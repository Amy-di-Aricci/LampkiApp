import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

Page {
    contentWidth: -2
    property alias hexCodeLabel: hexCodeLabel
    property alias hueSlider: hueSlider
    property alias saturationSlider: saturationSlider
    property alias valueSlider: valueSlider
    property alias rect: rect

    Slider {
        id: saturationSlider
        x: 100
        y: 250
        to: 100
        stepSize: 1
        value: 100
    }

    Slider {
        id: valueSlider
        x: 100
        y: 300
        to: 100
        stepSize: 1
        value: 0
    }

    Slider {
        id: hueSlider
        x: 100
        y: 200
        focusPolicy: Qt.NoFocus
        to: 360
        stepSize: 1
        value: 180
    }

    Text {
        id: hLabel
        x: 75
        y: 205
        width: 22
        height: 27
        text: qsTr("H")
        fontSizeMode: Text.VerticalFit
        font.pixelSize: 24
    }

    Text {
        id: sLabel
        x: 75
        y: 255
        width: 22
        height: 27
        text: qsTr("S")
        font.pixelSize: 24
        fontSizeMode: Text.VerticalFit
    }

    Text {
        id: vLabel
        x: 75
        y: 305
        width: 22
        height: 27
        text: qsTr("V")
        font.pixelSize: 24
        fontSizeMode: Text.VerticalFit
    }

    Text {
        id: hexCodeLabel
        x: 179
        y: 100
        text: qsTr("Text")
        font.pixelSize: 24
    }

    Rectangle{
        id: rect
        x: 10
        y: 10
        width: 30
        height: 30
    }
}
