import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class SH_app
  \brief \~french fenêtre principale de l'application qui contient tous les éléments de design de l'application
*/
ApplicationWindow {
    id: window
    visibility: Window.Windowed
    /*maximumHeight: 600
    maximumWidth: 800*/
    height: maximumHeight
    width: maximumWidth
    title: qsTr("Réception")
    color: App.readStringSetting("backgroundColor","globalGUI")
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
        status.text = Qt.binding(function() {return ((App.currentMode === AppMode.CONNEXION) ? qsTr("Connexion") : (App.currentUser.valid ? qsTr("Connecté comme %1").arg(App.currentUser.name) : qsTr("Non connecté")));});
    }
    Component.onCompleted: {
        window.reload();
    }
    StackView {
        id: stack
        signal cycle(Item previous, Item next)
        anchors.fill: parent
        Component.onCompleted: {
            stack.clear();
            stack.push([commonPage, welcomePage, connexionPage]);
            /*commonPage.focus = false;
            commonPage.visible = false;
            welcomePage.focus = false;
            welcomePage.visible = false;*/
        }
        onCycle: {
            previous.focus = false;
            previous.visible = false;
            window.reload();
            next.focus = true;
            next.visible = true;
            next.forceActiveFocus();
            next.width = stack.width;
            next.height = stack.height;
            next.anchors.centerIn = stack;
            stack.push({item: stack.get(next.Stack.index)});
            next.reload();
        }
        delegate: StackViewDelegate {
            function getTransition(properties)
            {
                return fading;
            }

            property Component fading: StackViewTransition {
                PropertyAnimation {
                    target: exitItem
                    property: "opacity"
                    from: 100
                    to: 0
                    duration: 100
                }
                PropertyAnimation {
                    target: exitItem
                    property: "visible"
                    from: true
                    to: false
                    duration: 0
                }
                PropertyAnimation {
                    target: exitItem
                    property: "focus"
                    from: true
                    to: false
                    duration: 0
                }
                PropertyAnimation {
                    target: enterItem
                    property: "opacity"
                    from: 0
                    to: 100
                    duration: 600
                }
                PropertyAnimation {
                    target: enterItem
                    property: "visible"
                    from: false
                    to: true
                    duration: 0
                }
                PropertyAnimation {
                    target: enterItem
                    property: "focus"
                    from: false
                    to: true
                    duration: 0
                }
            }
        }
    }
    SH_ConnexionPage {
        id: connexionPage
        objectName: "Connexion"
        focus: true
        visible: true
        onLoggedIn: {
            stack.cycle(connexionPage,welcomePage);
        }
    }
    SH_WelcomePage {
        id:welcomePage
        objectName: "Welcome"
        focus: false
        visible: false
        onQuit: {
            Qt.quit();
        }
        onClicked : {
            stack.cycle(welcomePage,commonPage);
        }
        onLoggedOut: {
            stack.cycle(welcomePage,connexionPage);
        }
    }
    SH_CommonPage {
        id: commonPage
        objectName: "Common"
        focus: false
        visible: false
        onQuit: {
            stack.cycle(commonPage,welcomePage);
        }
    }
}
