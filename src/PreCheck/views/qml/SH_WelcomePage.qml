import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_WelcomePage
  */
Rectangle {
    id: welcomePage
    color: "green"
    signal logOut()
    signal loggedOut()
    signal quit()
    signal clicked()
    signal reload()
    onLogOut: {
        if(App.userLogOut()) {
            welcomePage.loggedOut();
        }
    }
    onReload: {
        grid.anchors.centerIn = welcomePage;
        /*receptionButton.visible = App.currentUser.receptionist;
        administrationButton.visible = App.currentUser.administrator;
        managementXButton.visible = App.currentUser.managerX;
        managementZButton.visible = App.currentUser.managerZ;*/
    }

    GridLayout {
        id: grid
        anchors.centerIn: parent //welcomePage
        width: parent.width / 3 // welcomePage.width / 3
        height: parent.height / 3 // welcomePage.height / 3
        flow: GridLayout.LeftToRight
        columns:2
        visible: welcomePage.visible
        property int count: App.currentUser.roles
        RowLayout {
            Layout.rowSpan: grid.columns
            Layout.minimumHeight: childrenRect.height
            Layout.minimumWidth: childrenRect.width
            Layout.fillHeight: true
            Layout.fillWidth: true
            Button {
                id: logoutButton
                height: (grid.height%2)-grid.spacing
                width: (grid.width/2)-grid.spacing
                text: qsTr("Déconnecter")
                onClicked: {
                    welcomePage.logOut();
                }
            }
            Button {
                id: quitButton
                height: (grid.height%2)-grid.spacing
                width: (grid.width/2)-grid.spacing
                text: qsTr("Quitter")
                onClicked: {
                    welcomePage.quit();
                }
            }
        }
        function getRole(c) {
            var table = {reception: App.currentUser.receptionist, administration: App.currentUser.administrator, managementX: App.currentUser.managerX, managementZ: App.currentUser.managerZ}
            return table[c];
        }
        function getMode(c) {
            var table = {reception: AppMode.RECEPTION, administration: AppMode.ADMINISTRATION, managementX: AppMode.MANAGEMENT_X, managementZ: AppMode.MANAGEMENT_Z}
            return table[c];
        }

        Repeater {
            model:  ListModel {
                id: buttonsList
                ListElement {
                    BUTTONROLE: "reception"
                    BUTTONTEXT: QT_TR_NOOP("Réception")
                }
                ListElement {
                    BUTTONROLE: "administration"
                    BUTTONTEXT: QT_TR_NOOP("Administration")
                }
                ListElement {
                    BUTTONROLE: "managementX"
                    BUTTONTEXT: QT_TR_NOOP("Gestion lecture")
                }
                ListElement {
                    BUTTONROLE: "managementZ"
                    BUTTONTEXT: QT_TR_NOOP("Gestion lecture et écriture/exécution")
                }
            }
            delegate: Rectangle {
                visible: true
                color: "red"//"transparent"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.minimumHeight: childrenRect.height
                Layout.minimumWidth: childrenRect.width
                Layout.columnSpan: computeSpan(true)
                Layout.rowSpan: computeSpan(false)
                function computeSpan(columnAxis) {
                    var axisLength = 0;
                    if(columnAxis) {
                        if(grid.flow == GridLayout.TopToBottom) {
                            return 1;
                        } else {
                            axisLength = grid.columns;
                        }
                    } else {
                        if(grid.flow == GridLayout.LeftToRight) {
                            return 1;
                        } else {
                            axisLength = grid.rows;
                        }
                    }
                    if(axisLength <= 0) {
                        return 0;
                    } else {
                        var remaining = grid.count%axisLength;
                        if((remaining == 0) || (index < grid.count-remaining)) {
                            return 1;
                        } else {
                            return Math.floor(axisLength/remaining);
                        }
                    }
                }
                anchors.centerIn: parent
                Button {
                    id: button
                    height: (grid.height/2)-grid.spacing
                    width: (grid.width/2)-grid.spacing
                    anchors.centerIn: parent
                    visible: true //grid.getRole(BUTTONROLE)
                    enabled: true //grid.getRole(BUTTONROLE)
                    text: qsTr(BUTTONTEXT)
                    onClicked: {
                        App.currentMode = grid.getMode(BUTTONROLE);
                        welcomePage.clicked();
                    }
                    /*Binding {
                    target: button
                    property: "visible"
                    value: grid.getRole(BUTTONROLE)
                }
                Binding {
                    target: button
                    property: "enabled"
                    value: grid.getRole(BUTTONROLE)
                }*/
                }
            }
        }
    }
}
