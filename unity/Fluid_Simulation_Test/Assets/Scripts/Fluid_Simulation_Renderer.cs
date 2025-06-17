using JetBrains.Annotations;
using System;
using Unity.Collections;
using UnityEngine;
using static TMPro.SpriteAssetUtilities.TexturePacker_JsonArray;

public class FluidSimulationRenderer : MonoBehaviour
{
    [Header("TCP Client")]
    [SerializeField] private TCPClient TCPClient;

    [Header("Fluid Simulation Rendering")]
    [SerializeField] private ComputeShader fluidComputeShader;
    [SerializeField] private Material fluidMaterial;
    [SerializeField] private int simulationWidth = 100;
    [SerializeField] private int simulationHeight = 100;

    [Header("Density Rendering")]
    [SerializeField] public Texture2D densityColorTexture;

    [Header("Streamline Rendering")]
    [SerializeField] private ComputeShader streamlineComputeShader;
    [SerializeField] private Material streamlineMaterial;

    [Header("Vorticity Rendering")]
    [SerializeField] private ComputeShader vorticityComputeShader;
    [SerializeField] public Texture2D vorticityColorTexture;

    [Header("Velocity Rendering")]
    [SerializeField] public Texture2D velocityMagnitudeColorTexture;

    [Header("Physical Bounds")]
    [SerializeField] float initialDensity = 1.0f;
    [SerializeField] float initialVelocity = 0.1f;

    // -- TCP client --
    private TCPClient.SimulationFrame fluidSimulationFrame;

    // -- Fluid data --
    private Vector2 textureDimensions;
    private Vector2 inverseTextureDimensions;
    public float minimumDensity;
    public float maximumDensity;
    public float inverseDensityRange;
    public float minimumVelocity;
    public float maximumVelocity;
    public float inverseVelocityRange;
    public float minimumVorticity;
    public float maximumVorticity;
    public float inverseVorticityRange;

    private MeshRenderer fluidMeshRenderer;
    private MeshFilter fluidMeshFilter;

    private ComputeBuffer fluidDataBuffer;
    private NativeArray<Vector4> fluidDataArray;

    public float densityOffset;
    public float inverseDensityRangeValue;
    public float velocityOffset;
    public float inverseVelocityRangeValue;
    public float vorticityOffset;
    public float inverseVorticityRangeValue;

    // -- Density rendering --
    private Material densityMaterialInstance;
    private RenderTexture densityTexture;

    // -- Streamline rendering --
    private RenderTexture velocityTexture;
    private ComputeBuffer streamlineParticlePositionsBuffer;
    private ComputeBuffer streamlineTailBuffer;
    private ComputeBuffer streamlineDrawArgumentsBuffer;
    private ComputeBuffer streamlineHeadIndexBuffer;
    private ComputeBuffer streamlineSpawnPositionBuffer;
    private ComputeBuffer streamlineLifetimeBuffer;
    private ComputeBuffer streamlineTailIndexBuffer;

    private Bounds streamlineDrawBounds;

    private float streamlineTimestep = 0.8f;
    private float streamlineMaximumLifetime = 400.0f;
    public int streamlineCount = 100;
    public int streamlineLength = 64;
    public bool renderStreamlines = true;

    // -- Vorticity rendering --
    private RenderTexture vorticityTexture;

    private float vorticityContourHalfWidth = 1.0f;
    public float vorticityContourLevel = 0.05f;
    public bool renderVorticity = false;

    // -- Velocity magnitude rendering --
    private RenderTexture velocityMagnitudeTexture;

    // -- Compute shader kernels --
    private int fluidKernel;
    private uint fluidKernelThreadGroupSizeX;
    private uint fluidKernelThreadGroupSizeY;
    private int fluidKernelDispatchCountX;
    private int fluidKernelDispatchCountY;

    private int streamlineKernel;
    private uint streamlineKernelThreadGroupSizeX;
    private int streamlineKernelDispatchCount;

    private int vorticityKernel;
    private uint vorticityKernelThreadGroupSizeX;
    private uint vorticityKernelThreadGroupSizeY;
    private int vorticityKernelDispatchCountX;
    private int vorticityKernelDispatchCountY;

