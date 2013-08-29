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
    property real fontSize: 7.5
    property Component textStyle: defaultTextStyle
    property Component backgroundStyle: defaultBackgroundStyle
    style: ButtonStyle {
        id: bstyle
        label: btn.textStyle
        background: btn.backgroundStyle
        padding.top: 3
        padding.bottom: 3
        padding.right: 3
        padding.left: 3
    }
    property Component defaultTextStyle: Text {
        id: styleText
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        text :btn.text
        font.pointSize: btn.fontSize
        fontSizeMode: Text.Fit
        anchors.centerIn: parent
    }
    property Component defaultBackgroundStyle :  Item {
        anchors.margins: 0
        BorderImage {
            anchors.fill: parent
            border.top: 4
            border.bottom: 4
            border.left: 4
            border.right: 4
            anchors.bottomMargin: -1
            source: btn.enabled ? (btn.pressed ? "../icons/buttondown.png" : "../icons/buttonup.png") : "../icons/buttonblocked.png"
        }
    }
}
