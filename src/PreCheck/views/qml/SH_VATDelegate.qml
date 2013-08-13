import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_VATDelegate
  */
DelegateModel {
    model: SH_VATModel { }
    Component.onCompleted: {
        if(model.empty) {
            model.fetch();
        }
    }
    delegate: SH_DataDelegate {
        id: btn
        value: PERCENTAGE
        text: LABEL
        style: ButtonStyle {
            background:
                Item {
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
}
