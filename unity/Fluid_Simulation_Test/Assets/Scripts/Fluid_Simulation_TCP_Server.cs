using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using UnityEngine;

public class ServerScript : MonoBehaviour
{
    // -- Server settings --
    [SerializeField] private string IP = "127.0.0.1";
    [SerializeField] private int port = 12345;

    [SerializeField] private TextAsset binaryFile;
    
    // -- Communication parameters --
    [SerializeField] private float sendInterval = 0.1f;

    // -- TCP --
    TcpListener server = null;
    TcpClient client = null;
    NetworkStream stream = null;
    Thread thread;
    private volatile bool isRunning = true;

    // -- Simulation --
    List<byte[]> framePayloads;
    [SerializeField] private int width = 100;
    [SerializeField] private int height = 100;

    private void Start()
    {
        framePayloads = ParseBinaryFrames(binaryFile.bytes);
        thread = new Thread(new ThreadStart(SetupServer));
        thread.Start();
    }

    private List<byte[]> ParseBinaryFrames(byte[] data)
    {
        var list = new List<byte[]>();
        //int frameBodySize = width * height * 6; 
        int frameBodySize = width * height * 8; 

        int offset = 0;
        while (offset + frameBodySize <= data.Length)
        {
            var payload = new byte[frameBodySize];
            Array.Copy(data, offset, payload, 0, frameBodySize);
            list.Add(payload);
            offset += frameBodySize;
        }

        return list;
    }

    private void SetupServer()
    {
        try
        {
            IPAddress localAddr = IPAddress.Parse(IP);
            server = new TcpListener(localAddr, port);
            server.Start();
            Debug.Log("Server started on " + IP + ":" + port);

            while (isRunning)
            {
                Debug.Log("Waiting for connection...");
                client = server.AcceptTcpClient();
                client.NoDelay = true;
                Debug.Log("Connected");

                stream = client.GetStream();
                int frameIndex = 0;

                while (client.Connected && isRunning)
                {
                    byte[] frame = framePayloads[frameIndex];
                    stream.Write(frame, 0, frame.Length); 
                    frameIndex = (frameIndex + 1) % framePayloads.Count;
                    Thread.Sleep((int)(sendInterval * 1000));
                }

                client.Close();
            }
        }
        catch (SocketException e)
        {
            Debug.Log("SocketException: " + e);
        }
        finally
        {
            server.Stop();
        }
    }

    void OnApplicationQuit()
    {
        Close();
    }


    public void Close()
    {
        isRunning = false;

        try
        {
            stream?.Close();
            client?.Close();
            server?.Stop();
        }
        catch (Exception e)
        {
            Debug.LogWarning("Server cleanup error: " + e.Message);
        }

        if (thread != null && thread.IsAlive)
        {
            try
            {
                thread.Join(1000); // prevent indefinite blocking
            }
            catch (Exception e)
            {
                Debug.LogWarning("Thread join failed: " + e.Message);
            }
        }

        thread = null;
        client = null;
        stream = null;
        server = null;
    }

}