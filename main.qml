import QtQuick 2.9
import QtQuick.Controls 2.2
import LampkiAppSwipe.ColorViewModel 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    ColorViewModel {
        id: colorViewModel
    }

    SwipeView {
        anchors.fill: parent
        currentIndex: -2

        ColorPickerForm{
            id: colorPickerForm
            Binding {target: colorViewModel; property: "Hue"; value: colorPickerForm.hueSlider.value}
            Binding {target: colorViewModel; property: "Saturation"; value: colorPickerForm.saturationSlider.value}
            Binding {target: colorViewModel; property: "Value"; value: colorPickerForm.valueSlider.value}
            rectangle.color: Qt.hsva(colorViewModel.Hue/360, colorViewModel.Saturation/100, colorViewModel.Value/100, 1)
            hueLabel.text: colorViewModel.Hue
            saturationLabel.text: colorViewModel.Saturation
            valueLabel.text: colorViewModel.Value
        }

    }
}
