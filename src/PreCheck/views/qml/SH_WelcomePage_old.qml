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
                Layout.minimumHeight: Math.floor(grid.height/5)-grid.spacing
                Layout.minimumWidth: Math.floor(grid.width/2)-grid.spacing
                text: qsTr("Déconnecter")
                onClicked: {
                    welcomePage.logOut();
                }
            }
            Button {
                id: quitButton
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.minimumHeight: Math.floor(grid.height/5)-grid.spacing
                Layout.minimumWidth: Math.floor(grid.width/2)-grid.spacing
                text: qsTr("Quitter")
                onClicked: {
                    welcomePage.quit();
                }
            }
        }
        GridLayout {
            id: grid
            Layout.fillWidth: true
            Layout.fillHeight:  true
            flow: GridLayout.LeftToRight
            columns:2
            rowSpacing: 2
            columnSpacing: 2
            property int count: App.currentUser.roles
            Repeater {
                id: repeater
                model: ListModel {
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
                    id: cell
                    color: "transparent"
                    //visible: button.visible
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
                    Button {
                        id: button
                        //visible:button.checkRole(BUTTONROLE)
                        enabled: button.checkRole(BUTTONROLE)
                        /*width: grid.columns > 0 ? Math.floor(grid.width/grid.columns)-grid.columnSpacing : Math.ceil(grid.width*(grid.rows/grid.count))-grid.columnSpacing
                        height: grid.rows > 0 ? Math.floor(grid.height/grid.rows)-grid.rowSpacing : Math.ceil(grid.height*(grid.columns/grid.count))-grid.rowSpacing*/
                        width: Math.floor(grid.width/2)-grid.columnSpacing
                        height: Math.floor(grid.height/2)-grid.rowSpacing
                        anchors.centerIn: cell
                        text: qsTr(BUTTONTEXT)
                        function checkRole(c) {
                            var table = {reception: App.currentUser.receptionist, administration: App.currentUser.administrator, managementX: App.currentUser.managerX, managementZ: App.currentUser.managerZ}
                            return table[c];
                        }
                        function getMode(c) {
                            var table = {reception: AppMode.RECEPTION, administration: AppMode.ADMINISTRATION, managementX: AppMode.MANAGEMENT_X, managementZ: AppMode.MANAGEMENT_Z}
                            return table[c];
                        }
                        onClicked: {
                            App.currentMode = button.getMode(BUTTONROLE);
                            welcomePage.clicked();
                        }
                    }
                }
            }
        }
    }
}
