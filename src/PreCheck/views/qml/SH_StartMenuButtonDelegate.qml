import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

Button {
    id: button
    enabled: button.checkRole(BUTTONROLE)
    visible:button.checkRole(BUTTONROLE)
    text: qsTr(BUTTONTEXT)
    //property AppMode mode: button.getMode(BUTTONROLE)
    onClicked: App.currentMode = button.getMode(BUTTONROLE)
    function checkRole(c) {
        var table = {reception: App.currentUser.receptionist, administration: App.currentUser.administrator, managementX: App.currentUser.managerX, managementZ: App.currentUser.managerZ}
        return table[c];
    }
    function getMode(c) {
        var table = {reception: AppMode.RECEPTION, administration: AppMode.ADMINISTRATION, managementX: AppMode.MANAGEMENT_X, managementZ: AppMode.MANAGEMENT_Z}
        return table[c];
    }
}
