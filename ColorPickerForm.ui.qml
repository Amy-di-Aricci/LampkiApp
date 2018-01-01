import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

Page {
    contentWidth: -2
    property alias hueSlider: hueSlider
    property alias saturationSlider: saturationSlider
    property alias valueSlider: valueSlider
    property alias rectangle: rectangle
    property alias hueLabel: hueLabel
    property alias saturationLabel: saturationLabel
    property alias valueLabel: valueLabel
    property alias hexCodeLabel: hexCodeLabel

    Slider {
        id: saturationSlider
        x: 220
        y: 299
        to: 100
        stepSize: 1
        value: 100
    }

    Slider {
        id: valueSlider
        x: 219
        y: 346
        to: 100
        stepSize: 1
        value: 100
    }

    Slider {
        id: hueSlider
        x: 219
        y: 244
        focusPolicy: Qt.NoFocus
        to: 360
        stepSize: 0.8
        value: 0
    }

    Text {
        id: hLabel
        x: 194
        y: 249
        width: 22
        height: 27
        text: qsTr("H")
        fontSizeMode: Text.VerticalFit
        font.pixelSize: 24
    }

    Text {
        id: sLabel
        x: 194
        y: 299
        width: 22
        height: 27
        text: qsTr("S")
        font.pixelSize: 24
        fontSizeMode: Text.VerticalFit
    }

    Text {
        id: vLabel
        x: 194
        y: 348
        width: 22
        height: 27
        text: qsTr("V")
        font.pixelSize: 24
        fontSizeMode: Text.VerticalFit
    }

    TextEdit {
        id: hueLabel
        x: 425
        y: 247
        text: qsTr("hue")
        renderType: Text.QtRendering
        font.pixelSize: 24
    }

    Rectangle {
        id: rectangle
        x: 269
        y: 52
        width: 100
        height: 100
    }

    TextEdit {
        id: saturationLabel
        x: 425
        y: 298
        text: qsTr("sat")
        font.pixelSize: 24
    }

    TextEdit {
        id: valueLabel
        x: 425
        y: 348
        text: qsTr("val")
        font.pixelSize: 24
    }

    TextEdit {
        id: hexCodeLabel
        x: 298
        y: 187
        text: qsTr("hex")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 24
    }
}
