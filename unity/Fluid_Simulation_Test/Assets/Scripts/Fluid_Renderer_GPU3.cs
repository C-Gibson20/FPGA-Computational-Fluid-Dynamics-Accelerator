using JetBrains.Annotations;
using System;
using Unity.Collections;
using UnityEngine;

public class FluidRendererGPU3 : MonoBehaviour
{
    // -- Fluid simulation data --
    [Header("Fluid Simulation Data")]
    [SerializeField] private ComputeShader fluidShadeCS;
    [SerializeField] private TextAsset fluidData;
    [SerializeField] private Material fluidMaterial;
    [SerializeField] private Texture2D colorRamp;
    [SerializeField] private float frameTime = 0.1f;

    // -- Streamline rendering --
    [Header("Streamline Rendering")]
    [SerializeField] private ComputeShader streamlineComputeShader;
    [SerializeField] private Material streamlineMaterial;
    [SerializeField, Min(1)] private int particleCount = 1000;
    [SerializeField] private float streamlineDt = 0.2f;
    [SerializeField, Min(1)] private int trailLength = 64;
    [SerializeField] private bool enableStreamlines = true;

    // -- Fluid simulation frames --
    private FluidCell[][,] frames;
    private int width, height;
    private MeshFilter meshFilter;
    private MeshRenderer meshRenderer;
    private Texture2D frameTexture;
    private RenderTexture velocityRT;
    private RenderTexture shadedRT;
    private NativeArray<Vector4> rawCellNativeArray;

    // -- Buffers for compute shaders --
    private ComputeBuffer rawCellsBuffer;
    private ComputeBuffer particleBuffer;
    private ComputeBuffer trailBuffer;
    private ComputeBuffer argsBuffer;
    private ComputeBuffer headIndexBuffer;

    // -- Compute shader kernels --
    private int streamlineKernel;
    private uint threadGroupSizeX;
    private int fluidKernel;

    // -- State for rendering --
    private float elapsedTime;
    private int currentFrame;
    private int nextFrame;

    // -- Shader property IDs --
    private static readonly int IdColorRamp = Shader.PropertyToID("_ColorRamp");
    private static readonly int IdMainTex = Shader.PropertyToID("_MainTex");
    private static readonly int IdDeltaTime = Shader.PropertyToID("_DeltaTime");
    private static readonly int IdParticles = Shader.PropertyToID("_ParticleCount");
    private static readonly int IdTrails = Shader.PropertyToID("_Trails");
    private static readonly int IdTrailLen = Shader.PropertyToID("_TrailLength");
    private static readonly int IdVelocityTex = Shader.PropertyToID("_VelocityTex");
    private static readonly int IdHeadIndices = Shader.PropertyToID("_HeadIndices");
    private static readonly int IdStreamColor = Shader.PropertyToID("_StreamColor");
    private static readonly int IdTexSize = Shader.PropertyToID("_TexSize");
    private static readonly int IdInvTexSize = Shader.PropertyToID("_InvTexSize");
    private static readonly int IdParticleBuffer = Shader.PropertyToID("_Particles");
    private static readonly int IdRawCellsBuffer = Shader.PropertyToID("_RawCells");
    private static readonly int IdVelocityRT = Shader.PropertyToID("_VelocityRT");
    private static readonly int IdShadedRT = Shader.PropertyToID("_ShadedRT");

    private void Awake()
    {
        meshFilter = GetComponent<MeshFilter>();
        meshRenderer = GetComponent<MeshRenderer>();
        InitializeFluid();
        if (enableStreamlines) InitializeStreamlines();
    }

    void Update()
    {
        if (frames == null || frames.Length == 0) return;

        AdvanceFrame();
        RenderColorMap();
        if (enableStreamlines) RenderStreamlines();
    }

