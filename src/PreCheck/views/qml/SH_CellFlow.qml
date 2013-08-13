import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

GridLayout {
    id: grid
    property int count: model.size
    property alias model: repeater.model
    property string delegate
    rowSpacing: 2
    columnSpacing: 2
    signal clicked()
    Repeater {
        id: repeater
        delegate: Rectangle {
            id: cell
            color: "transparent"
            visible: cellLoader.item.visible
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: childrenRect.width
            Layout.minimumHeight: childrenRect.height
            Layout.columnSpan: computeSpan(true)
            Layout.rowSpan: computeSpan(false)

            function computeSpan(columnAxis) {
                var axisLength = 0;
                if(columnAxis) {
                    if(grid.flow == GridLayout.TopToBottom) {
                        return 1;
                    } else {
                        axisLength = grid.columns;
                    }
                } else {
                    if(grid.flow == GridLayout.LeftToRight) {
                        return 1;
                    } else {
                        axisLength = grid.rows;
                    }
                }
                if(axisLength <= 0) {
                    return 0;
                } else {
                    var remaining = grid.count%axisLength;
                    if((remaining == 0) || (index < grid.count-remaining)) {
                        return 1;
                    } else {
                        return Math.floor(axisLength/remaining);
                    }
                }
            }
            Rectangle {
                id: cellContent
                anchors.centerIn: parent
                width: Math.floor(grid.width/grid.columns)-grid.spacing
                height: Math.floor(grid.height/grid.rows)-grid.spacing
                color: "transparent"
                Loader {
                    source: grid.delegate
                    id:cellLoader
                    Binding {
                        target: cellLoader.item
                        property: "width"
                        value: cellContent.width
                    }
                    Binding {
                        target: cellLoader.item
                        property: "height"
                        value: cellContent.height
                    }
                    Connections {
                        target: cellLoader.item
                        onClicked: {
                            grid.clicked();
                        }
                    }
                }
            }
        }
    }
}
