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
    clip: true
    contentWidth: -2

    Row {
        id: row
        x: 155
        y: 51
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
                opacity: 0
                spacing: 8
                focusPolicy: Qt.NoFocus
                anchors.fill: parent
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
                opacity: 0
                anchors.fill: parent
            }
        }
    }

    Column {
        id: column
        x: 220
        y: 176
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
            text: qsTr("Wyslij!")
            anchors.horizontalCenter: parent.horizontalCenter
            focusPolicy: Qt.NoFocus
        }
    }
}