    void OnDestroy()
    {
        particleBuffer?.Release();
        trailBuffer?.Release();
        argsBuffer?.Release();
        headIndexBuffer?.Release();
        rawCellsBuffer?.Release();
        if (velocityRT) Destroy(velocityRT);
        if (shadedRT) Destroy(shadedRT);
        if (frameTexture) Destroy(frameTexture);
        if (meshFilter.mesh) Destroy(meshFilter.mesh);
        if (meshRenderer.material) Destroy(meshRenderer.material);
        if (rawCellNativeArray.IsCreated) rawCellNativeArray.Dispose();
    }
    private void InitializeFluid()
    {
        // -- Load frames --
        frames = FluidDataLoader.LoadFromBinary(fluidData);
        if (frames == null || frames.Length == 0)
            throw new InvalidOperationException("Failed to load fluid data.");

        width = frames[0].GetLength(0);
        height = frames[0].GetLength(1);

        velocityRT = new RenderTexture(width, height, 0, RenderTextureFormat.RGFloat)
        {
            enableRandomWrite = true,
            filterMode = FilterMode.Point,
            wrapMode = TextureWrapMode.Repeat
        };
        velocityRT.Create();

        shadedRT = new RenderTexture(width, height, 0, RenderTextureFormat.ARGBHalf)
        {
            enableRandomWrite = true,
            filterMode = FilterMode.Point,
            wrapMode = TextureWrapMode.Repeat
        };
        shadedRT.Create();

        rawCellsBuffer = new ComputeBuffer(width * height, sizeof(float) * 4, ComputeBufferType.Structured);
        rawCellNativeArray = new NativeArray<Vector4>(width * height, Allocator.Persistent);

        fluidKernel = fluidShadeCS.FindKernel("FluidCompute");

        // -- Setup mesh --
        meshFilter.mesh = GenerateQuadMesh(width, height);
        transform.localScale = new Vector3(width, height, 1f);

        meshRenderer.material = new Material(fluidMaterial);
        meshRenderer.material.SetTexture(IdColorRamp, colorRamp);
        meshRenderer.material.SetTexture(IdMainTex, shadedRT);
    }

    private void InitializeStreamlines()
    {
        // -- Kernel setup --
        streamlineKernel = streamlineComputeShader.FindKernel("StreamlineCompute");
        streamlineComputeShader.GetKernelThreadGroupSizes(streamlineKernel, out threadGroupSizeX, out _, out _);

        // -- Allocate buffers --
        particleBuffer = new ComputeBuffer(particleCount, sizeof(float) * 2, ComputeBufferType.Default);
        trailBuffer = new ComputeBuffer(particleCount * trailLength, sizeof(float) * 2, ComputeBufferType.Default);
        argsBuffer = new ComputeBuffer(1, sizeof(uint) * 5, ComputeBufferType.IndirectArguments);
        headIndexBuffer = new ComputeBuffer(particleCount, sizeof(uint));

        // -- Initialise particle positions and trails --
        var pos = new Vector2[particleCount];
        for (int i = 0; i < particleCount; i++)
        {
            pos[i] = new Vector2(UnityEngine.Random.Range(0, width), UnityEngine.Random.Range(0, height));
        }
        particleBuffer.SetData(pos);

        var trails = new Vector2[particleCount * trailLength];
        for (int i = 0; i < particleCount; i++)
            for (int j = 0; j < trailLength; j++)
                trails[i * trailLength + j] = pos[i];
        trailBuffer.SetData(trails);

        // -- Indirect draw args: vertex count per instance (2 indices per line * (trailLength-1)), instance count --
        uint[] args = { (uint)((trailLength - 1) * 2), (uint)particleCount, 0, 0, 0};
        argsBuffer.SetData(args);

        // -- Initialize head indices to zero --
        headIndexBuffer.SetData(new uint[particleCount]);
    }

