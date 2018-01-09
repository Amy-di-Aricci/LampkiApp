import QtQuick 2.4
import LampkiAppSwipe.ColorViewModel 1.0

ColorPickerForm {
    ColorViewModel {
        id: colorViewModel
    }

    id: colorPickerForm
    Binding {target: colorViewModel; property: "RH"; value: colorPickerForm.rhSlider.value}
    Binding {target: colorViewModel; property: "GS"; value: colorPickerForm.gsSlider.value}
    Binding {target: colorViewModel; property: "BV"; value: colorPickerForm.bvSlider.value}
    Binding {target: colorViewModel; property: "SelectedType"; value: colorPickerForm.comboBox.currentIndex}
    rectangle.color: colorViewModel.Hex
    hexCodeLabel.text: colorViewModel.Hex
    rhValueLabel.text: colorViewModel.RH
    gsValueLabel.text: colorViewModel.GS
    bvValueLabel.text: colorViewModel.BV
    button.onClicked: {
        console.log("RH=", colorViewModel.RH, "GS=", colorViewModel.GS, "BV=", colorViewModel.BV);
        hexCodeLabel.text = colorViewModel.Hex;
        colorViewModel.SendUnicolor();
    }

    Connections
    {
        target: colorViewModel

        onSelectedTypeChanged: {
            console.log("Dziolczy");
            var rhv = colorViewModel.RH;
            var gsv = colorViewModel.GS;
            var bvv = colorViewModel.BV;
            console.log(colorViewModel.SelectedType)
            if(colorPickerForm.comboBox.currentIndex == 0)
            {
                colorPickerForm.rhLabel.text = "Barwa";
                colorPickerForm.gsLabel.text = "Nasycenie";
                colorPickerForm.bvLabel.text = "Jasność";
                colorPickerForm.rhSlider.to = 360;
                colorPickerForm.gsSlider.to = 100;
                colorPickerForm.bvSlider.to = 100;
                colorPickerForm.rhSlider.value = rhv;
                colorPickerForm.gsSlider.value = gsv;
                colorPickerForm.bvSlider.value = bvv;
            }
            else if(colorPickerForm.comboBox.currentIndex == 1)
            {
                colorPickerForm.rhLabel.text = "Czerwony"
                colorPickerForm.gsLabel.text = "Zielony"
                colorPickerForm.bvLabel.text = "Niebieski"
                colorPickerForm.rhSlider.to = 255;
                colorPickerForm.gsSlider.to = 255;
                colorPickerForm.bvSlider.to = 255;
                colorPickerForm.rhSlider.value = rhv;
                colorPickerForm.gsSlider.value = gsv;
                colorPickerForm.bvSlider.value = bvv;
            }
        }
    }

}
