import QtQuick 2.4

ColorPickerForm {
    Binding {target: colorViewModel; property: "Hue"; value: hueSlider.value}
    Binding {target: colorViewModel; property: "Saturation"; value: saturationSlider.value}
    Binding {target: colorViewModel; property: "Value"; value: valueSlider.value}
    Binding {target: colorViewModel; property: "Hue"; value: hueLabel.data}

    background: hsva(colorViewModel.Hue/360, colorViewModel.Saturation/100, colorViewModel.Value/100, 1)

    hueLabel.text: colorViewModel.Hue
    saturationLabel.text: colorViewModel.Saturation
    valueLabel.text: colorViewModel.Value

}
