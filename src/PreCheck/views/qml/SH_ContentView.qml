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
    columns: (repeater.model===0) ? 1 : Math.max(0,Math.max(5,Math.min(repeater.count,dataView.maxColumns)))
    flow: GridLayout.LeftToRight
    columnSpacing: 1
    rowSpacing: 1
    rows: 1
    property int maxColumns: 5
    property string itemDelegate
    property string emptyDelegate
    property string sectionDelegate
    property alias sectionIndex : repeater.sectionIndex
    property variant model: 0
    signal selected(string selectedItem)

    /*!
          \fn computeRow
          \param \tyoe int index L'indice de l'élément pour lequel effectuer le calcul
          \param \type bool isCoordRow Indique si l'on calcule un indice de ligne ou pas (un indice de colonne dans le cas contraire)
          \return int l'indice de la ligne désirée (0 étant la première ligne)
          \brief \~french Calcule la ligne à laquelle insérer un élément donné
          \details Prend en compte le tri des éléments et va à la ligne pour toute nouvelle section (définie par le changement de valeur du critère de tri)
          */
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
    }

    Repeater {
        id: repeater
        property int sectionIndex : repeater.model===0 ? 0: repeater.model.sortKeyColumn
        model: dataView.model
        Component.onCompleted: {
            if(repeater.model !== 0) {
                if(repeater.model.isEmpty()) {
                    repeater.model.fetch();
                }
                if(!repeater.model.isEmpty()) {
                    console.log("\n\nÉléments fournis par " + repeater.model.table);
                    if(dataView.flow === Grid.LeftToRight) {
                        console.log("\nDisposition horizontale avec au maximum "+dataView.columns+" colonnes");
                    } else {
                        console.log("\nDisposition verticale avec au maximum "+dataView.rows+" lignes");
                    }
                }
            }
        }
        delegate: Rectangle {
            id: contentContainer
            Layout.fillHeight: true
            Layout.fillWidth: true
            property double maxHeight: repeater.model === 0 ? 0 : ((dataView.flow === GridLayout.TopToBottom) ? Math.floor(dataView.height / dataView.rows) : (Math.floor(dataView.height * (dataView.columns) / repeater.count)))
            property double maxWidth: repeater.model === 0 ? 0 : ((dataView.flow === GridLayout.LeftToRight) ? Math.floor(dataView.width / dataView.columns) : (Math.floor(dataView.width * (dataView.rows / repeater.count))))
            Layout.maximumHeight: Math.max(0,contentContainer.maxHeight - dataView.rowSpacing)
            Layout.maximumWidth: Math.max(0,contentContainer.maxWidth - dataView.columnSpacing)
            Layout.row: repeater.model === 0 ? 0 : (dataView.computeCoord(repeater.model, repeater.sectionIndex, index, repeater.itemAt(index-1), true))
            Layout.column: repeater.model === 0 ? 0 : (dataView.computeCoord(repeater.model, repeater.sectionIndex, index, repeater.itemAt(index-1), false))

            Loader {
                id:contentLoader
                source: dataView.itemDelegate
                Binding {
                    target: contentLoader.item
                    property: "width"
                    value: Math.max(0,contentContainer.width - 1)
                }
                Binding {
                    target: contentLoader.item
                    property: "height"
                    value: Math.max(0,contentContainer.height - 2)
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
    /*
    Repeater {
        id: complementaryRepeater
        model: repeater.model
        property int sectionIndex: repeater.sectionIndex
        property int currentIndex: 0
        property int currentSectionSize: 0
        property int previousSectionSize: 0
        delegate:
            Item {
            Binding {
                target: complementaryRepeater
                property: "currentIndex"
                value: index
            }
            Item {
                id: filler
                visible: false
                state: (complementaryRepeater.currentIndex > 0 && complementaryRepeater.model.data(complementaryRepeater.currentIndex-1, complementaryRepeater.sectionIndex) === complementaryRepeater.model.data(complementaryRepeater.currentIndex, complementaryRepeater.sectionIndex)) ? "sameSection": "newSection"
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
                        var previousSize = complementaryRepeater.currentSectionSize;
                        filler.cols = 0;
                        complementaryRepeater.currentSectionSize = previousSize+1;
                        complementaryRepeater.previousSectionSize = previousSize;
                    } else if(filler.state == "newSection") {
                        complementaryRepeater.previousSectionSize = complementaryRepeater.currentSectionSize;
                        complementaryRepeater.currentSectionSize = 1;
                        filler.cols = ((dataView.columns-(complementaryRepeater.previousSectionSize % dataView.columns)) % dataView.columns);

                        console.log("nouvelle section '" + complementaryRepeater.model.data(complementaryRepeater.currentIndex, complementaryRepeater.sectionIndex)+"'");
                        console.log(filler.cols + "/" + dataView.columns + " colonnes à remplir");
                    }
                    console.log("previous section size: "+complementaryRepeater.previousSectionSize);
                    console.log("next section size: " +complementaryRepeater.currentSectionSize);
                }

                Component.onCompleted: {
                    console.log("index : "+complementaryRepeater.currentIndex);
                    console.log("index in section : "+complementaryRepeater.currentSectionSize);
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
                            property double maxHeight: (dataView.flow == GridLayout.TopToBottom) ? Math.floor(dataView.height / dataView.rows) : (Math.floor(dataView.height * (dataView.columns) / repeater.count))
                            property double maxWidth: (dataView.flow == GridLayout.LeftToRight) ? Math.floor(dataView.width / dataView.columns) : (Math.floor(dataView.width * (dataView.rows / repeater.count)))
                            Layout.maximumHeight: contentContainer.maxHeight - dataView.rowSpacing
                            Layout.maximumWidth: contentContainer.maxWidth - dataView.columnSpacing
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
                                value: complementaryRepeater.model.data(complementaryRepeater.currentIndex, complementaryRepeater.sectionIndex)
                            }
                        }
                    }
                }
            }
        }
    }*/
}
