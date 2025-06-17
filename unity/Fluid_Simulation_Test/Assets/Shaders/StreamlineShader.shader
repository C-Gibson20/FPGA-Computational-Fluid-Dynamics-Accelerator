Shader "Custom/StreamlineShader"
{
    Properties { 
        _StreamlineColor ("Streamline Color", Color) = (1,1,1,1)
        _TextureDimensions ("Texture Dimensions", Vector) = (256,256,0,0)
        _InverseTextureDimensions ("Inverse Texture Dimensions", Vector) = (0.0039,0.0039,0,0)
        _StreamlineTailLength ("Streamline Trail Length", Int) = 64
        _StreamlineMaximumLifetime ("Streamline Maximum Lifetime", Float) = 400.0
    }
    SubShader {
        Tags { "Queue"="Transparent+1" "RenderType"="Transparent" }
        Blend SrcAlpha OneMinusSrcAlpha
        ZWrite Off
        ZTest Always
        Cull Off

        Pass {
            HLSLPROGRAM
            #pragma fragment StreamlineFragmentShader
            #pragma vertex StreamlineVertexShader
            #pragma target 5.0
            #include "UnityCG.cginc" 

            StructuredBuffer<float2> _StreamlineTails;  
            StructuredBuffer<uint> _StreamlineHeadIndices;
            StructuredBuffer<uint> _StreamlineTailIndices;
            StructuredBuffer<float> _StreamlineLifetimes;

            cbuffer StreamlineShaderParameters
            {
                float4 _StreamlineColor;
                float2 _InverseTextureDimensions;  
                float2 _TextureDimensions;  
                uint _StreamlineTailLength;
                float _StreamlineMaximumLifetime;
            }

            struct StreamlineVertexInput
            {
                uint vertexID : SV_VertexID;
                uint instanceID : SV_InstanceID;
            };

            struct StreamlineFragmentInput
            {
                float4 position : SV_POSITION;
                float4 colour : COLOR;
            };

            StreamlineFragmentInput StreamlineVertexShader(StreamlineVertexInput IN)
            {
                StreamlineFragmentInput OUT;
                OUT.position = float4(0,0,0,0);
                OUT.colour   = float4(0,0,0,0);

                // -- Compute segment index and vertex offset --
                uint segmentIdx = IN.vertexID >> 1;
                uint segmentVertexOffset = IN.vertexID & 1;
                uint tailStartIdx = IN.instanceID * _StreamlineTailLength;

                // -- Compute circular‐buffer index --
                uint streamlineHeadIdx = _StreamlineHeadIndices[IN.instanceID];
                streamlineHeadIdx = (streamlineHeadIdx == 0) ? (_StreamlineTailLength - 1) : (streamlineHeadIdx - 1); 
                uint tailVertexIdx = (streamlineHeadIdx - segmentIdx - segmentVertexOffset + _StreamlineTailLength) & (_StreamlineTailLength - 1);
                
                // -- Fetch first point in segment --
                float2 firstPosition = _StreamlineTails[tailStartIdx + tailVertexIdx];

                uint tail = _StreamlineTailIndices[IN.instanceID];
                uint validCount = (streamlineHeadIdx + _StreamlineTailLength - tail) & (_StreamlineTailLength - 1);
                if (segmentIdx >= validCount)
                {
                    OUT.colour.a = 0;
                    return OUT;
                }

                // -- Fetch second point in segment --
                int secondSegmentOffset = (segmentVertexOffset == 0) ? -1 : 1;
                uint secondTailVertexIdx = (tailVertexIdx + secondSegmentOffset + _StreamlineTailLength) & (_StreamlineTailLength - 1);
                float2 secondPosition = _StreamlineTails[tailStartIdx + secondTailVertexIdx];


                // -- Handle wrapped segments -- 
                float2 positionDelta = abs(firstPosition - secondPosition);
                bool wrapDetected = (positionDelta.x > 0.5 * _TextureDimensions.x) || (positionDelta.y > 0.5 * _TextureDimensions.y); 

                if (wrapDetected)
                {
                    OUT.colour.a = 0;
                    return OUT;
                }

                // -- Map into world-space --
                float3 worldPosition = float3((firstPosition * _InverseTextureDimensions - 0.5) * _TextureDimensions, 0);
                OUT.position = UnityObjectToClipPos(float4(worldPosition, 1));

                // -- Fade by trail segment -- 
                float trailFade = 1.0 - (float(segmentIdx) / (_StreamlineTailLength - 1)); 

                // -- Fade by lifetime --
                float particleLifetime = _StreamlineLifetimes[IN.instanceID];
                float fadeTime = _StreamlineMaximumLifetime / 5; 
                float fadeInAlpha = (particleLifetime <= fadeTime) ? saturate(particleLifetime / fadeTime) : 1.0;
                float fadeOutAlpha =  (_StreamlineMaximumLifetime - particleLifetime <= fadeTime) ? saturate((_StreamlineMaximumLifetime - particleLifetime) / fadeTime) : 1.0;
                float lifetimeFade = min(fadeInAlpha, fadeOutAlpha);
                
                // -- Appling color --
                OUT.colour = _StreamlineColor;
                OUT.colour.a *= trailFade * lifetimeFade;

                return OUT;
            }

            float4 StreamlineFragmentShader(StreamlineFragmentInput IN) : SV_Target
            {
                // -- Remove wrapped segment --
                clip(IN.colour.a - 0.001); 

                // -- Output color --
                return IN.colour;
            }

            ENDHLSL
        }
    }
}