    // -- Shader property IDs --
    private static readonly int DensityColorTextureID = Shader.PropertyToID("_DensityColorTexture");
    private static readonly int StreamlineTimestepID = Shader.PropertyToID("_StreamlineTimestep");
    private static readonly int StreamlineCountID = Shader.PropertyToID("_StreamlineParticleCount");
    private static readonly int StreamlineTailsID = Shader.PropertyToID("_StreamlineTails");
    private static readonly int StreamlineLengthID = Shader.PropertyToID("_StreamlineTailLength");
    private static readonly int StreamlineSpawnPositionID = Shader.PropertyToID("_StreamlineSpawnPositions");
    private static readonly int StreamlineLifetimeID = Shader.PropertyToID("_StreamlineLifetimes");
    private static readonly int StreamlineMaximumLifetimeID = Shader.PropertyToID("_StreamlineMaximumLifetime");
    private static readonly int StreamlineTailIndicesID = Shader.PropertyToID("_StreamlineTailIndices");
    private static readonly int VelocityTextureID = Shader.PropertyToID("_VelocityTexture");
    private static readonly int StreamlineHeadIndicesID = Shader.PropertyToID("_StreamlineHeadIndices");
    private static readonly int StreamlineColorID = Shader.PropertyToID("_StreamlineColor");
    private static readonly int TextureDimensionID = Shader.PropertyToID("_TextureDimensions");
    private static readonly int InverseTextureDimensionID = Shader.PropertyToID("_InverseTextureDimensions");
    private static readonly int StreamlineParticlePositionsID = Shader.PropertyToID("_StreamlineParticlePositions");
    private static readonly int FluidDataID = Shader.PropertyToID("_FluidData");
    private static readonly int DensityTextureID = Shader.PropertyToID("_DensityTexture");
    private static readonly int VorticityTextureID = Shader.PropertyToID("_VorticityTexture");
    public static readonly int VorticityContourLevelID = Shader.PropertyToID("_VorticityContourLevel");
    private static readonly int VorticityContourColorID = Shader.PropertyToID("_VorticityContourColor");
    private static readonly int VorticityContourHalfWidthID = Shader.PropertyToID("_VorticityContourHalfWidth");
    private static readonly int VorticityColorTextureID = Shader.PropertyToID("_VorticityColorTexture");
    private static readonly int VelocityMagnitudeColorTextureID = Shader.PropertyToID("_VelocityMagnitudeColorTexture");
    private static readonly int VelocityMagnitudeTextureID = Shader.PropertyToID("_VelocityMagnitudeTexture");

    public enum FluidRenderMode
    {
        Density,
        Vorticity,
        Velocity
    }

    private void Awake()
    {
        QualitySettings.vSyncCount = 1;
        Application.targetFrameRate = 120;

        InitializeFluidRender();
    }

    void Update()
    {
        if (TCPClient == null || TCPClient.noReceivedFrames) return;

        fluidSimulationFrame = TCPClient.RetrieveFrame();

        if (fluidSimulationFrame != null)
        {
            BufferFluidSimulationFrame(fluidSimulationFrame);

            ConfigureFluidComputeShader();

            fluidComputeShader.Dispatch(fluidKernel, fluidKernelDispatchCountX, fluidKernelDispatchCountY, 1);
        }

        ConfigureFluidMaterialShader();

        if (renderVorticity) VorticityRender();
        if (renderStreamlines) StreamlineRender();
    }

    private void OnDestroy()
    {
        ReleaseBuffer(ref fluidDataBuffer);
        ReleaseStreamlineRender();

        ReleaseTexture(ref velocityTexture);
        ReleaseTexture(ref densityTexture);
        ReleaseTexture(ref vorticityTexture);
        ReleaseTexture(ref velocityMagnitudeTexture);

        if (fluidMeshFilter.mesh) Destroy(fluidMeshFilter.mesh);

        if (fluidMeshRenderer.material) Destroy(fluidMeshRenderer.material);
        if (densityMaterialInstance != null) Destroy(densityMaterialInstance);

        if (fluidDataArray.IsCreated) fluidDataArray.Dispose();
        TCPClient?.Close();
    }

