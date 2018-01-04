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
        /*ColorViewModel {
            id: colorViewModel
            onTypeSelectionChanged: {
                console.log("cokolwiek");
            }
        }*/
        ColorPickerForm{
            id: colorPickerForm
            Binding {target: colorViewModel; property: "RH"; value: colorPickerForm.rhSlider.value}
            Binding {target: colorViewModel; property: "GS"; value: colorPickerForm.gsSlider.value}
            Binding {target: colorViewModel; property: "BV"; value: colorPickerForm.bvSlider.value}
            Binding {target: colorViewModel; property: "TypeSelection"; value: colorPickerForm.comboBox.currentIndex}
            rectangle.color: Qt.hsva(colorViewModel.RH/360, colorViewModel.GS/100, colorViewModel.BV/100, 1)
            rhValueLabel.text: colorViewModel.RH
            gsValueLabel.text: colorViewModel.GS
            bvValueLabel.text: colorViewModel.BV
            button.onClicked: {
                console.log("RH=", colorViewModel.RH, "GS=", colorViewModel.GS, "BV=", colorViewModel.BV);
                hexCodeLabel.text = colorViewModel.Hex;
            }

        }

    }

}
