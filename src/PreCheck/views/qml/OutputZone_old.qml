import QtQuick 2.1
import QtQuick.Window 2.0
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Item {
    id: output
    signal display(string text)
    signal selected(string selectedContent)
    function cleanDisplay() {
        content.text = "";
    }

    function addDisplay(text) {
        content.text=content.text+"\n"+text;
    }
    function displayCalendar(b) {
        cal.visible = b;
    }

    Rectangle {
        color: "lightgrey"
        anchors.fill: parent
        ColumnLayout {
            Text {
                id:content
                text:""
                Layout.preferredHeight: content.paintedHeight+2*content.anchors.margins
                Layout.fillWidth: true
                anchors.margins: 25
                font.pointSize: 12
                color: "black"
            }
            CalendarDialog {
                id:cal
                //Layout.minimumWidth: cal.childrenRect.width
                //Layout.minimumHeight: cal.childrenRect.height
                Layout.alignment: Qt.AlignHCenter
                visible:false
                Layout.preferredHeight: 350
                Layout.preferredWidth: 300
                onSelected: {
                    output.display(cal.text+"\n");
                }
            }
        }
    }
    onDisplay: addDisplay(text)
}