    private void InitializeFluidRender()
    {
        textureDimensions = new Vector2(simulationWidth, simulationHeight);
        inverseTextureDimensions = new Vector2(1f / simulationWidth, 1f / simulationHeight);

        InitializePhysicalBounds();

        fluidMeshFilter = GetComponent<MeshFilter>();
        fluidMeshFilter.mesh = GenerateQuadMesh();
        transform.localScale = new Vector3(simulationWidth, simulationHeight, 1f);
        fluidMeshRenderer = GetComponent<MeshRenderer>();
        fluidMeshRenderer.sharedMaterial = fluidMaterial;

        fluidKernel = fluidComputeShader.FindKernel("FluidCompute");
        fluidComputeShader.GetKernelThreadGroupSizes(fluidKernel, out fluidKernelThreadGroupSizeX, out fluidKernelThreadGroupSizeY, out _);
        fluidKernelDispatchCountX = Mathf.CeilToInt((float)simulationWidth / fluidKernelThreadGroupSizeX);
        fluidKernelDispatchCountY = Mathf.CeilToInt((float)simulationHeight / fluidKernelThreadGroupSizeY);

        fluidDataBuffer = new ComputeBuffer(simulationWidth * simulationHeight, sizeof(float) * 4, ComputeBufferType.Structured);
        fluidDataArray = new NativeArray<Vector4>(simulationWidth * simulationHeight, Allocator.Persistent);

        InitializeRenderTextures();

        ConfigureFluidMaterialShader();

        SetRender(FluidRenderMode.Density);
        
        if (renderStreamlines) InitializeStreamlineRender();
    }

    private void InitializePhysicalBounds()
    {
        float maximumMach = 0.3f;

        minimumDensity = initialDensity * (1 - maximumMach * maximumMach) * 0.98f;
        maximumDensity = initialDensity * (1 + maximumMach * maximumMach) * 1.02f;
        inverseDensityRange = 1 / (maximumDensity - minimumDensity);

        minimumVelocity = 0.0f;
        maximumVelocity = maximumMach * (1f / Mathf.Sqrt(3f)) * 1.02f;
        inverseVelocityRange = 1 / maximumVelocity;

        maximumVorticity = initialVelocity * 1.02f;
        inverseVorticityRange = 1 / (maximumVorticity * 2f);

        SetNormalisationValues(minimumDensity, inverseDensityRange, minimumVelocity, inverseVelocityRange, maximumVorticity, inverseVorticityRange);
    }

    private void InitializeRenderTextures()
    {
        velocityTexture = new RenderTexture(simulationWidth, simulationHeight, 0, RenderTextureFormat.RGFloat)
        {
            enableRandomWrite = true,
            filterMode = FilterMode.Point,
            wrapMode = TextureWrapMode.Repeat
        };
        velocityTexture.Create();

        densityTexture = new RenderTexture(simulationWidth, simulationHeight, 0, RenderTextureFormat.ARGBHalf)
        {
            enableRandomWrite = true,
            filterMode = FilterMode.Point,
            wrapMode = TextureWrapMode.Repeat
        };
        densityTexture.Create();

        vorticityTexture = new RenderTexture(simulationWidth, simulationHeight, 0, RenderTextureFormat.RFloat)
        {
            enableRandomWrite = true,
            filterMode = FilterMode.Bilinear,
            wrapMode = TextureWrapMode.Clamp
        };
        vorticityTexture.Create();

        velocityMagnitudeTexture = new RenderTexture(simulationWidth, simulationHeight, 0, RenderTextureFormat.RFloat)
        {
            enableRandomWrite = true,
            filterMode = FilterMode.Point,
            wrapMode = TextureWrapMode.Clamp
        };
        velocityMagnitudeTexture.Create();
    }

    public void SetRender(FluidRenderMode renderMode)
    {
        fluidMaterial.DisableKeyword("RENDER_DENSITY");
        fluidMaterial.DisableKeyword("RENDER_VORTICITY");
        fluidMaterial.DisableKeyword("RENDER_VELOCITY");

        switch (renderMode)
        {
            case FluidRenderMode.Density:
                fluidMaterial.EnableKeyword("RENDER_DENSITY");
                break;
            case FluidRenderMode.Vorticity:
                fluidMaterial.EnableKeyword("RENDER_VORTICITY");
                break;
            case FluidRenderMode.Velocity:
                fluidMaterial.EnableKeyword("RENDER_VELOCITY");
                break;
        }
    }

