import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0


ColumnLayout {
    id: vatSidePanel
    property var model
    property string delegateSource
    Component.onCompleted: if(model!==0 && model.empty) {model.fetch(); }
    signal selected(string selectedItem)
    Repeater {
        id: vatRep
        model: vatSidePanel.model
        delegate:
            Loader {
            id: contentLoader
            source: delegateSource
            Connections {
                target: contentLoader.item
                onClicked: {
                    vatSidePanel.selected(contentLoader.item.value);
                }
            }
        }
    }
}
