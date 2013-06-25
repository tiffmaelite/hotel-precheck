import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/**
  @class
  */
GridLayout {
    id: dataView
    columns: 5
    columnSpacing: 1
    rowSpacing: 1
    property string dataDelegate
    property string emptyDelegate
    property string sectionDelegate
    property variant activeFilterIndicatorIndexes
    property alias sectionIndex : repeater.sectionIndex
    property alias model: repeater.model
    signal selected(string selectedItem)
    Component.onCompleted: {
        dataView.model.fetch();
    }

    /**
      @fn
      @param
      @return

      @brief
      @details
      */
    function removeFilterIndex(index) {
        if(!dataView.activeFilterIndicatorIndexes) {
            dataView.activeFilterIndicatorIndexes = [];
        }
        var tmp = dataView.activeFilterIndicatorIndexes
        var pos = tmp.indexOf(index);
        tmp.splice(pos, 1);
        return tmp;
    }
    /**
      @fn
      @param
      @return

      @brief
      @details
      */
    function addFilterIndex(index) {
        if(!dataView.activeFilterIndicatorIndexes) {
            dataView.activeFilterIndicatorIndexes = [];
        }
        var tmp = dataView.activeFilterIndicatorIndexes
        tmp.push(index);
        return tmp;
    }
    /**
      @fn
      @param
      @return

      @brief
      @details
      */
    function sort(index) {
        repeater.model.setSortKeyKolumn(index);
    }
    /**
      @fn
      @param
      @return

      @brief
      @details
      */
    function filter(index, remove) {
        if(remove) {
            dataView.activeFilterIndicatorIndexes = dataView.addFilterIndex(index);
            repeater.model.setFilterKeyColumn(index);
        } else {
            dataView.activeFilterIndicatorIndexes = dataView.removeFilterIndex(index);
            var nbFilters = dataView.activeFilterIndicatorIndexes.length;
            repeater.model.invalidateFilter(index);
            for(var i = 0; i < nbFilters; i++) {
                repeater.model.setFilterKeyColumn(dataView.activeFilterIndicatorIndexes.at(i));
            }
        }
    }

    Repeater {
        id: repeater
        property bool sectioning: (sectionIndex != 0)
        property int sectionIndex : repeater.model===0 ? 0: repeater.model.sortKeyColumn
        /*property int currentIndex: 0
        property int currentSectionSize: 0
        property int previousSectionSize: 0
        delegate:
            Item {
            Binding {
                target: repeater
                property: "currentIndex"
                value: index
            }
            Item {
                id: filler
                visible: false
                state: (repeater.currentIndex > 0 && repeater.model.data(repeater.currentIndex-1, repeater.sectionIndex) === repeater.model.data(repeater.currentIndex, repeater.sectionIndex)) ? "sameSection": "newSection"
                states: [
                    State {
                        name:"newSection"
                        PropertyChanges {
                            target: filler
                            visible: true
                        }
                    },
                    State {
                        name:"sameSection"
                        PropertyChanges {
                            target: filler
                            visible: false
                        }
                    }
                ]
                onStateChanged: {
                    console.log("\n"+filler.state)
                    if(filler.state == "sameSection") {
                        var previousSize = repeater.currentSectionSize;
                        filler.cols = 0;
                        repeater.currentSectionSize = previousSize+1;
                        repeater.previousSectionSize = previousSize;
                    } else if(filler.state == "newSection") {
                        repeater.previousSectionSize = repeater.currentSectionSize;
                        repeater.currentSectionSize = 1;
                        filler.cols = ((dataView.columns-(repeater.previousSectionSize % dataView.columns)) % dataView.columns);

                        console.log("nouvelle section '" + repeater.model.data(repeater.currentIndex, repeater.sectionIndex)+"'");
                        console.log(filler.cols + "/" + dataView.columns + " colonnes à remplir");
                    }
                    console.log("previous section size: "+repeater.previousSectionSize);
                    console.log("next section size: " +repeater.currentSectionSize);
                }

                Component.onCompleted: {
                    console.log("index : "+repeater.currentIndex);
                    console.log("index in section : "+repeater.currentSectionSize);
                }
                property int cols: 0
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.minimumWidth: cols*(dataView.width / dataView.columns  - dataView.columnSpacing)
                Layout.rowSpan: cols
                ColumnLayout {
                    anchors.fill: parent
                    Repeater {
                        model: (filler.cols > 0) ? filler.cols : 0
                        delegate:
                            Rectangle {
                            id: emptyContainer
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.preferredHeight: (dataView.rows > 0) ? (Math.floor(dataView.height / dataView.rows) - dataView.rowSpacing) : (Math.floor((dataView.height * dataView.columns) / repeater.count) - dataView.rowSpacing)
                            Layout.preferredWidth: (dataView.columns > 0) ? (Math.floor(dataView.width / dataView.columns) - dataView.columnSpacing) : (Math.floor((dataView.width * dataView.rows) / repeater.count) - dataView.columnSpacing)
                            Loader {
                                id: emptyLoader
                                source: dataView.emptyDelegate
                                Binding {
                                    target: emptyLoader.item
                                    property: "anchors.centerIn"
                                    value: emptyContainer
                                }
                                Binding {
                                    target: emptyLoader.item
                                    property: "width"
                                    value: emptyContainer.width - 1
                                }
                                Binding {
                                    target: emptyLoader.item
                                    property: "height"
                                    value: emptyContainer.height - 1
                                }
                                Binding {
                                    target: emptyLoader.item
                                    property: "enabled"
                                    value: false
                                }
                                Binding {
                                    target: emptyLoader.item
                                    property: "visible"
                                    value: true
                                }
                            }
                        }
                    }
                }
                Item {
                    id: section
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.minimumWidth: dataView.width
                    Layout.columnSpan: dataView.columns
                    RowLayout {
                        Rectangle {
                            Layout.minimumHeight: dataView.rowSpacing
                            Layout.maximumHeight: 3*dataView.rowSpacing
                        }
                        Loader {
                            id: sectionLoader
                            source: dataView.sectionDelegate
                            Binding {
                                target: sectionLoader.item
                                property: "value"
                                value: repeater.model.data(repeater.currentIndex, repeater.sectionIndex)
                            }
                        }
                    }
                }
            }*/
        Rectangle {
            id: contentContainer
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumHeight: (dataView.rows > 0) ? (Math.floor(dataView.height / dataView.rows) - dataView.rowSpacing) : (Math.floor((dataView.height * dataView.columns) / repeater.count) - dataView.rowSpacing)
            Layout.maximumWidth: (dataView.columns > 0) ? (Math.floor(dataView.width / dataView.columns) - dataView.columnSpacing) : (Math.floor((dataView.width * dataView.rows) / repeater.count) - dataView.columnSpacing)
            Layout.row: computeRow()
            Layout.column: computeColumn()
            /**
              @fn
              @param
              @return

              @brief
              @details
              */
            function computeRow() {
                var next = 0;
                if(index > 0){
                    var previousRow = repeater.itemAt(index-1).Layout.row;
                    var previousColumn = repeater.itemAt(index-1).Layout.column;
                    console.log("\ncompute row pour l'item  d'id " + (index+1) + " successeur de [" + previousRow + ", " + previousColumn+"]");
                    if(repeater.sectioning && (repeater.model.data(index-1, repeater.sectionIndex) !== repeater.model.data(index, repeater.sectionIndex))) {
                        console.log("nouvelle section "+repeater.model.data(index, repeater.sectionIndex)+" remplaçant "+repeater.model.data(index-1, repeater.sectionIndex));
                        if(dataView.columns > 0) {
                            console.log("layout horizontal de "+dataView.columns+" colonnes non complétées par la section\non va à la ligne");
                            next=previousRow+1;
                        } else {
                            console.log("layout vertical de "+dataView.rows+" lignes\non retourne en première ligne");
                            next = 1;
                        }
                    } else if(repeater.sectioning){
                        console.log("même section");
                        if(dataView.columns > 0) {
                            console.log("layout horizontal de "+dataView.columns+" colonnes");
                            if((previousColumn % dataView.columns) == 0) { /*dernière colonne*/
                                console.log("on passe à la ligne suivante");
                                next = previousRow + 1;
                            } else {
                                console.log("on ne change pas de ligne");
                                next = previousRow;
                            }
                        } else{
                            console.log("layout vertical de "+dataView.rows+" lignes\non passe à la ligne suivante (ou on boucle)");
                            next = previousRow % dataView.rows + 1;
                        }
                    } else {
                        if(dataView.rows > 0) {
                            next = index % dataView.rows + 1;
                        } else {
                            next = Math.floor(index / dataView.columns) + 1;
                        }
                    }
                } else {
                    next = 1;
                }

                console.log("ligne "+next)
                return next;
            }
            /**
              @fn
              @param
              @return

              @brief
              @details
              */
            function computeColumn() {
                var next = 0;
                if(index > 0){
                    var previousRow = repeater.itemAt(index-1).Layout.row;
                    var previousColumn = repeater.itemAt(index-1).Layout.column;
                    console.log("\ncompute column pour l'item d'id " + (index+1) + " successeur de [" + previousRow + ", " + previousColumn+"]");
                    if(repeater.sectioning && (repeater.model.data(index-1, repeater.sectionIndex) !== repeater.model.data(index, repeater.sectionIndex))) {
                        console.log("nouvelle section "+repeater.model.data(index, repeater.sectionIndex)+" remplaçant "+repeater.model.data(index-1, repeater.sectionIndex));
                        if(dataView.columns > 0) {
                            console.log("layout horizontal de "+dataView.columns+" colonnes\non retourne à la première colonne");
                            next = 1;
                        } else {
                            console.log("layout vertical de "+dataView.rows+" lignes non complétées par la section\non va à la colonne suivante");
                            next = previousColumn+1;
                        }
                    } else if(repeater.sectioning){
                        console.log("même section");
                        if(dataView.rows > 0) {
                            console.log("layout vertical de "+dataView.rows+" lignes");
                            if((previousRow % dataView.rows) == 0) { /*dernière ligne*/
                                console.log("on passe à la colonne suivante");
                                next = previousColumn + 1;
                            } else {
                                console.log("on ne change pas de colonne");
                                next = previousColumn;
                            }
                        } else{
                            console.log("layout horizontal de "+dataView.columns+" colonnes\non passe à la colonne suivante (ou on boucle) ");
                            next = previousColumn % dataView.columns + 1;
                        }
                    } else {
                        if(dataView.columns > 0) {
                            next= index % dataView.columns + 1;
                        } else {
                            next= Math.floor(index / dataView.rows) + 1;
                        }
                    }
                } else {
                    next = 1;
                }

                console.log("colonne "+next)
                return next;
            }

            Loader {
                id:contentLoader
                source: dataView.dataDelegate
                Binding {
                    target: contentLoader.item
                    property: "width"
                    value: contentContainer.width - 1
                }
                Binding {
                    target: contentLoader.item
                    property: "height"
                    value: contentContainer.height - 2
                }
                Connections {
                    target: contentLoader.item
                    onClicked: {
                        if(dataView.enabled) {
                            dataView.selected(contentLoader.item.value);
                        }
                    }
                }
            }
        }
        /*}*/
    }
}
