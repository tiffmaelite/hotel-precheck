import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

FocusScope {
    id:root

    signal pressed

    property bool checked
    property bool up
    property real labelSpacing: 0

    property alias text: txtPart.text

    readonly property string imgUp: "../img/up.png"
    readonly property string imgDown: "../img/down.png"
    readonly property real length: txtPart.paintedWidth+imgPart.paintedWidth
    readonly property real innerHeight: root.height-root.anchors.topMargin-root.anchors.bottomMargin
    readonly property real innerWidth: root.width-root.anchors.rightMargin-root.anchors.leftMargin

    Image {
        id: imgPart
        fillMode: Image.PreserveAspectFit
        width: root.innerHeight
        height: root.innerHeight
        source: root.up ? root.imgUp : root.imgDown
        visible: root.checked
        anchors.left: root.left
        anchors.top: root.top
        anchors.bottom: root.bottom

        //TouchArea {
        MouseArea {
            onClicked: {
                root.pressed();
                root.up = !root.up;
            }
            focus: imgPart.visible
            anchors.fill: imgPart
            hoverEnabled: true
        }
    }

    Text {
        id:txtPart
        visible: true
        height: root.innerHeight
        width: imgPart.visible ? root.innerWidth-imgPart.paintedWidth-root.labelSpacing : root.innerWidth
        anchors.left: imgPart.visible ? imgPart.right : root.left
        anchors.right: root.right
        anchors.top: root.top
        anchors.bottom: root.bottom
        font.strikeout: !root.checked
        wrapMode: Text.Wrap
        //TouchArea {
        MouseArea {
            onClicked: {
                root.pressed();
                root.checked = !root.checked;
            }
            focus: !imgPart.visible
            anchors.fill: txtPart
            hoverEnabled: true
        }
    }
}
