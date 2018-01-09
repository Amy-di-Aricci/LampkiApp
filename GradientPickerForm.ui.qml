import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

Page {
    id: gradientPage
    property alias rectangle: rectangle
    property alias rectangle1: rectangle1
    property alias rectangle2: rectangle2
    property alias rectangle3: rectangle3
    property alias rectangle4: rectangle4
    property alias rectangle5: rectangle5
    property alias rectangle6: rectangle6
    property alias rectangle7: rectangle7
    property alias rhSlider: rhSlider
    property alias gsSlider: gsSlider
    property alias bvSlider: bvSlider
    property alias sendButton: sendButton
    property alias firstColorButton: firstColorButton
    property alias lastColorButton: lastColorButton
    property alias rhLabel: rhLabel
    property alias gsLabel: gsLabel
    property alias bvLabel: bvLabel
    property alias rhValueLabel: rhValueLabel
    property alias gsValueLabel: gsValueLabel
    property alias bvValueLabel: bvValueLabel
        property alias comboBox: comboBox
    width: 480
    height: 640
    title: "Gradient"
    clip: true
    contentWidth: -2

    Row {
        id: row
        x: 75
        y: 76
        width: 331
        height: 75

        Rectangle {
            id: rectangle
            width: 75
            height: 75
            color: "#ff0000"

            Button {
                id: firstColorButton
                text: qsTr("")
                anchors.fill: parent
                checked: true
                focusPolicy: Qt.NoFocus
                checkable: true
                opacity: 0
                spacing: 8
            }
        }

        Rectangle {
            id: rectangle1
            width: 30
            height: 75
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle2
            width: 30
            height: 75
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle3
            width: 30
            height: 75
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle4
            width: 30
            height: 75
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle5
            width: 30
            height: 75
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle6
            width: 30
            height: 75
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle7
            width: 75
            height: 75
            color: "#ff0000"

            Button {
                id: lastColorButton
                text: qsTr("Button")
                checkable: true
                opacity: 0
                anchors.fill: parent
            }
        }
    }

    Column {
        id: column
        x: 140
        y: 263
        width: 200
        height: 240
        spacing: 10

        Slider {
            id: rhSlider
            anchors.horizontalCenter: parent.horizontalCenter
            stepSize: 1
            to: 360
            value: 0
        }

        Slider {
            id: gsSlider
            width: 200
            height: 51
            anchors.horizontalCenter: parent.horizontalCenter
            stepSize: 1
            to: 100
            value: 100
        }

        Slider {
            id: bvSlider
            anchors.horizontalCenter: parent.horizontalCenter
            stepSize: 1
            to: 100
            value: 100
        }

        Button {
            id: sendButton
            text: qsTr("Wyslij")
            focusPolicy: Qt.NoFocus
            spacing: 4
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    ComboBox {
        id: comboBox
        x: 180
        y: 191
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

    Column {
        id: nameLabels
        x: 49
        y: 273
        width: 85
        height: 177
        spacing: 40

        Text {
            id: rhLabel
            text: qsTr("Barwa")
            anchors.right: parent.right
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 18
        }

        Text {
            id: gsLabel
            text: qsTr("Nasycenie")
            anchors.right: parent.right
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 18
        }

        Text {
            id: bvLabel
            text: qsTr("Jasnosc")
            anchors.right: parent.right
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 18
        }
    }

    Column {
        id: valueLabels
        x: 346
        y: 273
        width: 85
        height: 177
        spacing: 40
        Text {
            id: rhValueLabel
            text: qsTr("hue")
            font.pixelSize: 18
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id: gsValueLabel
            text: qsTr("sat")
            font.pixelSize: 18
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id: bvValueLabel
            text: qsTr("val")
            font.pixelSize: 18
            horizontalAlignment: Text.AlignLeft
        }
    }
}
