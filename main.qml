import QtQuick 2.9
import QtQuick.Controls 2.2
import LampkiAppSwipe.ColorViewModel 1.0

ApplicationWindow {
    visible: true
    width: 480
    height: 640
    title: qsTr("Tabs")
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        Loader
        {
            source: "ColorPicker.qml"
        }
        Loader
        {
            source: "GradientPicker.qml"
        }
        Loader
        {
            source: "Settings.qml"
        }
    }
    footer: TabBar{
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton{
            text: qsTr("Jeden Kolor")
        }
        TabButton{
            text: qsTr("Gradient")
        }
        TabButton{
            text: qsTr("Ustawienia")
        }
    }

}
