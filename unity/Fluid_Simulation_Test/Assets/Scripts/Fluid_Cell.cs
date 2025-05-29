using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// One cell in the fluid simulation grid.
/// Contains velocity and density.
/// </summary>
public struct FluidCell
{
    public Vector2 velocity;  // u.x and u.y
    public float density;     // rho
}

