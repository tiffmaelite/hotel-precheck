import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0


GridLayout {
    id: servicesList
    property var model
    property string delegateSource
    Component.onCompleted: if(model!==0 && model.empty) {model.fetch(); }
    signal selected(string selectedItem)
    Repeater {
        id: servicesRep
        model: servicesList.model
        delegate:
            Loader {
            id: servicesContentLoader
            source: delegateSource
            Connections {
                target: servicesContentLoader.item
                onClicked: {
                    servicesList.selected(servicesContentLoader.item.value);
                }
            }
        }
    }
}
