import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_ConnexionPage
  */
Item {
    id: connexionPage
    signal reload()
    signal checkUsername(string name)
    signal logIn(string login, string password)
    signal loggedIn

    onCheckUsername: {
        if(!App.userExists(name)) {
            errorLabel.text=qsTr("Cet utilisateur n'existe pas");
            errorLabel.visible = true;
            login.textColor="darkred";
        }
    }

    onLogIn: {
        if(App.setUser(login, password)) {
            errorLabel.visible=false;
            errorLabel.text="";
            App.currentMode = AppMode.ACCUEIL;
            connexionPage.loggedIn();
        } else {
            errorLabel.text=qsTr("Le mot de passe entré est incorrect");
            errorLabel.visible = true;
        }
    }

    GridLayout {
        anchors.centerIn: parent
        columns: 2
        columnSpacing: 10
        rowSpacing: 3
        Label {
            id: errorLabel
            visible: false
            color: "red"
            font.pointSize: 14
            Layout.minimumHeight: paintedHeight+2
            Layout.minimumWidth: paintedWidth
            Layout.columnSpan: 2
        }
        Label {
            text: qsTr("Nom d'utilisateur")
            Layout.minimumHeight: paintedHeight
        }
        TextField {
            id: login
            Layout.maximumHeight: 20
            activeFocusOnPress: true
            onAccepted: {
                connexionPage.checkUsername(login.text);
                password.forceActiveFocus();
            }
            onFocusChanged: {
                if(!focus) {
                    accepted();
                } else {
                    textColor="black";
                    errorLabel.text="";
                    errorLabel.visible = false;
                }
            }
            Keys.onPressed: {
                if(event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
                    login.getText(login.length-2,  login.length-1);
                } else if(event.key === Qt.Key_Tab) {
                    password.focus = true;
                    login.focus = false;
                }
            }
        }
        Label {
            text: qsTr("Mot de passe")
            Layout.minimumHeight: paintedHeight
        }
        TextField {
            id:password
            echoMode: TextInput.Password
            activeFocusOnPress: true
            Layout.maximumHeight: 20
            onFocusChanged: {
                if(!focus) {
                    accepted();
                } else {
                    errorLabel.text="";
                    errorLabel.visible = false;
                }
            }
            Keys.onPressed: {
                if(event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
                    password.getText(password.length-2,  password.length-1);
                } else if(event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                    password.focus = false;
                    connexion.clicked();
                }
            }
        }
        Rectangle {
            color: "transparent"
            Layout.minimumHeight: childrenRect.height
            Layout.minimumWidth: childrenRect.width
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Button {
                id: connexion
                text: qsTr("Connexion")
                anchors.centerIn: parent
                width: parent.width
                onClicked: {
                    connexionPage.logIn(login.text, password.text);
                    login.text = "";
                    password.text = "";
                }
            }
        }
    }
}
