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
    //columns: (repeater.count < dataView.maxColumns) ? repeater.count : dataView.maxColumns
    columns: 5
    columnSpacing: 1
    rowSpacing: 1
    property string dataDelegate
    property string emptyDelegate
    property string sectionDelegate
    property int maxColumns: 7
    property alias sectionIndex : repeater.sectionIndex
    property alias model: repeater.model
    readonly property bool horizontalDisposition: dataView.rows <=0 && dataView.columns > 0
    readonly property bool verticalDisposition: dataView.columns <=0 && dataView.rows > 0
    signal selected(string selectedItem)
    Component.onCompleted: {
        //dataView.columns =  (repeater.count < dataView.maxColumns) ? repeater.count : dataView.maxColumns;
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
            property double maxHeight: dataView.verticalDisposition ? Math.floor(dataView.height / dataView.rows) : (Math.floor(dataView.height * (dataView.columns) / repeater.count))
            property double maxWidth: dataView.horizontalDisposition ? Math.floor(dataView.width / dataView.columns) : (Math.floor(dataView.width * (dataView.rows / repeater.count)))
            Layout.maximumHeight: maxHeight - dataView.rowSpacing
            Layout.maximumWidth: maxWidth - dataView.columnSpacing
            Layout.row: computeCoord(true)
            Layout.column: computeCoord(false)
            /*!
              \fn computeRow
              \param \type bool isCoordRow Indique si l'on calcule un indice de ligne ou pas (un indice de colonne dans le cas contraire)
              \return int l'indice de la ligne désirée (0 étant la première ligne)
              \brief \~french Calcule la ligne à laquelle insérer un élément donné
              \details Prend en compte le tri des éléments et va à la ligne pour toute nouvelle section (définie par le changement de valeur du critère de tri)
              */
            function computeCoord(isCoordRow) {
                var startShift = 0;
                var next = 0;
                //on n'a besoin de calculer que pour des éléments ultérieurs au premier
                if(index > 0){
                    var currentSection = repeater.model.data(index, repeater.sectionIndex);
                    var previousSection = repeater.model.data(index-1, repeater.sectionIndex);
                    var previousRow = repeater.itemAt(index-1).Layout.row;
                    var previousColumn = repeater.itemAt(index-1).Layout.column;
                    var previousSameCoord = 0;
                    var previousOtherCoord = 0;
                    var totalSameCoord = 0;
                    var totalOtherCoord = 0;
                    var isAlongDisposition = true;
                    if(isCoordRow) {
                        console.log("\n\ncalcul de l'indice de ligne");
                        previousSameCoord = previousRow;
                        previousOtherCoord = previousColumn;
                        totalOtherCoord = dataView.columns;
                        totalSameCoord = dataView.rows;
                        isAlongDisposition = dataView.horizontalDisposition && !dataView.verticalDisposition;
                    } else {
                        console.log("\n\ncalcul de l'indice de colonne");
                        previousSameCoord = previousColumn;
                        previousOtherCoord = previousRow;
                        totalOtherCoord = dataView.rows;
                        totalSameCoord = dataView.columns;
                        isAlongDisposition = dataView.verticalDisposition && !dataView.horizontalDisposition;
                    }
                    if(isAlongDisposition) {
                        console.log("le calcul se fait dans le sens non limité");
                    }
                    console.log("élément d'ID " + (repeater.model.data(index, 0)) +", successeur de [" + previousRow + ", " + previousColumn+"]");
                    console.log("indice prédécent selon la même coordonnée : "+previousSameCoord+"/"+totalSameCoord);
                    console.log("indice prédécent selon l'autre coordonnée : "+previousOtherCoord+"/"+totalOtherCoord);

                    if(repeater.sectioning) {
                        if(previousSection !== currentSection) {
                            console.log("nouvelle section ["+repeater.model.field(repeater.sectionIndex).text+"] : "+currentSection);
                        } else{
                            console.log("même section ["+repeater.model.field(repeater.sectionIndex).text+"] : "+currentSection);
                        }
                    }

                    //dans le cas où la ligne/colonne de l'élément précédent avait atteint la limite, ou qu'il s'agit d'une nouvelle section
                    if((repeater.sectioning && (previousSection !== currentSection)) || (totalOtherCoord > 0 && ((previousOtherCoord - startShift % totalOtherCoord) + startShift == 0))) {
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
                }
                //on corrige les cas de dépassements étranges
                if(!isAlongDisposition) {
                    next = next % totalSameCoord + startShift;
                }
                if(next < startShift) {
                    next = startShift;
                }

                if(isCoordRow) {
                    console.log("ligne finale "+next);
                } else {
                    console.log("colonne finale "+next);
                }

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
