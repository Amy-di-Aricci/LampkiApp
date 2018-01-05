import QtQuick 2.4
import LampkiAppSwipe.GradientViewModel 1.0

GradientPickerForm {
    GradientViewModel
    {
        id: gradientViewModel
    }
    id: gradientPickerForm
    sendButton.onClicked: {
    gradientViewModel.SendGradient();
    }
    Binding {target: gradientViewModel; property: "RH"; value: gradientPickerForm.rhSlider.value}
    Binding {target: gradientViewModel; property: "GS"; value: gradientPickerForm.gsSlider.value}
    Binding {target: gradientViewModel; property: "BV"; value: gradientPickerForm.bvSlider.value}
    rectangle.color: gradientViewModel.gradientVector[0]
    rectangle1.color: gradientViewModel.gradientVector[1]
    rectangle2.color: gradientViewModel.gradientVector[2]
    rectangle3.color: gradientViewModel.gradientVector[3]
    rectangle4.color: gradientViewModel.gradientVector[4]
    rectangle5.color: gradientViewModel.gradientVector[5]
    rectangle6.color: gradientViewModel.gradientVector[6]
    rectangle7.color: gradientViewModel.gradientVector[7]
}
