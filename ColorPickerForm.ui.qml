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
    width: 480
    height: 640
    padding: 20
    contentHeight: 3
    focusPolicy: Qt.NoFocus
    font.capitalization: Font.MixedCase
    spacing: 10
    hoverEnabled: true
    clip: true

    Column {
        id: sliders
        anchors.rightMargin: 0
        anchors.bottomMargin: 34
        anchors.leftMargin: 0
        anchors.topMargin: 239
        anchors.fill: parent
        Layout.fillWidth: true

        TextEdit {
            id: bvValueLabel
            text: qsTr("val")
            anchors.right: parent.right
            anchors.rightMargin: 77
            horizontalAlignment: Text.AlignRight
            anchors.verticalCenter: bvSlider.verticalCenter
            font.pixelSize: 18
        }

        TextEdit {
            id: gsValueLabel
            text: qsTr("sat")
            horizontalAlignment: Text.AlignRight
            anchors.right: bvValueLabel.right
            anchors.rightMargin: 0
            anchors.verticalCenter: gsSlider.verticalCenter
            font.pixelSize: 18
        }

        TextEdit {
            id: rhValueLabel
            text: qsTr("hue")
            horizontalAlignment: Text.AlignRight
            anchors.verticalCenter: rhSlider.verticalCenter
            anchors.right: gsValueLabel.right
            anchors.rightMargin: 0
            renderType: Text.QtRendering
            font.pixelSize: 18
        }

        Text {
            id: bvLabel
            height: 27
            text: qsTr("Jasnosc")
            horizontalAlignment: Text.AlignRight
            anchors.right: bvSlider.left
            anchors.rightMargin: 10
            anchors.verticalCenter: bvValueLabel.verticalCenter
            font.pixelSize: 18
            fontSizeMode: Text.VerticalFit
        }

        Text {
            id: gsLabel
            height: 27
            text: qsTr("Nasycenie")
            horizontalAlignment: Text.AlignRight
            anchors.right: gsSlider.left
            anchors.rightMargin: 10
            anchors.verticalCenter: gsSlider.verticalCenter
            font.pixelSize: 18
            fontSizeMode: Text.VerticalFit
        }

        Text {
            id: rhLabel
            height: 27
            text: qsTr("Barwa")
            horizontalAlignment: Text.AlignRight
            anchors.right: gsLabel.right
            anchors.rightMargin: 0
            anchors.verticalCenter: rhSlider.verticalCenter
            fontSizeMode: Text.VerticalFit
            font.pixelSize: 18
        }

        Slider {
            id: rhSlider
            anchors.bottom: gsSlider.top
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            focusPolicy: Qt.NoFocus
            to: 360
            stepSize: 0.8
            value: 0
        }

        Slider {
            id: bvSlider
            anchors.top: gsSlider.bottom
            anchors.topMargin: 10
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

    Column {
        id: boxhex
        x: 20
        y: 20
        anchors.bottomMargin: 360
        anchors.fill: parent
        Layout.fillWidth: true

        Rectangle {
            id: rectangle
            width: 150
            height: 150
            anchors.top: parent.top
            anchors.topMargin: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }

        TextEdit {
            id: hexCodeLabel
            text: qsTr("hex")
            readOnly: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: rectangle.bottom
            anchors.topMargin: 25
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
        }
    }
}
