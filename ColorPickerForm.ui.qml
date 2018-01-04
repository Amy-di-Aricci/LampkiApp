import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

Page {
    id: page
    contentWidth: -2
    property alias hueSlider: hueSlider
    property alias saturationSlider: saturationSlider
    property alias valueSlider: valueSlider
    property alias rectangle: rectangle
    property alias hueLabel: hueLabel
    property alias saturationLabel: saturationLabel
    property alias valueLabel: valueLabel
    property alias hexCodeLabel: hexCodeLabel

    Column {
        id: sliders
        x: 304
        y: 40
        width: 300
        height: 400

        TextEdit {
            id: valueLabel
            text: qsTr("val")
            anchors.verticalCenter: valueSlider.verticalCenter
            anchors.left: valueSlider.right
            anchors.leftMargin: 10
            font.pixelSize: 24
        }

        TextEdit {
            id: saturationLabel
            text: qsTr("sat")
            anchors.right: valueLabel.right
            anchors.rightMargin: 0
            anchors.verticalCenter: saturationSlider.verticalCenter
            font.pixelSize: 24
        }

        TextEdit {
            id: hueLabel
            text: qsTr("hue")
            anchors.verticalCenter: hueSlider.verticalCenter
            anchors.right: saturationLabel.right
            anchors.rightMargin: 0
            renderType: Text.QtRendering
            font.pixelSize: 24
        }

        Text {
            id: vLabel
            width: 22
            height: 27
            text: qsTr("V")
            anchors.right: valueSlider.left
            anchors.rightMargin: 10
            anchors.verticalCenter: valueLabel.verticalCenter
            font.pixelSize: 24
            fontSizeMode: Text.VerticalFit
        }

        Text {
            id: sLabel
            width: 22
            height: 27
            text: qsTr("S")
            anchors.right: vLabel.right
            anchors.rightMargin: 0
            anchors.verticalCenter: saturationSlider.verticalCenter
            font.pixelSize: 24
            fontSizeMode: Text.VerticalFit
        }

        Text {
            id: hLabel
            width: 22
            height: 27
            text: qsTr("H")
            anchors.right: sLabel.right
            anchors.rightMargin: 0
            anchors.verticalCenter: hueSlider.verticalCenter
            fontSizeMode: Text.VerticalFit
            font.pixelSize: 24
        }

        Slider {
            id: hueSlider
            anchors.top: saturationSlider.top
            anchors.topMargin: -75
            anchors.horizontalCenter: parent.horizontalCenter
            focusPolicy: Qt.NoFocus
            to: 360
            stepSize: 0.8
            value: 0
        }

        Slider {
            id: valueSlider
            anchors.bottom: saturationSlider.bottom
            anchors.bottomMargin: -75
            anchors.horizontalCenter: parent.horizontalCenter
            to: 100
            stepSize: 1
            value: 100
        }

        Slider {
            id: saturationSlider
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            to: 100
            stepSize: 1
            value: 100
        }
    }

    Column {
        id: boxhex
        x: 50
        y: 40
        width: 250
        height: 400
        anchors.left: parent.left
        anchors.leftMargin: 48

        Rectangle {
            id: rectangle
            width: 200
            height: 200
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter
        }

        TextEdit {
            id: hexCodeLabel
            text: qsTr("hex")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: rectangle.bottom
            anchors.topMargin: 50
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
        }
    }
}
