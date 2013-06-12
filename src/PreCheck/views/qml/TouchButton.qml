import QtQuick 2.0


Pushable {
    id: button

    property color buttonColor
    property string buttonText

    radius: 4
    smooth:true

    gradient: Gradient {
        GradientStop { position: 0.0; color: buttonColor }
        GradientStop { position: 1.0; color: "#ffffff" }
    }
    opacity: 0
    Text {
        id: buttonLabel
        text: parent.buttonText
        anchors.centerIn: parent
    }
    onPushed: {
        //Qt.quit();
        console.log("choix de " + buttonText);
    }
    onRelased: {
        console.log("choix annulé de " + buttonText);
    }
    onMoved: {
        console.log("mouvement de " + buttonText);
    }

}
