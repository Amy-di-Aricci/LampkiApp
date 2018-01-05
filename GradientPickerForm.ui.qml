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
    contentWidth: -2

    Rectangle {
        id: rectangle
        x: 20
        y: 22
        width: 75
        height: 75
        color: "#ff0000"
    }

    Slider {
        id: rhSlider
        x: 173
        y: 170
        stepSize: 1
        to: 360
        value: 0
    }

    Slider {
        id: gsSlider
        x: 173
        y: 236
        width: 200
        height: 51
        stepSize: 1
        to: 100
        value: 100
    }

    Slider {
        id: bvSlider
        x: 173
        y: 315
        stepSize: 1
        to: 100
        value: 100
    }

    Rectangle {
        id: rectangle1
        x: 123
        y: 22
        width: 30
        height: 75
        color: "#ff0000"
    }

    Rectangle {
        id: rectangle2
        x: 180
        y: 22
        width: 30
        height: 75
        color: "#ff0000"
    }

    Rectangle {
        id: rectangle3
        x: 240
        y: 22
        width: 30
        height: 75
        color: "#ff0000"
    }

    Rectangle {
        id: rectangle4
        x: 299
        y: 22
        width: 30
        height: 75
        color: "#ff0000"
    }

    Rectangle {
        id: rectangle5
        x: 360
        y: 22
        width: 30
        height: 75
        color: "#ff0000"
    }

    Rectangle {
        id: rectangle6
        x: 418
        y: 22
        width: 30
        height: 75
        color: "#ff0000"
    }

    Rectangle {
        id: rectangle7
        x: 476
        y: 22
        width: 75
        height: 75
        color: "#ff0000"
    }

    Button {
        id: sendButton
        x: 223
        y: 396
        text: qsTr("Wyslij!")
    }
}
