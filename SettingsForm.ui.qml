import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3

Page {
    id: settingsPage
    width: 480
    height: 640
    property alias button: button
    clip: true
    property alias portTextField1: portTextField
    property alias ipTextField: ipTextField

    ColumnLayout {
        id: columnLayout
        x: 43
        y: 71
        width: 395
        height: 268
        transformOrigin: Item.Top
        spacing: 25
        clip: false

        RowLayout {
            id: rowLayout
            y: 0
            width: 400
            height: 150
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            spacing: 15
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            ColumnLayout {
                id: labelsColumn
                width: 200
                height: 200
                spacing: 45

                Text {
                    id: iPLabel
                    y: -10
                    text: qsTr("IP urządzenia:")
                    verticalAlignment: Text.AlignTop
                    font.pixelSize: 28
                }

                Text {
                    id: portLabel
                    y: 70
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
                    text: qsTr("192.168.1.6")
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                    font.bold: false
                    font.pointSize: 18
                    validator: RegExpValidator {
                        regExp: /^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$/
                    }
                }

                TextField {
                    id: portTextField
                    text: qsTr("5000")
                    Layout.fillWidth: true
                    font.pointSize: 18
                    validator: IntValidator{
                        bottom: 0
                        top: 65535
                    }
                }
            }
        }
    }

    Button {
        id: button
        x: 208
        y: 487
        text: qsTr("Zapisz")
        Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
        Layout.fillWidth: false
        Layout.fillHeight: false
    }
}
