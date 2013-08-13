import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_HeaderView
  */
GridLayout {
    id: filterGrid
    property variant delegateModel
    property alias model: repeater.model

    /*maxi 2 lignes s'il y a 4 colonnes; et maxi 3 lignes s'il y a 6 colonnes; sinon 10 toutes petites colonnes et autant de lignes que nécessaire*/
    /*maxNbRowsFew: 2
    maxNbColsFew: 4
    maxNbRowsStd: 3
    maxNbColsStd: 6
    maxNbFlowMany: 10*/
    columns: 4
    signal up(int index)
    signal checked(int index, bool ch)
    Repeater {
        id:repeater
        delegate:
            Item {
            visible: filterGrid.visible
            enabled: filterGrid.enabled
            Layout.fillWidth: true
            Layout.fillHeight: true
            SH_TriStateCheckImage {
                id: cbx
                property variant dataModel
                enabled: filterGrid.enabled
                anchors.fill: parent
                Component.onCompleted: {
                    dataModel = Qt.binding(function() {return filterGrid.delegateModel.field(index);});
                    text = Qt.binding(function() {return dataModel.text;});
                }
                onUpChanged: {
                    if(cbx.up) {
                        dataModel.sortOrder = Qt.AscendingOrder;
                    } else {
                        dataModel.sortOrder = Qt.DescendingOrder
                    }
                    filterGrid.up(index);
                }

                onCheckedChanged: {
                    filterGrid.checked(index, !cbx.checked);
                }
                onPressed: {
                    filterGrid.currentIndex = index
                }
            }
        }

    }
}
