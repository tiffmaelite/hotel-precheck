import QtQuick 2.1
import QtQml 2.0
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class SH_RoomsDelegate
  */
//SH_DataModelDelegate {
SH_DataDelegate {
    id: btn
    //model: SH_RoomsModel { }
    text: qsTr("%L1").arg(NUMBER);
    value: NUMBER
    backgroundStyle:
        Item {
        BorderImage {
            anchors.fill: parent
            border.top: 1
            border.bottom: 1
            border.left: 1
            border.right: 1
            anchors.bottomMargin: -1
            property string color: ISCLEANED === Qt.Unchecked ? 'blue' : (ISAVAILABLE === Qt.Checked ? "green" : "orange")
            source: btn.pressed ? "../icons/button"+color.toUpperCase()+"down.png" : "../icons/button"+color.toUpperCase()+"up.png"
        }
    }
}
