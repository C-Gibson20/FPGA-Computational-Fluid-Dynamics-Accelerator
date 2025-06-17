using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

public class UIController : MonoBehaviour
{
    [SerializeField] private UIDocument UIDocument;
    [SerializeField] private FluidSimulationRenderer fluidSimulationRenderer;

    private Camera mainCamera;
    private Transform fluidTransform;
    private Plane fluidPlane;

    private VisualElement root;

    private Label renderTitle;
    private VisualElement densityLegend;
    private VisualElement velocityLegend;
    private VisualElement vorticityLegend;
    private Label legendLabelMaximum;
    private Label legendLabelMinimum;

    private Button controlPanelButton;
    private VisualElement controlPanel;

    private Button resetButton;

    private Slider minimumDensitySlider;
    private Label minimumDensityValue;
    private Slider maximumDensitySlider;
    private Label maximumDensityValue;

    private Toggle velocityToggle;
    private Slider minimumVelocitySlider;
    private Label minimumVelocityValue;
    private Slider maximumVelocitySlider;
    private Label maximumVelocityValue;

    private Toggle streamlineToggle;
    private RadioButtonGroup streamlineLengthGroup;
    private string[] streamlineLengthArray;
    private IntegerField streamlineCount;

    private Toggle vorticityToggle;
    private Slider minimumVorticitySlider;
    private Label minimumVorticityValue;
    private Slider maximumVorticitySlider;
    private Label maximumVorticityValue;
    private Slider vorticitySlider;
    private Label vorticityValue;
    private string maximumDirection;
    private string minimumDirection;

    private VisualElement fluidInteractionOverlay;
    private Label fluidInteractionData;

    private FluidSimulationRenderer.FluidRenderMode fluidRenderMode;

