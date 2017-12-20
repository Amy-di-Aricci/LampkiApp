import QtQuick 2.4

ColorPickerForm {
    Binding {target: hsvColorViewModel; property: "Hue"; value: hueSlider.value}
    Binding {target: hsvColorViewModel; property: "Saturation"; value: saturationSlider.value}
    Binding {target: hsvColorViewModel; property: "Value"; value: valueSlider.value}

    background: hsva(hsvColorViewModel.Hue/360, hsvColorViewModel.Saturation/100, hsvColorViewModel.Value/100, 1)

    hexCodeLabel.text: hsvColorViewModel.Hue
}
