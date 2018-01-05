import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

Page {
    id: gradientPage
    property alias rectangle: rectangle
    property alias rectangle1: rectangle1
    property alias rhSlider: rhSlider
    property alias gsSlider: gsSlider
    property alias bvSlider: bvSlider
    contentWidth: -2

    Rectangle {
        id: rectangle
        x: 20
        y: 22
        width: 200
        height: 200
        color: "#ff0000"
    }

    Slider {
        id: rhSlider
        x: 165
        y: 255
        stepSize: 1
        to: 360
        value: 0
    }

    Slider {
        id: gsSlider
        x: 165
        y: 329
        width: 200
        height: 51
        stepSize: 1
        to: 100
        value: 100
    }

    Slider {
        id: bvSlider
        x: 165
        y: 428
        stepSize: 1
        to: 100
        value: 100
    }

    Rectangle {
        id: rectangle1
        x: 280
        y: 82
        width: 125
        height: 102
        color: "#ff0000"
    }
}
