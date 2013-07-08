import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_WelcomePage
  */
Item {
    id: welcomePage
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
    }
    ColumnLayout {
        id: column
        anchors.centerIn: welcomePage
        width: parent.width/2
        height: parent.height/2
        spacing: grid.rowSpacing
        RowLayout {
            id: row
            Layout.fillWidth: true
            Layout.fillHeight:  true
            spacing: grid.columnSpacing
            Button {
                id: logoutButton
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: qsTr("Déconnecter")
                onClicked: {
                    welcomePage.logOut();
                }
            }
            Button {
                id: quitButton
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: qsTr("Quitter")
                onClicked: {
                    welcomePage.quit();
                }
            }
        }
        SH_CellFlow {
            id: grid
            Layout.fillWidth: true
            Layout.fillHeight:  true
            flow: GridLayout.LeftToRight
            columns:2
            count: App.currentUser.roles
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
            delegate: "SH_StartMenuButtonDelegate.qml"
            onClicked: welcomePage.clicked()
        }
    }
}
