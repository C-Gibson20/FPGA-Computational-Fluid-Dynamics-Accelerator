// StreamlineParticle.shader (URP or Standard)
Shader "Custom/StreamlineParticle"
{
    Properties { 
        _StreamColor ("Streamline Color", Color) = (1,1,1,1)
        _TexSize ("Simulation Texture Size (w,h)", Vector) = (256,256,0,0)
        _InvTexSize ("Inverse Texture Size", Vector) = (0.0039,0.0039,0,0)
    }
    SubShader {
        Tags { "Queue"="Transparent" "RenderType"="Transparent" }
        ZWrite Off
        Blend SrcAlpha OneMinusSrcAlpha
        Cull Off

        Pass {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma target 5.0

            #include "UnityCG.cginc" 

            StructuredBuffer<float2> _Trails;
            StructuredBuffer<uint> _HeadIndices;

            cbuffer StreamlineParams
            {
                float4 _StreamColor;
                float2 _TexSize;       
                float2 _InvTexSize;    
                uint _TrailLength;
                uint _ParticleCount;
            }

            struct Attributes
            {
                uint vertexID   : SV_VertexID;
                uint instanceID : SV_InstanceID;
            };

            struct Vars
            {
                float4 pos : SV_POSITION;
                float4 col : COLOR;
            };

            Vars vert(Attributes IN)
            {
                Vars OUT;

                // Each line segment is two verts → seg = vertexID/2, pt = vertexID%2
                uint seg = IN.vertexID >> 1;
                uint pt  = IN.vertexID & 1;

                // -- Compute circular‐buffer index --
                uint head = _HeadIndices[IN.instanceID];
                head = (head == 0) ? (_TrailLength - 1) : (head - 1); // head points to most recent
                uint idx = (head - seg - pt + _TrailLength) % _TrailLength;


                // -- Fetch point --
                uint baseIdx = IN.instanceID * _TrailLength;
                float2 simPos    = _Trails[baseIdx + idx];

                // -- Find other point in the segment --
                int neighborPt   = (pt == 0) ? 1 : 0;
                int neighborSegOffset = (pt == 0) ? -1 : +1;
                uint otherIdx = (idx + neighborSegOffset + _TrailLength) % _TrailLength;
                float2 simPosO   = _Trails[baseIdx + otherIdx];

                // -- Deretmine wrapping -- 
                float2 delta    = abs(simPos - simPosO);
                bool   didWrap  = (delta.x > 0.5 * _TexSize.x) || (delta.y > 0.5 * _TexSize.y); // Wrap if two points are more than half the domain

                // -- Map into world‐space --
                float2 uv       = simPos * _InvTexSize - 0.5;
                float3 worldPos = float3(uv * _TexSize, 0);
                OUT.pos         = UnityObjectToClipPos(float4(worldPos, 1));

                // -- Appling color --
                float age       = float(IN.vertexID >> 1) / (_TrailLength - 1);
                OUT.col         = _StreamColor;
                OUT.col.a      *= 1.0 - age;     // fade by age
                if (didWrap)
                    OUT.col.a = 0;      // hide wrap‐arounds

                return OUT;
            }

            float4 frag(Vars IN) : SV_Target
            {
                clip(IN.col.a - 0.001); // kill wrapped segments
                return IN.col;
            }

            ENDHLSL
        }
    }
}