import QtQuick 2.0

//le panel de gauche de l'application, appelé dans "app.qml"
//ce panel contient des pages avec onglets et un petit clavier
Rectangle {
    id:leftPanel

    color: "grey"

    //la partie supérieure du panel est remplie par des onglets et leur contenu
    TabView {
        id: tabZone
        width: leftPanel.width
        //height: leftPanel.height/2
        currentIndex: 1
        insertTab();
    }

        //la partie inférieure du panel peut être masquée et elle contient le clavier
        CollapsiblePanel
        {
            id: panel
            width: parent.width
            height: parent.height
            anchors.top: tabZone.bottom
            customModel: collapsibleKeyboard
            customDelegate: myDelegate
            anchors {
                bottom: leftPanel.bottom
            }
        }

        // la zone contenant le clavier
        Component
        {
            id: myDelegate
            Pushable{
                id: myDelegateZone
                width: parent.width
                height: parent.height

                onPushed: {
                    //Qt.quit();
                }
                onRelased: {
                }
                onMoved: {
                }
            }
        }

        //le cavier
        Keyboard {
            id: collapsibleKeyboard
            keys: buttonList
            width: leftPanel.width
            height: leftPanel.height/2
            rows: 5
            columns: 6
            spacing: 1
            anchors {
                bottom: panel.bottom
            }
        }

        //les touches du clavier
        VisualItemModel {
            id: buttonList

            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }        TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }        TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }        TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }        TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
            TouchButton {
                buttonColor: "lightblue"
                buttonText: "0"
            }
        }
    }
