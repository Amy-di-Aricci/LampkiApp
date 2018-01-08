import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3

Page {
    id: page
    contentWidth: -2
    property alias rhSlider: rhSlider
    property alias gsSlider: gsSlider
    property alias bvSlider: bvSlider
    property alias rectangle: rectangle
    property alias hexCodeLabel: hexCodeLabel
    property alias rhValueLabel: rhValueLabel
    property alias gsValueLabel: gsValueLabel
    property alias bvValueLabel: bvValueLabel
    property alias comboBox: comboBox
    property alias button: button
    property alias rhLabel: rhLabel
    property alias gsLabel: gsLabel
    property alias bvLabel: bvLabel
    padding: 20
    contentHeight: 3
    focusPolicy: Qt.NoFocus
    font.capitalization: Font.MixedCase
    spacing: 10
    hoverEnabled: true
    clip: true

    Flow {
        id: flow1
        layoutDirection: Qt.LeftToRight
        flow: Flow.LeftToRight
        spacing: 10
        anchors.fill: parent

        Column {
            id: boxhex
            width: 250
            height: 400
            clip: true
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 0

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
                readOnly: true
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: rectangle.bottom
                anchors.topMargin: 50
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
            }
        }

        Column {
            id: sliders
            width: 300
            height: 400
            clip: true
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 0

            TextEdit {
                id: bvValueLabel
                text: qsTr("val")
                anchors.verticalCenter: bvSlider.verticalCenter
                anchors.left: bvSlider.right
                anchors.leftMargin: 10
                font.pixelSize: 24
            }

            TextEdit {
                id: gsValueLabel
                text: qsTr("sat")
                anchors.right: bvValueLabel.right
                anchors.rightMargin: 0
                anchors.verticalCenter: gsSlider.verticalCenter
                font.pixelSize: 24
            }

            TextEdit {
                id: rhValueLabel
                text: qsTr("hue")
                anchors.verticalCenter: rhSlider.verticalCenter
                anchors.right: gsValueLabel.right
                anchors.rightMargin: 0
                renderType: Text.QtRendering
                font.pixelSize: 24
            }

            Text {
                id: bvLabel
                width: 22
                height: 27
                text: qsTr("V")
                anchors.right: bvSlider.left
                anchors.rightMargin: 10
                anchors.verticalCenter: bvValueLabel.verticalCenter
                font.pixelSize: 24
                fontSizeMode: Text.VerticalFit
            }

            Text {
                id: gsLabel
                width: 22
                height: 27
                text: qsTr("S")
                anchors.right: bvLabel.right
                anchors.rightMargin: 0
                anchors.verticalCenter: gsSlider.verticalCenter
                font.pixelSize: 24
                fontSizeMode: Text.VerticalFit
            }

            Text {
                id: rhLabel
                width: 22
                height: 27
                text: qsTr("H")
                anchors.right: gsLabel.right
                anchors.rightMargin: 0
                anchors.verticalCenter: rhSlider.verticalCenter
                fontSizeMode: Text.VerticalFit
                font.pixelSize: 24
            }

            Slider {
                id: rhSlider
                anchors.top: gsSlider.top
                anchors.topMargin: -75
                anchors.horizontalCenter: parent.horizontalCenter
                focusPolicy: Qt.NoFocus
                to: 360
                stepSize: 0.8
                value: 0
            }

            Slider {
                id: bvSlider
                anchors.bottom: gsSlider.bottom
                anchors.bottomMargin: -75
                anchors.horizontalCenter: parent.horizontalCenter
                to: 100
                stepSize: 1
                value: 100
            }

            Slider {
                id: gsSlider
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                to: 100
                stepSize: 1
                value: 100
            }

            Button {
                id: button
                text: qsTr("Wyslij")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 25
            }

            ComboBox {
                id: comboBox
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                model: ListModel {
                    id: cbItems
                    ListElement {
                        text: "HSV"
                    }
                    ListElement {
                        text: "RGB"
                    }
                }
            }
        }
    }
}
