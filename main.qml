import QtQuick 2.9
import QtQuick.Controls 2.2
import LampkiAppSwipe.HSVColorViewModel 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    HSVColorViewModel {
        id: hsvColorViewModel
    }

    SwipeView {
        anchors.fill: parent
        currentIndex: -2

        ColorPickerForm{
            id: colorPickerForm
            Binding {target: hsvColorViewModel; property: "Hue"; value: colorPickerForm.hueSlider.value}
            Binding {target: hsvColorViewModel; property: "Saturation"; value: colorPickerForm.saturationSlider.value}
            Binding {target: hsvColorViewModel; property: "Value"; value: colorPickerForm.valueSlider.value}
            rectangle.color: Qt.hsva(hsvColorViewModel.Hue/360, hsvColorViewModel.Saturation/100, hsvColorViewModel.Value/100, 1)
            hueLabel.text: hsvColorViewModel.Hue
            saturationLabel.text: hsvColorViewModel.Saturation
            valueLabel.text: hsvColorViewModel.Value
        }

    }
}
