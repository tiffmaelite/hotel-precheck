import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_DataDelegate
  */
Button {
    id: btn
    text: ""
    property string value: ""
    property int fontSize: 8
    property Component textStyle: defaultTextStyle
    property Component backgroundStyle: defaultBackgroundStyle
    style: ButtonStyle {
        label: btn.textStyle
        background: btn.backgroundStyle
    }
    property Component defaultTextStyle: Text {
        id: styleText
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        text:btn.text
        font.pointSize: btn.fontSize
    }
    property Component defaultBackgroundStyle :  Item {
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
