import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class SH_RoomsDelegate
  */
SH_DataDelegate {
    id: btn
    text: qsTr("%L1").arg(NUMBER);
    value: NUMBER
    style: ButtonStyle {
        background:
            Item {
            BorderImage {
                anchors.fill: parent
                border.top: 1
                border.bottom: 1
                border.left: 1
                border.right: 1
                anchors.bottomMargin: -1
                property string color: "green"//(AVAILABILITY == '') ? 'blue' : ((AVAILABILITY === '1' || AVAILABILITY === 1) ? "green" : "orange")
                source: btn.pressed ? "../img/button"+color.toUpperCase()+"down.png" : "../img/button"+color.toUpperCase()+"up.png"
            }
        }
    }
}
