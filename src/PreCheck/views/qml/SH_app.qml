import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

//fenêtre principale de l'application qui contient tous les éléments de design de l'application
ApplicationWindow {
    id: window
    visibility: Window.Windowed
    //maximumHeight: 600
    //maximumWidth: 800
    height: maximumHeight
    width: maximumWidth
    title: "Réception"
    property alias pages: stack
    signal reload()
    statusBar: StatusBar {
        Label {
            id: status
            text: ""
            anchors.centerIn: parent
        }
    }
    onReload: {
        status.text = Qt.binding(function() {return ((SH_App.currentMode === SH_AppMode.CONNEXION) ? qsTr("Connexion") : (SH_App.currentUser.valid ? SH_App.currentUser.name : ""));});
    }
    Component.onCompleted: {
        window.reload();
    }

    StackView {
        id: stack
        signal cycle(Item c)
        anchors.fill: parent
        Component.onCompleted: {
            stack.push({item: SH_CommonPage, immediate:true});
            stack.push({item: welcomePage, immediate: true});
            stack.push({item: SH_ConnexionPage, immediate: true});
        }
        onCycle: {
            window.reload();
            c.reload();
            stack.push({item: stack.get(c.Stack.index)});
        }
        delegate: StackViewDelegate {
            function getTransition(properties)
            {
                //return (properties.enterItem.Stack.index % 2) ? fading : bouncing
                return fading;
            }

            property Component fading: StackViewTransition {
                PropertyAnimation {
                    target: exitItem
                    property: "opacity"
                    from: 100
                    to: 0
                    duration: 50
                }
                PropertyAnimation {
                    target: enterItem
                    property: "opacity"
                    from: 0
                    to: 100
                    duration: 600
                }
            }
        }
    }
    SH_WelcomePage {
        id:welcomePage
        objectName: "Welcome"
        onQuit: {
            Qt.quit();
        }
        onClicked : {
            stack.cycle(SH_CommonPage);
        }
        onLoggedOut: {
            stack.cycle(SH_ConnexionPage);
        }
    }
    SH_ConnexionPage {
        id: SH_ConnexionPage
        objectName: "Connexion"
        onLoggedIn: {
            stack.cycle(welcomePage);
        }
    }

    SH_CommonPage {
        id: SH_CommonPage
        objectName: "Common"
        onQuit: {
            stack.cycle(welcomePage);
        }
    }
}
