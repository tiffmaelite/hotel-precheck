import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/**
  @class
  */
Rectangle {
    id: btn
    property string value
    color: "lightblue"
    Text {
        text: qsTr("Étage %L1").arg(btn.value);
        color: "darkblue"
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
    }
}
