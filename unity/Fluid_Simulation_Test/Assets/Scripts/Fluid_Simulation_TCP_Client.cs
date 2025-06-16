using System;
using System.Buffers;
using System.Collections;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;


public class TCPClient : MonoBehaviour
{
    // -- Server settings --
    public string serverIP = "127.0.0.1";
    public int serverPort = 12345;

    // -- Simulation settings -- 
    [SerializeField] public int simulationWidth = 100;
    [SerializeField] public int simulationHeight = 100;
    public static int bytesPerCell = 8;
    private static int simulationFrameSize;

    // -- TCP connection --
    private TcpClient tcpClient;

    private NetworkStream networkStream;

    private Thread clientReceiveThread;

    // -- TCP state --
    private volatile bool isTcpRunning = false;
    public bool noReceivedFrames = true;

    // -- Buffer --
    private const int bufferSize = 3;

    private SimulationFrame[] simulationFrames;

    private int latestFrameIndex = -1;
    private int count = 0;

    // -- Utility --
    private const float fixedPointScale = 1f / 8192f;

    public struct FluidCell
    {
        public Vector2 velocity;
        public float velocitySquared;
        public float density;
    };

    public class SimulationFrame
    {
        public byte[] rawSimulationData;
        public volatile bool isFrameReady;
        public FluidCell[] parsedFluidGrid;
    }

    private void InitializeFrameBuffer()
    {
        simulationFrames = new SimulationFrame[bufferSize];

        for (int i = 0; i < bufferSize; i++)
        {
            simulationFrames[i] = new SimulationFrame
            {
                rawSimulationData = new byte[simulationFrameSize],
                parsedFluidGrid = new FluidCell[simulationWidth * simulationHeight],
                isFrameReady = false
            };
        }
    }

    IEnumerator Start()
    {
        yield return new WaitForSeconds(1f);

        simulationFrameSize = simulationWidth * simulationHeight * (bytesPerCell);// + 2);

        InitializeFrameBuffer();

        ConnectToServer();
    }

    void OnApplicationQuit()
    {
        Close();
    }

    public SimulationFrame RetrieveFrame()
    {
        int frameIdx = Volatile.Read(ref latestFrameIndex);
        
        if (frameIdx < 0 || frameIdx >= bufferSize) return null;

        var frame = simulationFrames[frameIdx];

        if (!frame.isFrameReady) return null;

        frame.isFrameReady = false; 

        return frame;
    }

    private void ConnectToServer()
    {
        try
        {
            tcpClient = new TcpClient(serverIP, serverPort);
            networkStream = tcpClient.GetStream();
            isTcpRunning = true;
            Debug.Log("Connected to server.");

            _ = ReceiveFrameBytesAsync();
        }
        catch (SocketException exception)
        {
            Debug.LogError("SocketException: " + exception);
        }
    }

    private async Task ReceiveFrameBytesAsync()
    {
        var byteBuffer = ArrayPool<byte>.Shared.Rent(simulationFrameSize);
        int byteOffset = 0;

        try
        {
            while (isTcpRunning && tcpClient.Connected)
            {
                int n = await networkStream.ReadAsync(byteBuffer, byteOffset, simulationFrameSize - byteOffset);

                if (n == 0)
                {
                    isTcpRunning = false;
                    break;
                }

                byteOffset += n;
                if (byteOffset < simulationFrameSize) continue;

                byteOffset = 0;
                OnFrameReceived(byteBuffer);
            }
        }
        catch (Exception exception)
        {
            Debug.LogError($"TCP receive error: {exception.Message}");
            isTcpRunning = false;
        }
        finally
        {
            ArrayPool<byte>.Shared.Return(byteBuffer);
        }
    }

    private void OnFrameReceived(byte[] newFrameData)
    {
        if (noReceivedFrames) noReceivedFrames = false;

        int nextIndex = (latestFrameIndex + 1) % bufferSize;
        var frame = simulationFrames[nextIndex];

        frame.isFrameReady = false;

        Buffer.BlockCopy(newFrameData, 0, frame.rawSimulationData, 0, simulationFrameSize);
        
        ProcessRawFrameData(frame.rawSimulationData, frame.parsedFluidGrid);

        frame.isFrameReady = true;

        Volatile.Write(ref latestFrameIndex, nextIndex);
    }


    private void ProcessRawFrameData(byte[] newFrameData, FluidCell[] fluidGrid)
    {
        Span<short> frameData = MemoryMarshal.Cast<byte, short>(newFrameData);

        int byteIdx = 0;

        for (int i = 0; i < simulationWidth * simulationHeight; i++)
        {
            short rawRho = frameData[byteIdx++];
            short rawvelocitySquared = frameData[byteIdx++];
            short rawVelocityX = frameData[byteIdx++];
            short rawVelocityY = frameData[byteIdx++];

            fluidGrid[i].density = rawRho * fixedPointScale;
            fluidGrid[i].velocitySquared = rawvelocitySquared * fixedPointScale;
            fluidGrid[i].velocity.x = rawVelocityX * fixedPointScale;
            fluidGrid[i].velocity.y = rawVelocityY * fixedPointScale;
        }
        count += 1;
    }

    public void Close()
    {
        isTcpRunning = false;

        if (clientReceiveThread != null && clientReceiveThread.IsAlive)
        {
            try
            {
                clientReceiveThread.Join(1000);
            }
            catch (Exception exception)
            {
                Debug.LogWarning("Thread join failed: " + exception.Message);
            }
        }

        networkStream?.Close();
        tcpClient?.Close();

        clientReceiveThread = null;
        networkStream = null;
        tcpClient = null;
    }
}