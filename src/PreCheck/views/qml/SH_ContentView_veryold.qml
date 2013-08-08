import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_ContentView
  */
GridLayout {
    id: dataView
    columns: Math.max(5, dataView.maxColumns)
    columnSpacing: 1
    rowSpacing: 1
    property int maxColumns: 5
    property string itemDelegate
    property string emptyDelegate
    property string sectionDelegate
    property variant activeFilterIndicatorIndexes
    property alias sectionIndex : repeater.sectionIndex
    property alias model: repeater.model
    signal selected(string selectedItem)
    Component.onCompleted: {
        dataView.model.fetch();
    }

    Repeater {
        id: repeater
        property bool sectioning: (sectionIndex != 0)
        property int sectionIndex : repeater.model===0 ? 0: repeater.model.sortKeyColumn
        Rectangle {
            id: contentContainer
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumHeight: (dataView.rows > 0) ? (Math.floor(dataView.height / dataView.rows) - dataView.rowSpacing) : (Math.floor((dataView.height * dataView.columns) / repeater.count) - dataView.rowSpacing)
            Layout.maximumWidth: (dataView.columns > 0) ? (Math.floor(dataView.width / dataView.columns) - dataView.columnSpacing) : (Math.floor((dataView.width * dataView.rows) / repeater.count) - dataView.columnSpacing)
            Layout.row: computeRow()
            Layout.column: computeColumn()
    
            function computeRow() {
                var next = 0;
                if(index > 0){
                    var previousRow = repeater.itemAt(index-1).Layout.row;
                    var previousColumn = repeater.itemAt(index-1).Layout.column;
                    console.log("\ncompute row pour l'item  n° " + (index+1) + " successeur de [" + previousRow + ", " + previousColumn+"]");
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

            function computeColumn() {
                var next = 0;
                if(index > 0){
                    var previousRow = repeater.itemAt(index-1).Layout.row;
                    var previousColumn = repeater.itemAt(index-1).Layout.column;
                    console.log("\ncompute column pour l'item n° " + (index+1) + " successeur de [" + previousRow + ", " + previousColumn+"]");
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
                source: dataView.itemDelegate
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
    }
}
