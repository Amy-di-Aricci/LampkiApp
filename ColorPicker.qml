import QtQuick 2.4

ColorPickerForm {

    Binding {target: colorViewModel; property: "RH"; value: rhSlider.value}
    Binding {target: colorViewModel; property: "GS"; value: gsSlider.value}
    Binding {target: colorViewModel; property: "BV"; value: bvSlider.value}

    background: hsva(colorViewModel.Hue/360, colorViewModel.Saturation/100, colorViewModel.Value/100, 1)

    hueLabel.text: colorViewModel.RH
    saturationLabel.text: colorViewModel.GS
    valueLabel.text: colorViewModel.BV

}
