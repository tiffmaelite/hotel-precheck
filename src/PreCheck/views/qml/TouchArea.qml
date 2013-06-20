#ifndef DOXYGEN_SHOULD_SKIP_THIS

import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0
PinchArea {
    id: area
    signal clicked
    signal doubleClicked
    signal canceled
    signal entered
    signal exited
    signal positionChanged
    signal pressAndHold
    signal pressed
    signal released
    property bool hoverEnabled
    anchors.fill: parent
    MouseArea {
        preventStealing:true
        anchors.fill: parent
        onClicked: area.clicked(mouse);
        onDoubleClicked: area.doubleClicked(mouse);
        onCanceled: area.canceled(mouse);
        onEntered: area.entered(mouse);
        onExited: area.exited(mouse);
        onPositionChanged: area.positionChanged(mouse);
        onPressAndHold: area.pressAndHold(mouse);
        onPressed: area.pressed(mouse);
        onReleased:area.released(mouse);
        onWheel: area.wheel(wheel);
        hoverEnabled: area.hoverEnabled
    }
    onPinchFinished: area.released(pinch);
    onPinchStarted: area.clicked(pinch);
    onPinchUpdated: area.positionChanged(pinch);
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
