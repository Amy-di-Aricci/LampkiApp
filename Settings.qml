import QtQuick 2.4
import LampkiAppSwipe.SettingsViewModel 1.0
import Qt.labs.settings 1.0

SettingsForm {
    id: settingsForm
    button.onClicked: {
        console.log("IP: ", settingsViewModel.Url);
        console.log("PORT: ", settingsViewModel.Port);
        settingsViewModel.setSettings();

    }
    SettingsViewModel{
        id: settingsViewModel
    }

    Binding {target: settingsViewModel; property:"Port"; value: settingsForm.portTextField1.text}
    ipTextField.onTextChanged:
    {
        if(settingsForm.ipTextField.acceptableInput)
        {
            settingsForm.ipTextField.color = "#ffffff";
            settingsForm.button.enabled = true;
            settingsViewModel.Url = settingsForm.ipTextField.text;
        }
        else
        {
            settingsForm.ipTextField.color = "#ff0000";
            settingsForm.button.enabled = false;
        }
    }
    ipTextField.text: settingsViewModel.getUrlFromSettings()
    portTextField1.text: settingsViewModel.getPortFromSettings()
}