    void Start()
    {
        mainCamera = Camera.main;
        fluidTransform = fluidSimulationRenderer.transform;
        fluidPlane = new Plane(fluidTransform.forward, fluidTransform.position);

        root = UIDocument.rootVisualElement;

        InitializeDisplayElements();

        // -- Control panel toggle --
        InitializeControlPanelElements();

        controlPanelButton.clicked += () =>
        {
            bool isOpen = controlPanel.style.display != DisplayStyle.None;
            controlPanel.style.display = isOpen ? DisplayStyle.None : DisplayStyle.Flex;
            controlPanelButton.text = isOpen ? "Open Control\nPanel" : "Close Control\nPanel";
        };

        // -- Density sliders --
        InitializeDensityElements();

        minimumDensitySlider.RegisterValueChangedCallback(evt =>
        {
            minimumDensityValue.text = $"Density Minimum: {evt.newValue:F3}";
            legendLabelMinimum.text = $"Minimum\nDensity: {minimumDensitySlider.value:F3}";
            fluidSimulationRenderer.densityOffset = evt.newValue;
            fluidSimulationRenderer.inverseDensityRangeValue = 1f / (maximumDensitySlider.value - evt.newValue);
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        maximumDensitySlider.RegisterValueChangedCallback(evt =>
        {
            maximumDensityValue.text = $"Density Maximum: {evt.newValue:F3}";
            legendLabelMaximum.text = $"Maximum\nDensity: {maximumDensitySlider.value:F3}";
            fluidSimulationRenderer.inverseDensityRangeValue = 1f / (evt.newValue - fluidSimulationRenderer.densityOffset);
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        // -- Velocity toggle --
        InitializeVelocityElements();

        velocityToggle.RegisterValueChangedCallback(evt =>
        {
            fluidRenderMode = evt.newValue ? FluidSimulationRenderer.FluidRenderMode.Velocity : (vorticityToggle.value ? FluidSimulationRenderer.FluidRenderMode.Vorticity : FluidSimulationRenderer.FluidRenderMode.Density);
            fluidSimulationRenderer.SetRender(fluidRenderMode);
            UpdateDisplay(fluidRenderMode);
        });

        // -- Velocity sliders --
        minimumVelocitySlider.RegisterValueChangedCallback(evt =>
        {
            minimumVelocityValue.text = $"Velocity Minimum: {evt.newValue:F3}";
            legendLabelMinimum.text = $"Minimum\nVelocity: {minimumVelocitySlider.value:F3}";
            fluidSimulationRenderer.velocityOffset = evt.newValue;
            fluidSimulationRenderer.inverseVelocityRangeValue = 1f / (maximumVelocitySlider.value - evt.newValue);
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        maximumVelocitySlider.RegisterValueChangedCallback(evt =>
        {
            maximumVelocityValue.text = $"Velocity Maximum: {evt.newValue:F3}";
            legendLabelMaximum.text = $"Maximum\nVelocity: {maximumVelocitySlider.value:F3}";
            fluidSimulationRenderer.inverseVelocityRangeValue = 1f / (evt.newValue - fluidSimulationRenderer.velocityOffset);
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        // -- Streamline toggle --
        InitializeStreamlineElements();

        streamlineToggle.RegisterValueChangedCallback(evt =>
        {
            fluidSimulationRenderer.renderStreamlines = evt.newValue;
            if (evt.newValue) fluidSimulationRenderer.InitializeStreamlineRender();
            else fluidSimulationRenderer.ReleaseStreamlineRender();
        });

        // -- Streamline length radio buttons --
        streamlineLengthGroup.RegisterValueChangedCallback(evt =>
        {
            string streamlineLengthString = streamlineLengthArray[evt.newValue];
            if (int.TryParse(streamlineLengthString, out int streamlineLengthInt))
            {
                fluidSimulationRenderer.streamlineLength = streamlineLengthInt;
                if (fluidSimulationRenderer.renderStreamlines) fluidSimulationRenderer.InitializeStreamlineRender();
            }
        });

        // -- Streamline count input field --
        streamlineCount.RegisterCallback<BlurEvent>(_ =>
        {
            int value = streamlineCount.value;
            if (value < 1) return;

            fluidSimulationRenderer.streamlineCount = value;
            if (fluidSimulationRenderer.renderStreamlines) fluidSimulationRenderer.InitializeStreamlineRender();
        });

        // -- Vorticity toggle --
        InitializeVorticityElements(); 

        vorticityToggle.RegisterValueChangedCallback(evt =>
        {
            fluidSimulationRenderer.renderVorticity = evt.newValue;
            if (evt.newValue) fluidSimulationRenderer.InitializeVorticityRender();

            fluidRenderMode = evt.newValue ? FluidSimulationRenderer.FluidRenderMode.Vorticity : (velocityToggle.value ? FluidSimulationRenderer.FluidRenderMode.Velocity : FluidSimulationRenderer.FluidRenderMode.Density);
            fluidSimulationRenderer.SetRender(fluidRenderMode);
            UpdateDisplay(fluidRenderMode);
        });

        // -- Vorticity sliders --
        minimumVorticitySlider.RegisterValueChangedCallback(evt =>
        {
            minimumVorticityValue.text = $"Vorticity Minimum: {evt.newValue:F3}";
            minimumDirection = (minimumVorticitySlider.value < 0) ? "Anti-Clockwise" : "Clockwise";
            legendLabelMinimum.text = $"Minimum\nVorticity: {minimumVorticitySlider.value:F3}\n{minimumDirection}";
            fluidSimulationRenderer.inverseVorticityRangeValue = 1f / (fluidSimulationRenderer.vorticityOffset - evt.newValue);
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        maximumVorticitySlider.RegisterValueChangedCallback(evt =>
        {
            maximumVorticityValue.text = $"Vorticity Maximum: {evt.newValue:F3}";
            maximumDirection = (maximumVorticitySlider.value < 0) ? "Anti-Clockwise" : "Clockwise";
            legendLabelMaximum.text = $"Maximum\nVorticity: {maximumVorticitySlider.value:F3}\n{maximumDirection}";
            fluidSimulationRenderer.vorticityOffset = evt.newValue;
            fluidSimulationRenderer.inverseVorticityRangeValue = 1f / (evt.newValue + minimumVorticitySlider.value);
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        // -- Vorticity contour level slider --
        vorticitySlider.RegisterValueChangedCallback(evt =>
        {
            vorticityValue.text = $"Contour Value: {evt.newValue:F2}";
            fluidSimulationRenderer.vorticityContourLevel = evt.newValue;
            fluidSimulationRenderer.ConfigureFluidMaterialShader();
        });

        // -- Fluid interaction data --
        InitializeFluidInteractionElements();

        fluidInteractionOverlay.RegisterCallback<PointerMoveEvent>(OnPointerMove);
        fluidInteractionOverlay.RegisterCallback<PointerLeaveEvent>(_ =>
        {
            fluidInteractionData.style.display = DisplayStyle.None;
        });

        // -- Reset button --
        resetButton = root.Q<Button>("reset-button");
        resetButton.clicked += () =>
        {
            ResetSettings();
        };
    }

    private void ResetSettings()
    {
        minimumDensitySlider.value = fluidSimulationRenderer.minimumDensity;
        maximumDensitySlider.value = fluidSimulationRenderer.maximumDensity;
        minimumDensityValue.text = $"Density Minimum: {fluidSimulationRenderer.minimumDensity:F3}";
        maximumDensityValue.text = $"Density Maximum: {fluidSimulationRenderer.maximumDensity:F3}";
        fluidSimulationRenderer.densityOffset = fluidSimulationRenderer.minimumDensity;
        fluidSimulationRenderer.inverseDensityRangeValue = 1f / (fluidSimulationRenderer.maximumDensity - fluidSimulationRenderer.minimumDensity);

        velocityToggle.value = false;
        minimumVelocitySlider.value = fluidSimulationRenderer.minimumVelocity;
        maximumVelocitySlider.value = fluidSimulationRenderer.maximumVelocity;
        minimumVelocityValue.text = $"Velocity Minimum: {fluidSimulationRenderer.minimumVelocity:F3}";
        maximumVelocityValue.text = $"Velocity Maximum: {fluidSimulationRenderer.maximumVelocity:F3}";
        fluidSimulationRenderer.velocityOffset = fluidSimulationRenderer.minimumVelocity;
        fluidSimulationRenderer.inverseVelocityRangeValue = 1f / (fluidSimulationRenderer.maximumVelocity - fluidSimulationRenderer.minimumVelocity);

        streamlineToggle.value = fluidSimulationRenderer.renderStreamlines;
        streamlineCount.value = fluidSimulationRenderer.streamlineCount;
        streamlineLengthGroup.value = Mathf.Clamp(Array.IndexOf(streamlineLengthArray, fluidSimulationRenderer.streamlineLength.ToString()), 0, streamlineLengthArray.Length - 1);

        vorticityToggle.value = false;
        minimumVorticitySlider.value = -fluidSimulationRenderer.maximumVorticity;
        maximumVorticitySlider.value = fluidSimulationRenderer.maximumVorticity;
        minimumVorticityValue.text = $"Vorticity Minimum: {-fluidSimulationRenderer.maximumVorticity:F3}";
        maximumVorticityValue.text = $"Vorticity Maximum: {fluidSimulationRenderer.maximumVorticity:F3}";
        fluidSimulationRenderer.vorticityOffset = fluidSimulationRenderer.maximumVorticity;
        fluidSimulationRenderer.inverseVorticityRangeValue = 1f / (fluidSimulationRenderer.maximumVorticity * 2f);

        vorticitySlider.value = fluidSimulationRenderer.vorticityContourLevel;
        vorticityValue.text = $"Contour Value: {vorticitySlider.value:F2}";

        fluidRenderMode = FluidSimulationRenderer.FluidRenderMode.Density;
        fluidSimulationRenderer.SetRender(fluidRenderMode);
        UpdateDisplay(fluidRenderMode);

        fluidSimulationRenderer.ConfigureFluidMaterialShader();
    }

    private void InitializeDisplayElements()
    {
        renderTitle = root.Q<Label>("render-title");
        renderTitle.style.display = DisplayStyle.Flex;

        InitializeLegendTextures();
        densityLegend = root.Q<VisualElement>("density-legend");
        velocityLegend = root.Q<VisualElement>("velocity-legend");
        vorticityLegend = root.Q<VisualElement>("vorticity-legend");
        densityLegend.style.display = DisplayStyle.Flex;

        legendLabelMaximum = root.Q<Label>("render-legend-label-max");
        legendLabelMinimum = root.Q<Label>("render-legend-label-min");
        legendLabelMaximum.text = $"Maximum\nDensity: {fluidSimulationRenderer.maximumDensity:F3}";
        legendLabelMinimum.text = $"Minimum\nDensity: {fluidSimulationRenderer.minimumDensity:F3}";
        legendLabelMaximum.style.display = DisplayStyle.Flex;
        legendLabelMinimum.style.display = DisplayStyle.Flex;
    }

    private void InitializeLegendTextures()
    {
        var legendTextureMap = new Dictionary<string, Texture2D>
        {
            { "density", fluidSimulationRenderer.densityColorTexture },
            { "velocity", fluidSimulationRenderer.velocityMagnitudeColorTexture },
            { "vorticity", fluidSimulationRenderer.vorticityColorTexture }
        };

        foreach (var keyTexturePair in legendTextureMap)
        {
            var legend = root.Q<VisualElement>($"{keyTexturePair.Key}-legend");
            legend.style.backgroundImage = new StyleBackground(keyTexturePair.Value);
            legend.style.rotate = new Rotate(-90);
            legend.style.transformOrigin = new TransformOrigin(Length.Percent(50), Length.Percent(50));
            legend.style.display = DisplayStyle.None;
        }
    }

    private void InitializeControlPanelElements()
    {
        controlPanelButton = root.Q<Button>("control-panel-toggle");
        controlPanelButton.text = "Open Control\nPanel";

        controlPanel = root.Q<VisualElement>("control-panel");
        controlPanel.style.display = DisplayStyle.None;
    }

    private void InitializeDensityElements()
    {
        minimumDensitySlider = root.Q<Slider>("density-minimum");
        minimumDensityValue = root.Q<Label>("density-minimum-label");
        minimumDensitySlider.value = fluidSimulationRenderer.minimumDensity;
        minimumDensitySlider.highValue = fluidSimulationRenderer.maximumDensity * 2;
        minimumDensityValue.text = $"Density Minimum: {fluidSimulationRenderer.minimumDensity:F3}";

        maximumDensitySlider = root.Q<Slider>("density-maximum");
        maximumDensityValue = root.Q<Label>("density-maximum-label");
        maximumDensitySlider.value = fluidSimulationRenderer.maximumDensity;
        maximumDensitySlider.highValue = fluidSimulationRenderer.maximumDensity * 2;
        maximumDensityValue.text = $"Density Maximum: {fluidSimulationRenderer.maximumDensity:F3}";
    }

    private void InitializeVelocityElements()
    {
        velocityToggle = root.Q<Toggle>("velocity-toggle");

        minimumVelocitySlider = root.Q<Slider>("velocity-minimum");
        minimumVelocityValue = root.Q<Label>("velocity-minimum-label");
        minimumVelocitySlider.value = fluidSimulationRenderer.minimumVelocity;
        minimumVelocitySlider.highValue = fluidSimulationRenderer.maximumVelocity * 2;
        minimumVelocityValue.text = $"Velocity Minimum: {fluidSimulationRenderer.minimumVelocity:F3}";


        maximumVelocitySlider = root.Q<Slider>("velocity-maximum");
        maximumVelocityValue = root.Q<Label>("velocity-maximum-label");
        maximumVelocitySlider.value = fluidSimulationRenderer.maximumVelocity;
        maximumVelocitySlider.highValue = fluidSimulationRenderer.maximumVelocity * 2;
        maximumVelocityValue.text = $"Velocity Minimum: {fluidSimulationRenderer.maximumVelocity:F3}";
    }

    private void InitializeStreamlineElements()
    {
        streamlineToggle = root.Q<Toggle>("streamline-toggle");
        streamlineToggle.value = fluidSimulationRenderer.renderStreamlines;

        streamlineLengthGroup = root.Q<RadioButtonGroup>("streamline-length");
        streamlineLengthArray = streamlineLengthGroup.choices.ToArray();
        streamlineLengthGroup.value = Mathf.Clamp(Array.IndexOf(streamlineLengthArray, fluidSimulationRenderer.streamlineLength.ToString()), 0, streamlineLengthArray.Length - 1);

        streamlineCount = root.Q<IntegerField>("streamline-count");
        streamlineCount.value = fluidSimulationRenderer.streamlineCount;
    }

    private void InitializeVorticityElements()
    {
        vorticityToggle = root.Q<Toggle>("vorticity-toggle");
        vorticityToggle.value = fluidSimulationRenderer.renderVorticity;

        minimumVorticitySlider = root.Q<Slider>("vorticity-minimum");
        minimumVorticityValue = root.Q<Label>("vorticity-minimum-label");
        minimumVorticitySlider.value = -fluidSimulationRenderer.maximumVorticity;
        minimumVorticitySlider.lowValue = -fluidSimulationRenderer.maximumVorticity * 2;
        minimumVorticitySlider.highValue = fluidSimulationRenderer.maximumVorticity * 2;
        minimumVorticityValue.text = $"Vorticity Minimum: {-fluidSimulationRenderer.maximumVorticity:F3}";

        maximumVorticitySlider = root.Q<Slider>("vorticity-maximum");
        maximumVorticityValue = root.Q<Label>("vorticity-maximum-label");
        maximumVorticitySlider.value = fluidSimulationRenderer.maximumVorticity;
        maximumVorticitySlider.lowValue = -fluidSimulationRenderer.maximumVorticity * 2;
        maximumVorticitySlider.highValue = fluidSimulationRenderer.maximumVorticity * 2;
        maximumVorticityValue.text = $"Vorticity Minimum: {fluidSimulationRenderer.maximumVorticity:F3}";

        vorticitySlider = root.Q<Slider>("vorticity-slider");
        vorticitySlider.value = fluidSimulationRenderer.vorticityContourLevel;
        vorticitySlider.highValue = fluidSimulationRenderer.maximumVorticity * 2;

        vorticityValue = root.Q<Label>("vorticity-value");
        vorticityValue.text = $"Contour Value: {vorticitySlider.value:F2}";
    }

    private void InitializeFluidInteractionElements()
    {
        fluidInteractionData = root.Q<Label>("fluid-interaction-data");
        fluidInteractionOverlay = root.Q<VisualElement>("fluid-interaction-overlay");
    }

    private void UpdateDisplay(FluidSimulationRenderer.FluidRenderMode renderMode)
    {
        switch (renderMode)
        {
            case FluidSimulationRenderer.FluidRenderMode.Density:
                renderTitle.text = "Density Field";
                legendLabelMaximum.text = $"Maximum\nDensity: {maximumDensitySlider.value:F3}";
                legendLabelMinimum.text = $"Minimum\nDensity: {minimumDensitySlider.value:F3}";
                densityLegend.style.display = DisplayStyle.Flex;
                velocityLegend.style.display = DisplayStyle.None;
                vorticityLegend.style.display = DisplayStyle.None;
                break;
            case FluidSimulationRenderer.FluidRenderMode.Velocity:
                renderTitle.text = "Velocity Field";
                legendLabelMaximum.text = $"Maximum\nVelocity: {maximumVelocitySlider.value:F3}";
                legendLabelMinimum.text = $"Minimum\nVelocity: {minimumVelocitySlider.value:F3}";
                densityLegend.style.display = DisplayStyle.None;
                velocityLegend.style.display = DisplayStyle.Flex;
                vorticityLegend.style.display = DisplayStyle.None;
                break;
            case FluidSimulationRenderer.FluidRenderMode.Vorticity:
                maximumDirection = (maximumVorticitySlider.value < 0) ? "Anti-Clockwise" : "Clockwise";
                minimumDirection = (minimumVorticitySlider.value < 0) ? "Anti-Clockwise" : "Clockwise";

                renderTitle.text = "Vorticity Field";
                legendLabelMaximum.text = $"Maximum\nVorticity: {maximumVorticitySlider.value:F3}\n{maximumDirection}";
                legendLabelMinimum.text = $"Minimum\nVorticity: {minimumVorticitySlider.value:F3}\n{minimumDirection}";
                densityLegend.style.display = DisplayStyle.None;
                velocityLegend.style.display = DisplayStyle.None;
                vorticityLegend.style.display = DisplayStyle.Flex;
                break;
            default:
                renderTitle.text = "Density Field";
                legendLabelMaximum.text = $"Maximum\nDensity: {maximumDensitySlider.value:F3}";
                legendLabelMinimum.text = $"Minimum\nDensity: {minimumDensitySlider.value:F3}";
                densityLegend.style.display = DisplayStyle.Flex;
                velocityLegend.style.display = DisplayStyle.None;
                vorticityLegend.style.display = DisplayStyle.None;
                break;
        }
    }

    private void OnPointerMove(PointerMoveEvent evt)
    {
        // -- Current mouse position origin at the bottom-left --
        Vector2 mouseScreenPosition = Mouse.current.position.ReadValue();

        // -- Camera ray to mouse position --
        Ray cameraToMouseRay = mainCamera.ScreenPointToRay(mouseScreenPosition);

        // -- Raycast against fluid render plane --
        if (fluidPlane.Raycast(cameraToMouseRay, out float enter))
        {
            Transform fluidTransform = fluidSimulationRenderer.transform;
            Vector3 worldHitPoint = cameraToMouseRay.GetPoint(enter);
            Vector3 localHitPoint = fluidTransform.InverseTransformPoint(worldHitPoint);

            // -- Normalize quad space (-0.5 to +0.5) to UV space (0 to 1) --
            Vector2 normalizedUv = new Vector2(localHitPoint.x + 0.5f, localHitPoint.y + 0.5f);

            // -- Check hit point bounds --
            if (normalizedUv.x >= 0 && normalizedUv.x <= 1 && normalizedUv.y >= 0 && normalizedUv.y <= 1)
            {
                float[] data = fluidSimulationRenderer.SampleTexelData(normalizedUv);
                fluidInteractionData.style.display = DisplayStyle.Flex;
                fluidInteractionData.text = $"Density: {data[0]:F5}\nVelocity: ({data[1]:F5}, {data[2]:F5})\n|Velocity|: {data[3]:F5}";
                fluidInteractionData.style.left = evt.position.x + 10;
                fluidInteractionData.style.top = evt.position.y +10;
            }
            else
            {
                // -- Out of bounds --
                fluidInteractionData.style.display = DisplayStyle.None;
            }
        }
        else
        {
            // -- Out of plane --
            fluidInteractionData.style.display = DisplayStyle.None;
        }
    }
}