    public void InitializeStreamlineRender()
    {
        ReleaseStreamlineRender();

        streamlineKernel = streamlineComputeShader.FindKernel("StreamlineCompute");
        streamlineComputeShader.GetKernelThreadGroupSizes(streamlineKernel, out streamlineKernelThreadGroupSizeX, out _, out _);
        streamlineKernelDispatchCount = Mathf.CeilToInt((float)streamlineCount / streamlineKernelThreadGroupSizeX);

        streamlineDrawBounds = new Bounds(Vector3.zero, new Vector3(simulationWidth, simulationHeight, 1f));

        // -- Buffer Allocation --
        streamlineParticlePositionsBuffer = new ComputeBuffer(streamlineCount, sizeof(float) * 2, ComputeBufferType.Default);
        streamlineTailBuffer = new ComputeBuffer(streamlineCount * streamlineLength, sizeof(float) * 2, ComputeBufferType.Default);
        streamlineDrawArgumentsBuffer = new ComputeBuffer(1, sizeof(uint) * 5, ComputeBufferType.IndirectArguments);
        streamlineHeadIndexBuffer = new ComputeBuffer(streamlineCount, sizeof(uint), ComputeBufferType.Default);
        streamlineSpawnPositionBuffer = new ComputeBuffer(streamlineCount, sizeof(float) * 2, ComputeBufferType.Default);
        streamlineLifetimeBuffer = new ComputeBuffer(streamlineCount, sizeof(float), ComputeBufferType.Default);
        streamlineTailIndexBuffer = new ComputeBuffer(streamlineCount, sizeof(uint), ComputeBufferType.Default);

        var streamlineSpawnPositions = GenerateStreamlineSpawnPositions(streamlineCount);

        var streamlineTails = new Vector2[streamlineCount * streamlineLength];

        var streamlineLifetimes = new float[streamlineCount];

        for (int i = 0; i < streamlineCount * streamlineLength; i++)
        {
            int spawnPositionIdx = i / streamlineLength;

            streamlineTails[i] = streamlineSpawnPositions[spawnPositionIdx];

            if (i < streamlineCount)
            {
                streamlineLifetimes[i] = UnityEngine.Random.Range(0f, streamlineMaximumLifetime * 0.5f);
            }
        }

        uint[] streamlineDrawArguments = { (uint)((streamlineLength - 1) * 2), (uint)streamlineCount, 0, 0, 0 };

        streamlineParticlePositionsBuffer.SetData(streamlineSpawnPositions);
        streamlineTailBuffer.SetData(streamlineTails);
        streamlineDrawArgumentsBuffer.SetData(streamlineDrawArguments);
        streamlineHeadIndexBuffer.SetData(new uint[streamlineCount]);
        streamlineSpawnPositionBuffer.SetData(streamlineSpawnPositions);
        streamlineLifetimeBuffer.SetData(streamlineLifetimes);
        streamlineTailIndexBuffer.SetData(new uint[streamlineCount]);
    }

    public void InitializeVorticityRender()
    {
        vorticityKernel = vorticityComputeShader.FindKernel("VorticityCompute");
        vorticityComputeShader.GetKernelThreadGroupSizes(vorticityKernel, out vorticityKernelThreadGroupSizeX, out vorticityKernelThreadGroupSizeY, out _);
        vorticityKernelDispatchCountX = Mathf.CeilToInt((float)simulationWidth / vorticityKernelThreadGroupSizeX);
        vorticityKernelDispatchCountY = Mathf.CeilToInt((float)simulationHeight / vorticityKernelThreadGroupSizeY);
    }

    private Vector2[] GenerateStreamlineSpawnPositions(int streamlineParticleCount)
    {
        Vector2[] spawnPositions = new Vector2[streamlineParticleCount];

        int streamlineParticleCountX = Mathf.CeilToInt(Mathf.Sqrt(streamlineParticleCount * simulationWidth / (float)simulationHeight));
        int streamlineParticleCountY = Mathf.CeilToInt(streamlineParticleCount / (float)streamlineParticleCountX);

        float particleSpacingX = simulationWidth / (float)streamlineParticleCountX;
        float particleSpacingY = simulationHeight / (float)streamlineParticleCountY;

        int particleIdx = 0;

        for (int y = 0; y < streamlineParticleCountY; y++)
        {
            for (int x = 0; x < streamlineParticleCountX; x++)
            {
                if (particleIdx >= streamlineParticleCount) return spawnPositions;

                spawnPositions[particleIdx++] = new Vector2(
                    (x + 0.5f) * particleSpacingX,
                    (y + 0.5f) * particleSpacingY
                );
            }
        }

        return spawnPositions;
    }

