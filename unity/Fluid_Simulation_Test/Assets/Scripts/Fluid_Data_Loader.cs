using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class FluidDataLoader
{
    public static FluidCell[][,] LoadFromBinary(TextAsset binData)
    {
        using var stream = new MemoryStream(binData.bytes); // Use MemoryStream to read from byte array
        using var reader = new BinaryReader(stream); // Use BinaryReader to read binary data

        int width = reader.ReadInt32();
        int height = reader.ReadInt32();

        int cellCount = width * height;
        int cellStride = 3 * sizeof(float); // ux, uy, rho

        long frameSize = cellCount * cellStride; // Size of one frame in bytes
        int frameCount = (binData.bytes.Length - 8) / (int)frameSize;
        Debug.Log("frameCount: " + frameCount);

        var frames = new FluidCell[frameCount][,];

        for (int f = 0; f < frameCount; f++)
        {
            var grid = new FluidCell[width, height];
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    float ux = reader.ReadSingle();
                    float uy = reader.ReadSingle();
                    float rho = reader.ReadSingle();
                    grid[x, y] = new FluidCell
                    {
                        velocity = new Vector2(ux, uy),
                        density = rho
                    };
                }
            }
            frames[f] = grid;
        }

        return frames;
    }
}
