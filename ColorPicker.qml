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
    Binding {target: colorViewModel; property: "TypeSelection"; value: colorPickerForm.comboBox.currentIndex}
    rectangle.color: colorViewModel.Hex //hsva(colorViewModel.RH/360, colorViewModel.GS/100, colorViewModel.BV/100, 1)
    hexCodeLabel.text: colorViewModel.Hex
    rhValueLabel.text: colorViewModel.RH
    gsValueLabel.text: colorViewModel.GS
    bvValueLabel.text: colorViewModel.BV
    button.onClicked: {
        console.log("RH=", colorViewModel.RH, "GS=", colorViewModel.GS, "BV=", colorViewModel.BV);
        hexCodeLabel.text = colorViewModel.Hex;
        colorViewModel.SendUnicolor();
    }
    /*Connections{
        target: colorViewModel
    }*/

    Connections
    {
        target: colorViewModel
        /*onHexChanged:{
            colorPickerForm.hexCodeLabel.text = colorViewModel.Hex;
            colorPickerForm.rectangle.color = colorViewModel.Hex;
        }*/

        onTypeSelectionChanged: {
            console.log("Dziolczy");
            var rhv = colorViewModel.RH;
            var gsv = colorViewModel.GS;
            var bvv = colorViewModel.BV;
            console.log(colorViewModel.TypeSelection)
            if(colorPickerForm.comboBox.currentIndex == 0)
            {
                colorPickerForm.rhLabel.text = "H";
                colorPickerForm.gsLabel.text = "S";
                colorPickerForm.bvLabel.text = "V";
                /*colorPickerForm.rhValueLabel.text = rhv;
                colorPickerForm.gsValueLabel.text = gsv;
                colorPickerForm.bvValueLabel.text = bvv;*/
                colorPickerForm.rhSlider.to = 360;
                colorPickerForm.gsSlider.to = 100;
                colorPickerForm.bvSlider.to = 100;
                colorPickerForm.rhSlider.value = rhv;
                colorPickerForm.gsSlider.value = gsv;
                colorPickerForm.bvSlider.value = bvv;
            }
            else if(colorPickerForm.comboBox.currentIndex == 1)
            {
                colorPickerForm.rhLabel.text = "R"
                colorPickerForm.gsLabel.text = "G"
                colorPickerForm.bvLabel.text = "B"
                /*colorPickerForm.rhValueLabel.text = rhv;
                colorPickerForm.gsValueLabel.text = gsv;
                colorPickerForm.bvValueLabel.text = bvv;*/
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
