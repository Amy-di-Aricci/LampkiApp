import QtQuick 2.4
import LampkiAppSwipe.GradientViewModel 1.0

GradientPickerForm {
    GradientViewModel
    {
        id: gradientViewModel
    }
    id: gradientPickerForm
    Binding {target: gradientViewModel; property: "RH"; value: gradientPickerForm.rhSlider.value}
    Binding {target: gradientViewModel; property: "GS"; value: gradientPickerForm.gsSlider.value}
    Binding {target: gradientViewModel; property: "BV"; value: gradientPickerForm.bvSlider.value}
    rectangle.color: gradientViewModel.gradientVector[0]
    rectangle1.color: gradientViewModel.gradientVector[1]
}
