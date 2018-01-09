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
    Binding {target: gradientViewModel; property: "selectedType"; value: gradientPickerForm.comboBox.currentIndex}
    rhValueLabel.text: gradientViewModel.RH
    gsValueLabel.text: gradientViewModel.GS
    bvValueLabel.text: gradientViewModel.BV
    rectangle.color: gradientViewModel.gradientVector[0]
    rectangle1.color: gradientViewModel.gradientVector[1]
    rectangle2.color: gradientViewModel.gradientVector[2]
    rectangle3.color: gradientViewModel.gradientVector[3]
    rectangle4.color: gradientViewModel.gradientVector[4]
    rectangle5.color: gradientViewModel.gradientVector[5]
    rectangle6.color: gradientViewModel.gradientVector[6]
    rectangle7.color: gradientViewModel.gradientVector[7]

    lastColorButton.onClicked: {
        gradientPickerForm.rectangle7.border.width = 2;
        gradientPickerForm.rectangle.border.width = 0;
        gradientViewModel.selectedDiode = 1;
        gradientPickerForm.rhSlider.value = gradientViewModel.RH;
        gradientPickerForm.gsSlider.value = gradientViewModel.GS;
        gradientPickerForm.bvSlider.value = gradientViewModel.BV;
    }
    firstColorButton.onClicked: {
        gradientPickerForm.rectangle.border.width = 2;
        gradientPickerForm.rectangle7.border.width = 0;
        gradientViewModel.selectedDiode = 0;
        gradientPickerForm.rhSlider.value = gradientViewModel.RH;
        gradientPickerForm.gsSlider.value = gradientViewModel.GS;
        gradientPickerForm.bvSlider.value = gradientViewModel.BV;
    }

    Connections
    {
        target: gradientViewModel

        onSelectedTypeChanged:
        {
            var rhv = gradientViewModel.RH;
            var gsv = gradientViewModel.GS;
            var bvv = gradientViewModel.BV;
            if(gradientPickerForm.comboBox.currentIndex == 0)
            {
                gradientPickerForm.rhLabel.text = "Barwa";
                gradientPickerForm.gsLabel.text = "Nasycenie";
                gradientPickerForm.bvLabel.text = "Jasność";
                gradientPickerForm.rhSlider.to = 360;
                gradientPickerForm.gsSlider.to = 100;
                gradientPickerForm.bvSlider.to = 100;
                gradientPickerForm.rhSlider.value = rhv;
                gradientPickerForm.gsSlider.value = gsv;
                gradientPickerForm.bvSlider.value = bvv;
            }
            else if(gradientPickerForm.comboBox.currentIndex == 1)
            {
                gradientPickerForm.rhLabel.text = "Czerwony";
                gradientPickerForm.gsLabel.text = "Zielony";
                gradientPickerForm.bvLabel.text = "Niebieski";
                gradientPickerForm.rhSlider.to = 255;
                gradientPickerForm.gsSlider.to = 255;
                gradientPickerForm.bvSlider.to = 255;
                gradientPickerForm.rhSlider.value = rhv;
                gradientPickerForm.gsSlider.value = gsv;
                gradientPickerForm.bvSlider.value = bvv;
            }
        }
    }

    sendButton.onClicked: {
        gradientViewModel.SendGradient();
    }
}
