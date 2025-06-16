Shader "Custom/FluidShader"
{
    Properties
    {
        _DensityTexture ("Density Texture", 2D) = "white" {}
        _DensityColorTexture ("Density Color Texture", 2D) = "white" {}
        
        _VorticityTexture ("Vorticity Texture", 2D) = "white" {}
        _VorticityColorTexture ("Vorticity Color Texture", 2D) = "white" {}

        _VorticityContourLevel ("Contour Vorticity Level", Float) = 0.05
        _VorticityContourHalfWidth("Half-Width", Float) = 0.5
        _VorticityContourColor ("Contour Color", Color) = (1,1,1,1)

        _VelocityMagnitudeTexture("Velocity Magnitude Texture", 2D) = "white" {}
        _VelocityMagnitudeColorTexture("Velocity Magnitude Color Texture", 2D) = "white" {}

        _DensityOffset ("Density Offset", Float) = 0.97
        _InverseDensityRange ("Inverse Density Range", Float) = 16.6

        _VelocityOffset ("Velocity Offset", Float) = 0.0
        _InverseVelocityRange ("Inverse Velocity Range", Float) = 5.8

        _VorticityOffset ("Vorticity Offset", Float) = 0.1
        _InverseVorticityRange ("Inverse Vorticity Range", Float) = 5
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        Pass
        {
            CGPROGRAM
            #pragma vertex FluidVertexShader
            #pragma fragment FluidFragmentShader
            #pragma multi_compile _ RENDER_VORTICITY RENDER_DENSITY RENDER_VELOCITY
            #pragma target 5.0

            sampler2D _DensityTexture; 
            sampler2D _VorticityTexture;
            sampler2D _DensityColorTexture;
            sampler2D _VorticityColorTexture;
            sampler2D _VelocityMagnitudeTexture;
            sampler2D _VelocityMagnitudeColorTexture;

            cbuffer FluidShaderParameters
            {
                float _VorticityContourLevel;
                float _VorticityContourHalfWidth;
                float4 _VorticityContourColor;
                float _DensityOffset;
                float _InverseDensityRange;
                float _VelocityOffset;
                float _InverseVelocityRange;
                float _VorticityOffset;
                float _InverseVorticityRange;
            }

            struct VertexInputs {
                float4 vertexPosition : POSITION;
                float2 texelCoord : TEXCOORD0;
            };

            struct FragmentInputs {
                float4 vertexPosition : SV_POSITION;
                float2 texelCoord : TEXCOORD0;
            };

            FragmentInputs FluidVertexShader(VertexInputs IN)
            {
                FragmentInputs OUT;
                OUT.vertexPosition = UnityObjectToClipPos(IN.vertexPosition);
                OUT.texelCoord = IN.texelCoord;
                return OUT;
            }

            fixed4 FluidFragmentShader(FragmentInputs IN) : SV_Target
            {
                float normalisedDensity;
                float normalizedVorticity;

                float density = tex2D(_DensityTexture, IN.texelCoord).r;
                if (density == 0) return float4(0, 0, 0, 1);

                #ifdef RENDER_VORTICITY

                    float vorticity = tex2D(_VorticityTexture, IN.texelCoord).r;
                    
                    normalizedVorticity = saturate((vorticity + _VorticityOffset) * _InverseVorticityRange);

                    float4 vorticityColour = tex2D(_VorticityColorTexture, float2(normalizedVorticity, 0.5));

                    float vorticityMagnitude = abs(vorticity);
                    
                    float vorticityDx = ddx(vorticityMagnitude);
                    float vorticityDy = ddy(vorticityMagnitude);
                    
                    float vorticityGradientMagnitude = sqrt(vorticityDx * vorticityDx + vorticityDy * vorticityDy);

                    float distance = (vorticityMagnitude - _VorticityContourLevel) / (vorticityGradientMagnitude + 1e-5);

                    float contourMask = step(abs(distance), _VorticityContourHalfWidth);
                    vorticityColour.rgb = lerp(vorticityColour.rgb, _VorticityContourColor.rgb, contourMask * _VorticityContourColor.a);
                    
                    return vorticityColour;

                #elif defined(RENDER_DENSITY)

                    normalisedDensity = saturate((density - _DensityOffset) * _InverseDensityRange);
                    return tex2D(_DensityColorTexture, float2(normalisedDensity, 0.5));

                #elif defined(RENDER_VELOCITY)

                    float velocityMagnitude = tex2D(_VelocityMagnitudeTexture, IN.texelCoord).r;
                    float normalisedVelocityMagnitude = saturate((velocityMagnitude - _VelocityOffset) * _InverseVelocityRange);
                    return tex2D(_VelocityMagnitudeColorTexture, float2(normalisedVelocityMagnitude, 0.5));

                #endif

                normalisedDensity = saturate((density - _DensityOffset) * _InverseDensityRange);
                return tex2D(_DensityColorTexture, float2(normalisedDensity, 0.5));
            }
            ENDCG
        }
    }
}
