import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import PreCheck 1.0

ComplexGridView {
    id: dataView
    property string dataDelegate
    property variant activeFilterIndicatorIndexes
    // maxi 10 lignes s'il y a 6 colonnes; et maxi 15 lignes s'il y a 12 colonnes; sinon 18 toutes petites colonnes et autant de lignes que nécessaire
    maxNbRowsFew: 10
    maxNbColsFew: 6
    maxNbRowsStd: 15
    maxNbColsStd: 12
    maxNbFlowMany: 18
    function removeFilterIndex(index) {
        if(!activeFilterIndicatorIndexes) {
            activeFilterIndicatorIndexes = [];
        }

        var tmp = activeFilterIndicatorIndexes
        var pos = tmp.indexOf(index);
        tmp.splice(pos, 1);
        return tmp;
    }

    function addFilterIndex(index) {
        if(!activeFilterIndicatorIndexes) {
            activeFilterIndicatorIndexes = [];
        }
        var tmp = activeFilterIndicatorIndexes
        tmp.push(index);
        return tmp;
    }
    function sort(index) {
        dataView.model.sort(index);
    }
    function filter(index, remove) {
        if(remove) {
            activeFilterIndicatorIndexes = addFilterIndex(index);
            dataView.model.setFilterKeyColumn(index);
        } else {
            activeFilterIndicatorIndexes = removeFilterIndex(index);
            var nbFilters = activeFilterIndicatorIndexes.length;
            dataView.model.invalidateFilter(index);
            for(var i = 0; i < nbFilters; i++) {
                dataView.model.setFilterKeyColumn(activeFilterIndicatorIndexes.at(i));
            }
        }
    }
    delegate: Loader {
        id:contentLoader
        source: dataDelegate

        Binding {
            target: contentLoader.item
            property: "visible"
            value: dataView.enabled
        }
        Binding {
            target: contentLoader.item
            property: "width"
            value: dataView.cellWidth-dataView.cellSpacing
        }
        Binding {
            target: contentLoader.item
            property: "heigth"
            value: dataView.cellHeight-dataView.cellSpacing
        }
        Connections {
            target: contentLoader.item
            onClicked: {
                if(dataView.enabled) {
                    dataView.selected(contentLoader.item.value);
                    dataView.currentIndex = index;
                }
            }
        }
    }
}
