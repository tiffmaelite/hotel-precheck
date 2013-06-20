import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Item {
    id: SH_ConnexionPage
    signal reload()
    signal checkUsername(string name)
    signal logIn(string login, string password)
    signal loggedIn

    onCheckUsername: {
        if(!SH_App.userExists(name)) {
            errorLabel.text=qsTr("Cet utilisateur n'existe pas");
            errorLabel.visible = true;
            login.textColor="darkred";
        }
    }

    onLogIn: {
        if(SH_App.setUser(login, password)) {
            errorLabel.visible=false;
            errorLabel.text="";
            SH_App.currentMode = SH_AppMode.ACCUEIL;
            SH_ConnexionPage.loggedIn();
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
            font.pointSize: 15
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
            activeFocusOnPress: true
            onAccepted: {
                SH_ConnexionPage.checkUsername(login.text);
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

            Layout.maximumHeight: 20
        }
        Label {
            text: qsTr("Mot de passe")
            Layout.minimumHeight: paintedHeight
        }
        TextField {
            id:password
            echoMode: TextInput.Password

            Layout.maximumHeight: 20
            onFocusChanged: {
                if(!focus) {
                    accepted();
                } else {
                    errorLabel.text="";
                    errorLabel.visible = false;
                }
            }
        }
        Button {
            text: qsTr("Connexion")
            Layout.minimumHeight: childrenRect.height
            Layout.minimumWidth: childrenRect.width
            Layout.columnSpan: 2
            onClicked: {
                SH_ConnexionPage.logIn(login.text, password.text);
                login.text = "";
                password.text = "";
            }
        }
    }
}