    private static Mesh GenerateQuadMesh(int w, int h)
    {
        // -- Create a quad mesh with vertices and UVs --
        var m = new Mesh();
        m.vertices = new Vector3[]{
            new Vector3(-0.5f,-0.5f,0), new Vector3(0.5f,-0.5f,0),
            new Vector3(-0.5f, 0.5f,0), new Vector3(0.5f, 0.5f,0)
        };
        m.uv = new Vector2[]{
            Vector2.zero, Vector2.right,
            Vector2.up,   Vector2.one
        };

        // -- Two triangles to form a quad --
        m.triangles = new[] { 0, 2, 1, 2, 3, 1 };
        m.RecalculateNormals();
        return m;
    }

    private void AdvanceFrame()
    {
        elapsedTime += Time.deltaTime;
        if (elapsedTime < frameTime) return;

        elapsedTime -= frameTime;
        currentFrame = nextFrame;
        nextFrame = (nextFrame + 1) % frames.Length;
    }

    private void RenderColorMap()
    {
        // -- Pack current frame into Buffer --
        var frame = frames[currentFrame];
        int index = 0;
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                var c = frame[x, y];
                rawCellNativeArray[index++] = new Vector4(c.velocity.x, c.velocity.y, c.density, 0);
            }
        }
        rawCellsBuffer.SetData(rawCellNativeArray);

        // -- Bind parameters --
        fluidShadeCS.SetVector(IdTexSize, new Vector2(width, height));
        fluidShadeCS.SetBuffer(fluidKernel, IdRawCellsBuffer, rawCellsBuffer);
        fluidShadeCS.SetTexture(fluidKernel, IdVelocityRT, velocityRT);
        fluidShadeCS.SetTexture(fluidKernel, IdShadedRT, shadedRT);

        // -- Dispatch compute shader --
        int tx = Mathf.CeilToInt(width / 16f);
        int ty = Mathf.CeilToInt(height / 16f);
        fluidShadeCS.Dispatch(fluidKernel, tx, ty, 1);
    }

    void RenderStreamlines()
    {
        // -- Bind parameters to compute shader --
        streamlineComputeShader.SetVector(IdTexSize, new Vector4(width, height, 0, 0));
        streamlineComputeShader.SetVector(IdInvTexSize, new Vector4(1f / width, 1f / height, 0, 0));
        streamlineComputeShader.SetFloat(IdDeltaTime, streamlineDt);
        streamlineComputeShader.SetInt(IdParticles, particleCount);
        streamlineComputeShader.SetInt(IdTrailLen, trailLength);
        streamlineComputeShader.SetBuffer(streamlineKernel, IdParticleBuffer, particleBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, IdTrails, trailBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, IdHeadIndices, headIndexBuffer);
        streamlineComputeShader.SetTexture(streamlineKernel, IdMainTex, shadedRT);
        streamlineComputeShader.SetTexture(streamlineKernel, IdVelocityTex, velocityRT);

        // -- Dispatch compute shader --
        int dispatchCount = Mathf.CeilToInt((float)particleCount / threadGroupSizeX);
        streamlineComputeShader.Dispatch(streamlineKernel, dispatchCount, 1, 1);

        // -- Bind data to material --
        streamlineMaterial.SetBuffer(IdTrails, trailBuffer);
        streamlineMaterial.SetBuffer(IdHeadIndices, headIndexBuffer);
        streamlineMaterial.SetVector(IdTexSize, new Vector4(width, height, 0, 0));
        streamlineMaterial.SetVector(IdInvTexSize, new Vector4(1f / width, 1f / height, 0, 0));
        streamlineMaterial.SetColor(IdStreamColor, Color.white);
        streamlineMaterial.SetInt(IdTrailLen, trailLength);
        streamlineMaterial.SetInt(IdParticles, particleCount);
        streamlineMaterial.enableInstancing = true;

        // -- Draw procedural lines --
        Graphics.DrawProceduralIndirect(
            streamlineMaterial,
            new Bounds(Vector3.zero, new Vector3(width, height, 1f)),
            MeshTopology.Lines,
            argsBuffer
        );
    }
}
