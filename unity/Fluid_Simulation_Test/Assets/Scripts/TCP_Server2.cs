using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using UnityEngine;

public class ServerScript : MonoBehaviour
{
    TcpListener server = null;
    TcpClient client = null;
    NetworkStream stream = null;
    Thread thread;

    private void Start()
    {
        thread = new Thread(new ThreadStart(SetupServer));
        thread.Start();
        InvokeRepeating("SendRequest", 3f, 1f); // Call SendRequest every second
    }

    private void SetupServer()
    {
        try
        {
            IPAddress localAddr = IPAddress.Parse("127.0.0.1");
            server = new TcpListener(localAddr, 12345);
            server.Start();
            Debug.Log("Server started and listening on port 12345");

            byte[] buffer = new byte[1024];
            string data = null;

            while (true)
            {
                Debug.Log("Waiting for connection...");
                client = server.AcceptTcpClient();
                Debug.Log("Connected");

                data = null;
                stream = client.GetStream();

                int i;

                while ((i = stream.Read(buffer, 0, buffer.Length)) != 0)
                {
                    data = Encoding.UTF8.GetString(buffer, 0, i);
                    Debug.Log("Client Message Received: " + data);
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

    private void OnApplicationQuit()
    {
        stream.Close();
        client.Close();
        server.Stop();
        thread.Abort();
    }

    public void SendRequest()
    {   if (client != null && client.Connected && stream != null)
        {
            byte[] msg = Encoding.UTF8.GetBytes("R");
            stream.Write(msg, 0, msg.Length);
            Debug.Log("Sent request");
        }
        else
        {
            Debug.LogWarning("Client is not connected or stream is null.");
        }
    }
}