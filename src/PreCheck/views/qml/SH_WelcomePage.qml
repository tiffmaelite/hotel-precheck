import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Item {
    id: welcomePage
    signal logOut()
    signal loggedOut()
    signal quit()
    signal clicked()
    signal reload()
    onLogOut: {
        if(SH_App.userLogOut()) {
            welcomePage.loggedOut();
        }
    }
    onReload: {
        buttons.anchors.centerIn = welcomePage;
        receptionButton.visible = SH_App.currentUser.receptionist;
        administrationButton.visible = SH_App.currentUser.administrator;
        managementXButton.visible = SH_App.currentUser.managerX;
        managementZButton.visible = SH_App.currentUser.managerZ;
    }

    ColumnLayout {
        id: buttons
        anchors.centerIn: welcomePage
        width: parent.width / 2
        height: parent.height / 2
        spacing: 5
        RowLayout {
            Button {
                id: logoutButton
                height: (buttons.height%2)-buttons.spacing
                width: (buttons.width/2)-buttons.spacing
                text: qsTr("Déconnecter")
                onClicked: {
                    welcomePage.logOut();
                }
            }
            Button {
                id: quitBUtton
                height: (buttons.height%2)-buttons.spacing
                width: (buttons.width/2)-buttons.spacing
                text: qsTr("Quitter")
                onClicked: {
                    welcomePage.quit();
                }
            }
        }
        GridLayout {
            id: grid
            columns: 2
            property int count: SH_App.currentUser.roles
            Rectangle {
                color: "transparent"
                Layout.minimumHeight: childrenRect.height
                Layout.minimumWidth: childrenRect.width
                Layout.columnSpan: (grid.count%grid.columns == 0 || Layout.row <= grid.count/grid.columns) ? 1 : grid.columns-Layout.column
                Button {
                    id: receptionButton
                    anchors.centerIn: parent
                    height: (buttons.height/2)-buttons.spacing
                    width: (buttons.width/2)-buttons.spacing
                    text: qsTr("Réception")
                    visible: SH_App.currentUser.receptionist
                    onClicked: {
                        SH_App.currentMode = SH_AppMode.RECEPTION;
                        welcomePage.clicked();
                    }
                }
            }
            Rectangle {
                color: "transparent"
                Layout.minimumHeight: childrenRect.height
                Layout.minimumWidth: childrenRect.width
                Layout.columnSpan: (grid.count%grid.columns == 0 || Layout.row <= grid.count/grid.columns) ? 1 : grid.columns-Layout.column
                Button {
                    id: administrationButton
                    height: (buttons.height/2)-buttons.spacing
                    width: (buttons.width/2)-buttons.spacing
                    text: qsTr("Administration")
                    visible: SH_App.currentUser.administrator
                    onClicked: {
                        SH_App.currentMode = SH_AppMode.ADMINISTRATION;
                        welcomePage.clicked();
                    }
                }
            }
            Rectangle {
                color: "transparent"
                Layout.minimumHeight: childrenRect.height
                Layout.minimumWidth: childrenRect.width
                Layout.columnSpan: (grid.count%grid.columns == 0 || Layout.row <= grid.count/grid.columns) ? 1 : grid.columns-Layout.column
                Button {
                    id: managementXButton
                    height: (buttons.height/2)-buttons.spacing
                    width: (buttons.width/2)-buttons.spacing
                    text: qsTr("Gestion lecture")
                    visible: SH_App.currentUser.managerX
                    onClicked: {
                        SH_App.currentMode = SH_AppMode.MANAGEMENT_X;
                        welcomePage.clicked();
                    }
                }
            }
            Rectangle {
                color: "transparent"
                Layout.minimumHeight: childrenRect.height
                Layout.minimumWidth: childrenRect.width
                Layout.columnSpan: (grid.count%grid.columns == 0 || Layout.row <= grid.count/grid.columns) ? 1 : grid.columns-Layout.column
                Button {
                    id: managementZButton
                    height: (buttons.height/2)-buttons.spacing
                    width: (buttons.width/2)-buttons.spacing
                    text: qsTr("Gestion lecture écriture")
                    visible: SH_App.currentUser.managerZ
                    onClicked: {
                        SH_App.currentMode = SH_AppMode.MANAGEMENT_Z;
                        welcomePage.clicked();
                    }
                }
            }
        }
    }
}