    private static Mesh GenerateQuadMesh()
    {
        var DensityRenderMesh = new Mesh();

        DensityRenderMesh.vertices = new Vector3[]{
            new Vector3(-0.5f,-0.5f,0),
            new Vector3(0.5f,-0.5f,0),
            new Vector3(-0.5f, 0.5f,0),
            new Vector3(0.5f, 0.5f,0)
        };

        DensityRenderMesh.uv = new Vector2[]{
            Vector2.zero,
            Vector2.right,
            Vector2.up,
            Vector2.one
        };

        DensityRenderMesh.triangles = new[] { 0, 2, 1, 2, 3, 1 };

        DensityRenderMesh.RecalculateNormals();

        return DensityRenderMesh;
    }

    private void BufferFluidSimulationFrame(TCPClient.SimulationFrame frame)
    {
        var fluidGrid = frame.parsedFluidGrid;
        int fluidCellIdx = 0;

        for (int i = 0; i < simulationWidth * simulationHeight; i++)
        {
            var fluidCell = fluidGrid[i];

            fluidDataArray[fluidCellIdx++] = new Vector4(fluidCell.velocity.x, fluidCell.velocity.y, fluidCell.velocitySquared, fluidCell.density);
        }
        fluidDataBuffer.SetData(fluidDataArray);
    }

    private void ConfigureFluidComputeShader()
    {
        fluidComputeShader.SetVector(TextureDimensionID, textureDimensions);
        fluidComputeShader.SetBuffer(fluidKernel, FluidDataID, fluidDataBuffer);
        fluidComputeShader.SetTexture(fluidKernel, VelocityTextureID, velocityTexture);
        fluidComputeShader.SetTexture(fluidKernel, DensityTextureID, densityTexture);
        fluidComputeShader.SetTexture(fluidKernel, VelocityMagnitudeTextureID, velocityMagnitudeTexture);
    }

    public void ConfigureFluidMaterialShader()
    {
        fluidMaterial.SetTexture(DensityColorTextureID, densityColorTexture);
        fluidMaterial.SetTexture(VorticityColorTextureID, vorticityColorTexture);
        fluidMaterial.SetTexture(DensityTextureID, densityTexture);
        fluidMaterial.SetTexture(VorticityTextureID, vorticityTexture);
        fluidMaterial.SetFloat(VorticityContourLevelID, vorticityContourLevel);
        fluidMaterial.SetFloat(VorticityContourHalfWidthID, vorticityContourHalfWidth);
        fluidMaterial.SetColor(VorticityContourColorID, Color.white);
        fluidMaterial.SetTexture(VelocityMagnitudeTextureID, velocityMagnitudeTexture);
        fluidMaterial.SetTexture(VelocityMagnitudeColorTextureID, velocityMagnitudeColorTexture);

        fluidMaterial.SetFloat("_DensityOffset", densityOffset);
        fluidMaterial.SetFloat("_InverseDensityRange", inverseDensityRangeValue);
        fluidMaterial.SetFloat("_VelocityOffset", velocityOffset);
        fluidMaterial.SetFloat("_InverseVelocityRange", inverseVelocityRangeValue);
        fluidMaterial.SetFloat("_VorticityOffset", vorticityOffset);
        fluidMaterial.SetFloat("_InverseVorticityRange", inverseVorticityRangeValue);

        fluidMaterial.enableInstancing = true;
    }
    
    void StreamlineRender()
    {
        ConfigureStreamlineComputeShader();

        streamlineComputeShader.Dispatch(streamlineKernel, streamlineKernelDispatchCount, 1, 1);

        ConfigureStreamlineMaterialShader();

        Graphics.DrawProceduralIndirect(
            streamlineMaterial,
            streamlineDrawBounds,
            MeshTopology.Lines,
            streamlineDrawArgumentsBuffer
        );
    }

    private void ConfigureStreamlineComputeShader()
    {
        streamlineComputeShader.SetVector(TextureDimensionID, textureDimensions);
        streamlineComputeShader.SetVector(InverseTextureDimensionID, inverseTextureDimensions);
        streamlineComputeShader.SetFloat(StreamlineTimestepID, streamlineTimestep);
        streamlineComputeShader.SetFloat(StreamlineMaximumLifetimeID, streamlineMaximumLifetime);
        streamlineComputeShader.SetInt(StreamlineCountID, streamlineCount);
        streamlineComputeShader.SetInt(StreamlineLengthID, streamlineLength);
        streamlineComputeShader.SetBuffer(streamlineKernel, StreamlineParticlePositionsID, streamlineParticlePositionsBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, StreamlineTailsID, streamlineTailBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, StreamlineHeadIndicesID, streamlineHeadIndexBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, StreamlineSpawnPositionID, streamlineSpawnPositionBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, StreamlineLifetimeID, streamlineLifetimeBuffer);
        streamlineComputeShader.SetBuffer(streamlineKernel, StreamlineTailIndicesID, streamlineTailIndexBuffer);
        streamlineComputeShader.SetTexture(streamlineKernel, DensityTextureID, densityTexture);
        streamlineComputeShader.SetTexture(streamlineKernel, VelocityTextureID, velocityTexture);
    }

