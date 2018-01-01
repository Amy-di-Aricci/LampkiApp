import QtQuick 2.4

ColorPickerForm {
    Binding {target: hsvColorViewModel; property: "Hue"; value: hueSlider.value}
    Binding {target: hsvColorViewModel; property: "Saturation"; value: saturationSlider.value}
    Binding {target: hsvColorViewModel; property: "Value"; value: valueSlider.value}
    Binding {target: hsvColorViewModel; property: "Hue"; value: hueLabel.data}

    background: hsva(hsvColorViewModel.Hue/360, hsvColorViewModel.Saturation/100, hsvColorViewModel.Value/100, 1)

    hueLabel.text: hsvColorViewModel.Hue
    saturationLabel.text: hsvColorViewModel.Saturation
    valueLabel.text: hsvColorViewModel.Value

}
