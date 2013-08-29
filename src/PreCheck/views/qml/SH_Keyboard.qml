import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_Keyboard
  */
GridLayout {
    id: layout
    rowSpacing:0
    columnSpacing:0
    property variant actionsList: []
    readonly property int count: layout.actionsList.length
    Repeater {
        id: repeater
        model: (layout.actionsList === []) ? 0 :  layout.count
        delegate:
            SH_DataDelegate {
            id: btn
            enabled: layout.enabled
            property double maxHeight:  repeater.model <= 0 ? 0 : ((layout.flow === GridLayout.TopToBottom) ? Math.floor(layout.height / layout.rows) :  repeater.model <= 0 ? 0  :(Math.floor((layout.height * layout.columns) / repeater.model)))
            property double maxWidth: ((layout.flow === GridLayout.LeftToRight) ? Math.floor(layout.width / layout.columns) : (Math.floor(layout.width * (layout.rows / repeater.model))))
            Layout.maximumHeight: Math.max(0, btn.maxHeight - layout.rowSpacing)
            Layout.maximumWidth: Math.max(0, btn.maxWidth - layout.columnSpacing)
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: actionsList[index].text
            tooltip: actionsList[index].tooltip
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