    private void ConfigureStreamlineMaterialShader()
    {
        streamlineMaterial.SetBuffer(StreamlineTailsID, streamlineTailBuffer);
        streamlineMaterial.SetBuffer(StreamlineHeadIndicesID, streamlineHeadIndexBuffer);
        streamlineMaterial.SetBuffer(StreamlineTailIndicesID, streamlineTailIndexBuffer);
        streamlineMaterial.SetBuffer(StreamlineLifetimeID, streamlineLifetimeBuffer);
        streamlineMaterial.SetVector(TextureDimensionID, textureDimensions);
        streamlineMaterial.SetVector(InverseTextureDimensionID, inverseTextureDimensions);
        streamlineMaterial.SetColor(StreamlineColorID, Color.white);
        streamlineMaterial.SetInt(StreamlineLengthID, streamlineLength);
        streamlineMaterial.SetFloat(StreamlineMaximumLifetimeID, streamlineMaximumLifetime);
        streamlineMaterial.enableInstancing = true;
    }

    private void VorticityRender()
    {
        ConfigureVorticityComputeShader();

        vorticityComputeShader.Dispatch(vorticityKernel, vorticityKernelDispatchCountX, vorticityKernelDispatchCountY, 1);
    }

    private void ConfigureVorticityComputeShader()
    {
        vorticityComputeShader.SetVector(TextureDimensionID, textureDimensions);
        vorticityComputeShader.SetVector(InverseTextureDimensionID, inverseTextureDimensions);
        vorticityComputeShader.SetTexture(vorticityKernel, VelocityTextureID, velocityTexture);
        vorticityComputeShader.SetTexture(vorticityKernel, DensityTextureID, densityTexture);
        vorticityComputeShader.SetTexture(vorticityKernel, VorticityTextureID, vorticityTexture);
    }

    public void ReleaseStreamlineRender()
    {
        ReleaseBuffer(ref streamlineParticlePositionsBuffer);
        ReleaseBuffer(ref streamlineTailBuffer);
        ReleaseBuffer(ref streamlineDrawArgumentsBuffer);
        ReleaseBuffer(ref streamlineHeadIndexBuffer);
        ReleaseBuffer(ref streamlineSpawnPositionBuffer);
        ReleaseBuffer(ref streamlineLifetimeBuffer);
        ReleaseBuffer(ref streamlineTailIndexBuffer);
    }

    private void ReleaseBuffer(ref ComputeBuffer buffer)
    {
        if (buffer != null)
        {
            buffer.Release();
            buffer = null;
        }
    }

    private void ReleaseTexture(ref RenderTexture texture)
    {
        if (texture != null)
        {
            texture.Release();
            Destroy(texture);
            texture = null;
        }
    }

    public float[] SampleTexelData (Vector2 mouseTexel)
    {
        int x = Math.Clamp((int)(mouseTexel.x * simulationWidth), 0, simulationWidth - 1);
        int y = Math.Clamp((int)(mouseTexel.y * simulationHeight), 0, simulationHeight - 1);
        var fluidCellData = fluidDataArray[y * simulationWidth + x];
        return new float[] { fluidCellData.w, fluidCellData.x, fluidCellData.y, (float)Math.Sqrt(fluidCellData.z) }; 
    }

    public void SetNormalisationValues(float newDensityOffset, float newInverseDensityRangeValue, float newVelocityOffset, float newInverseVelocityRangeValue, float newVorticityOffset, float newInverseVorticityRangeValue)
    {
        densityOffset = newDensityOffset;
        inverseDensityRangeValue = newInverseDensityRangeValue;
        velocityOffset = newVelocityOffset;
        inverseVelocityRangeValue = newInverseVelocityRangeValue;
        vorticityOffset = newVorticityOffset;
        inverseVorticityRangeValue = newInverseVorticityRangeValue;
        ConfigureFluidMaterialShader();
    }
}
