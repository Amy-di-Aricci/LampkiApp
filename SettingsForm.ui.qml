import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3

Page {
    id: settingsPage
    width: 640
    height: 480

    RowLayout {
        id: rowLayout
        x: 113
        y: 45
        width: 415
        height: 150
        spacing: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        ColumnLayout {
            id: labelsColumn
            width: 200
            height: 200
            spacing: 25

            Text {
                id: iPLabel
                text: qsTr("IP urządzenia:")
                font.pixelSize: 28
            }

            Text {
                id: portLabel
                text: qsTr("Port:")
                textFormat: Text.PlainText
                font.pixelSize: 28
            }
        }

        ColumnLayout {
            id: inputColumn
            width: 250
            height: 200
            spacing: 25

            TextField {
                id: ipTextField
                text: qsTr("Text Field")
            }

            TextField {
                id: portTextField1
                text: qsTr("Text Field")
            }
        }
    }
}
