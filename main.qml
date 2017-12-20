import QtQuick 2.9
import QtQuick.Controls 2.2
import LampkiApp.TestViewModel 1.0
import LampkiApp.ColorViewModel 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    Binding {target: testViewModel; property: "numberValue"; value: slider.value}

    TestViewModel {
        id: testViewModel
    }

    ColorViewModel {
        id: colorViewModel
    }

    SwipeView {
        anchors.fill: parent
        currentIndex: -2

        Page {
            Text {
                id: aaa
                text: testViewModel.numberValue
                color: "#ffffff"
            }

            Text {
                id: bbb
                x: 336
                y: 19
                color: "#bbbbbb"
                text: testViewModel.numberValue
            }

            Slider {
                id: slider
                x: 130
                y: 124
                to: 100
                stepSize: 1
                value: 50
            }

            Button {
                id: button
                x: 231
                y: 281
                text: qsTr("Button")
                focusPolicy: Qt.StrongFocus
                onClicked: {
                    bbb.text = testViewModel.numberValue;
                }
            }
        }

        ColorPickerForm{
            id: colorPickerForm
            Binding {target: colorViewModel; property: "Hue"; value: colorPickerForm.hueSlider.value}
            Binding {target: colorViewModel; property: "Saturation"; value: colorPickerForm.saturationSlider.value}
            Binding {target: colorViewModel; property: "Value"; value: colorPickerForm.valueSlider.value}
            //rect: Qt.hsva(colorViewModel.Hue/360, colorViewModel.Saturation/100, colorViewModel.Value/100, 1)
            rect.color: Qt.hsva(colorViewModel.Hue/360, colorViewModel.Saturation/100, colorViewModel.Value/100, 1)
            hexCodeLabel.text: colorViewModel.Hue
        }

    }

    /*SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
        }

        Page2Form {
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }*/
}
