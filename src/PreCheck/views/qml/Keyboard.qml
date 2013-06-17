import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0


GridLayout {
    id: layout
    rowSpacing:0
    columnSpacing:0
    property var actionsList: []
    Repeater {
        id: repeater
        model: (layout.actionsList==null) ? 0 :  layout.actionsList.length
        delegate:
            DataDelegate {
            id: btn
            enabled: layout.enabled
            Layout.minimumHeight: (layout.rows > 0) ? (Math.floor(layout.height / layout.rows) - layout.rowSpacing) : (Math.floor((layout.height * layout.columns) / repeater.count) - layout.rowSpacing)
            Layout.minimumWidth: (layout.columns > 0) ? Math.floor(layout.width / layout.columns) - layout.columnSpacing : Math.floor((layout.width * layout.rows) / repeater.count) - layout.columnSpacing
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: actionsList[index].text
            tooltip: actionsList[index].tooltip
            iconName: actionsList[index].iconName
            iconSource: actionsList[index].iconSource
            checkable: false
            action: Action {
                id: act
                text: actionsList[index].text
                shortcut: actionsList[index].shortcut
                checkable: false
                enabled: actionsList[index].enabled
                iconName: actionsList[index].iconName
                iconSource: actionsList[index].iconSource
                tooltip: actionsList[index].tooltip
                Component.onCompleted: {
                    act.triggered.connect(actionsList[index].triggered);
                }
            }
        }
    }
}
