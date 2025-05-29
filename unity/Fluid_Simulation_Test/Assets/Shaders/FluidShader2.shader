Shader "Custom/FluidShader2"
{
    Properties {
        _MainTex    ("Fluid Data", 2D) = "white" {}
        _ColorRamp  ("Color Ramp", 2D) = "white" {}
    }
    SubShader {
        Tags { "RenderType"="Opaque" }
        LOD 100

        Pass {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"

            sampler2D _MainTex;
            sampler2D _ColorRamp;

            struct appdata {
                float4 vertex : POSITION;
                float2 uv     : TEXCOORD0;
            };

            struct v2f {
                float2 uv      : TEXCOORD0;
                float4 vertex  : SV_POSITION;
            };

            v2f vert(appdata IN)
            {
                v2f OUT;
                OUT.vertex = UnityObjectToClipPos(IN.vertex);
                OUT.uv = IN.uv;
                return OUT;
            }

            fixed4 frag(v2f IN) : SV_Target
            {
                float4 data = tex2D(_MainTex, IN.uv);
                float density = data.b;

                float t = saturate((density - 0.9) / 0.2);

                return tex2D(_ColorRamp, float2(t, 0.5));
            }
            ENDCG
        }
    }
}