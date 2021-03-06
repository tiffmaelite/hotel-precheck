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
    flow: GridLayout.LeftToRight
    columnSpacing: 1
    rowSpacing: 1
    rows: 1
    property int maxColumns: 5
    property string itemDelegate
    property string emptyDelegate
    property string sectionDelegate
    property alias sectionIndex : repeater.sectionIndex
    property alias model: repeater.model
    signal selected(string selectedItem)
    Component.onCompleted: {
        if(dataView.model !== 0) {
            dataView.model.fetch();
        }
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

            Layout.row: repeater.model === 0 ? 0 : computeRow()
            Layout.column: repeater.model === 0 ? 0 : computeColumn()

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

            /*Layout.row: repeater.model === 0 ? 0 : (dataView.computeCoord(repeater.model, repeater.sectionIndex, index, repeater.itemAt(index-1), true))
            Layout.column: repeater.model === 0 ? 0 : (dataView.computeCoord(repeater.model, repeater.sectionIndex, index, repeater.itemAt(index-1), false))

  function computeCoord(model, sectionIndex, index, previous, isCoordRow) {
        var sectioning = (sectionIndex !== 0);
        var startShift = 1;//0;
        var next = startShift;
        console.log("élément n°"+index+" d'ID " + (model.data(index, 0)));
        if(isCoordRow) {
            console.log("\ncalcul de l'indice de ligne");
        } else {
            console.log("\ncalcul de l'indice de colonne");
        }
        //on n'a besoin de calculer que pour des éléments ultérieurs au premier
        if(index > 0){
            var currentSection = model.data(index, sectionIndex);
            var previousSection = model.data(Math.max(0,index-1), sectionIndex);
            var previousRow = previous.Layout.row;
            var previousColumn = previous.Layout.column;
            var previousSameCoord = 0;
            var previousOtherCoord = 0;
            var totalSameCoord = 0;
            var totalOtherCoord = 0;
            var isAlongDisposition = true;
            if(isCoordRow) {
                previousSameCoord = previousRow;
                previousOtherCoord = previousColumn;
                totalOtherCoord = Math.max(0,dataView.columns);
                totalSameCoord = Math.max(0,dataView.rows);
                isAlongDisposition = (dataView.flow == GridLayout.LeftToRight) && !(dataView.flow == GridLayout.TopToBottom);
            } else {
                previousSameCoord = previousColumn;
                previousOtherCoord = previousRow;
                totalOtherCoord = Math.max(0,dataView.rows);
                totalSameCoord = Math.max(0,dataView.columns);
                isAlongDisposition = (dataView.flow == GridLayout.TopToBottom) && !(dataView.flow == GridLayout.LeftToRight);
            }
            console.log("indice prédécent selon la même coordonnée : "+previousSameCoord+"/"+totalSameCoord);
            console.log("indice prédécent selon l'autre coordonnée : "+previousOtherCoord+"/"+totalOtherCoord);
            if(isAlongDisposition) {
                console.log("le calcul se fait dans le sens non limité");
            }
            console.log("successeur de [" + previousRow + ", " + previousColumn+"]");
            if(sectioning) {
                if(previousSection !== currentSection) {
                    console.log("nouvelle section ["+model.field(sectionIndex).text+"] : "+currentSection);
                } else{
                    console.log("même section ["+model.field(sectionIndex).text+"] : "+currentSection);
                }
            }

            //dans le cas où la ligne/colonne de l'élément précédent avait atteint la limite, ou qu'il s'agit d'une nouvelle section
            if((sectioning && (previousSection !== currentSection)) || (totalOtherCoord > 0 && ((previousOtherCoord - startShift % totalOtherCoord) + startShift == 0))) {
                if(isAlongDisposition) {
                    console.log("nouvelle ligne/colonne dans le sens non limité");
                    next = previousSameCoord + 1;
                } else {
                    console.log("retour au début dans le sens non limité")
                    next = startShift;
                }
                //dans le cas où on continue normalement
            } else {
                if(isAlongDisposition) {
                    console.log("même ligne/colonne");
                    next = previousSameCoord;
                } else {
                    console.log("ligne/colonne suivante");
                    next = previousOtherCoord + 1;
                }
            }
            //on corrige les cas de dépassements étranges
            if(!isAlongDisposition) {
                next = next % totalSameCoord + startShift;
            }
        }
        //on adapte pour éviter les impossibilités
        if(next < startShift) {
            console.log("on adapte");
            next = startShift;
        }
        if(isCoordRow) {
            console.log("ligne finale "+next);
        } else {
            console.log("colonne finale "+next);
        }

        return next;
    }*/

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
