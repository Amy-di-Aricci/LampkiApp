import QtQuick 2.9
import QtQuick.Controls 2.2
import LampkiAppSwipe.ColorViewModel 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    SwipeView {
        anchors.fill: parent
        currentIndex: -2
        /*ColorViewModel {
            id: colorViewModel
            onTypeSelectionChanged: {
                console.log("cokolwiek");
            }
        }*/
        Loader
        {
            source: "ColorPicker.qml"
        }
        Loader
        {
            source: "GradientPicker.qml"
        }
    }

}
