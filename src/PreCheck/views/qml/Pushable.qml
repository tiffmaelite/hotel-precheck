#ifndef DOXYGEN_SHOULD_SKIP_THIS

import QtQuick 2.0

Rectangle {
    id: pushableItem

    signal pushed
    signal released
    /*signal moved*/

    PinchArea {
        anchors.fill: parent
        onPinchStarted: pushableItem.pushed()
        onPinchFinished: pushableItem.released()
        /*onPinchChanged:*/
        /*onPinchUpdated: pushableItem.moved()*/
    }

    MouseArea {
        anchors.fill: parent
        onClicked: pushableItem.pushed()
        onDoubleClicked: pushableItem.pushed()
        onPressed: pushableItem.pushed()
        onReleased: pushableItem.released
    }
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
