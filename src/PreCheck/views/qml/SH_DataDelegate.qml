import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_DataDelegate
  */
Button {
    id: btn
    property string value: ""
    property int fontSize: 8
    text: ""
    style: ButtonStyle {
        label: Text {
            id: styleText
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.Wrap
            text:btn.text
            font.pointSize: btn.fontSize
        }
        background:
            Item {
            anchors.margins: 0
            BorderImage {
                anchors.fill: parent
                border.top: 3
                border.bottom: 3
                border.left: 3
                border.right: 3
                anchors.bottomMargin: -1
                source: btn.enabled ? (btn.pressed ? "../icons/buttondown.png" : "../icons/buttonup.png") : "../icons/buttonblocked.png"
            }
        }
    }
}
