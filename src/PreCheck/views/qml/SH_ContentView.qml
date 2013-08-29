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
    flow: GridLayout.LeftToRight
    columnSpacing: 1
    rowSpacing: 1
    rows: 1
    columns: repeater.model === 0 ? 0 : dataView.maxColumns
    property int maxColumns: 4
    property variant model: 0
    property Component itemDelegate
    signal selected(string selectedItem)
    Component.onCompleted: {
        if(dataView.model !== 0 && dataView.model.rowCount() > 0) {
            dataView.columns = Math.min(dataView.model.rowCount(), dataView.maxColumns);
            repeater.model = dataView.model;
        }
    }
    function computeMaxCoord(rep, grid, height) {
        if(rep.model === 0 || rep.model.rowCount() <= 0) {
            return 0;
        }
        var dispositionFlow;
        var alongDispositionMaxSize;
        var alongDispositionDivisions;
        var otherDispositionDivisions;
        var alongDispositionSpacing;
        if(height) {
            dispositionFlow = GridLayout.TopToBottom;
            alongDispositionMaxSize = Math.max(0, grid.height);
            alongDispositionDivisions = Math.max(0, grid.rows);
            otherDispositionDivisions = Math.max(0, grid.columns);
            alongDispositionSpacing = Math.max(0, grid.rowSpacing);
        } else {
            dispositionFlow = GridLayout.LeftToRight;
            alongDispositionMaxSize = Math.max(0, grid.width);
            alongDispositionDivisions = Math.max(0, grid.columns);
            otherDispositionDivisions = Math.max(0, grid.rows);
            alongDispositionSpacing = Math.max(0, grid.columnSpacing);
        }
        var size;
        if(grid.flow === dispositionFlow) {
            size = Math.floor( alongDispositionMaxSize / alongDispositionDivisions);
        } else {
            size = Math.floor((alongDispositionMaxSize * otherDispositionDivisions) / rep.count);
        }
        return Math.max(0,size - alongDispositionSpacing);
    }

    /*!
          \fn computeCoord
          \param \type Repeater rep
          \param \type int index L'indice de l'élément pour lequel effectuer le calcul
          \param \type GridLayout grid
          \param \type bool isCoordRow Indique si l'on calcule un indice de ligne ou pas (un indice de colonne dans le cas contraire)
          \return int l'indice de la ligne désirée (1 étant la première ligne)
          \brief \~french Calcule la ligne à laquelle insérer un élément donné
          \details Prend en compte le tri des éléments et va à la ligne pour toute nouvelle section (définie par le changement de valeur du critère de tri)
          */
    function computeCoord(rep, index, grid, isCoordRow) {
        //console.log("\n\nélément n°"+index);
        var model = rep.model;
        if(model === 0 || model.rowCount() <= 0) {
            console.log("Modèle vide");
            return 0;
        }
        var next = 0;
        var id = model.data(model.modelIndex(index, 0), 256);
        /*console.log("élément d'ID " + id+" ("+ model.data(model.modelIndex(index, 1), 256+1)+")");
        if(isCoordRow) {
            console.log("\ncalcul de l'indice de ligne");
        } else {
            console.log("\ncalcul de l'indice de colonne");
        }*/
        if(index >= 1) { // on n'a besoin de calculer que pour des éléments ultérieurs au premier car ligne 0 et colonne 0 pour élément d'index 0
            var sectionIndex = Math.max(0,model.sortKeyColumn); //L'indice du champ du modèle selon lequel est effectué le tri des éléments
            var sectioning = (sectionIndex > 0); //sectionIndex=0 <=> tri par les ID <=> pas de tri
            var currentSection = model.data(model.modelIndex(index, sectionIndex), 256+sectionIndex);
            var previousSection = model.data(model.modelIndex(index-1, sectionIndex), 256+sectionIndex);
            var previous = rep.itemAt(index-1);
            var previousRow = previous.Layout.row;
            var previousColumn = previous.Layout.column;

            var previousSameCoord;
            var previousOtherCoord;
            var totalSameCoord;
            var totalOtherCoord;
            var isAlongDisposition;
            if(isCoordRow) {
                previousSameCoord = previousRow;
                previousOtherCoord = previousColumn;
                totalOtherCoord = Math.max(0,grid.columns);
                totalSameCoord = Math.max(0,grid.rows);
                isAlongDisposition = (grid.flow === GridLayout.LeftToRight) && !(grid.flow === GridLayout.TopToBottom);
            } else {
                previousSameCoord = previousColumn;
                previousOtherCoord = previousRow;
                totalOtherCoord = Math.max(0,grid.rows);
                totalSameCoord = Math.max(0,grid.columns);
                isAlongDisposition = (grid.flow === GridLayout.TopToBottom) && !(grid.flow === GridLayout.LeftToRight);
            }
            /*if(isAlongDisposition) {
                console.log("le calcul se fait dans le sens non limité");
            }
            if(sectioning) {
                if(previousSection !== currentSection) {
                    console.log("nouvelle section ("+model.field(sectionIndex).text+") : "+currentSection);
                } else{
                    console.log("même section ("+model.field(sectionIndex).text+") : "+currentSection);
                }
            }
            console.log("previousOtherCoord: "+previousOtherCoord+", totalOtherCoord: "+totalOtherCoord+", previousSameCoord:"+previousSameCoord+", totalSameCoord:"+totalSameCoord);*/

            //dans le cas où la ligne/colonne de l'élément précédent avait atteint la limite, ou qu'il s'agit d'une nouvelle section
            if((sectioning && (previousSection !== currentSection)) || (totalOtherCoord > 0 && ((previousOtherCoord + 1) % totalOtherCoord == 0))) {
                if(isAlongDisposition) {
                    //console.log("nouvelle ligne/colonne dans le sens non limité");
                    next = previousSameCoord + 1;
                } else {
                    //console.log("retour au début dans le sens non limité")
                    next = 0;
                }
                //dans le cas où on continue normalement
            } else {
                if(isAlongDisposition) {
                    //console.log("même ligne/colonne");
                    next = previousSameCoord;
                } else {
                    //console.log("ligne/colonne suivante");
                    next = previousSameCoord + 1;
                }
            }
            //on corrige les cas de dépassements étranges
            if(!isAlongDisposition && (next >= totalSameCoord)) {
                next = next % totalSameCoord;
            }
            /*on adapte pour éviter les impossibilités*/
            next = Math.max(next, 0);
            if(totalSameCoord > 0) {
                next = Math.min(next, totalSameCoord);
            }
            //console.log("successeur de [" + previousRow + ", " + previousColumn+"]");
        }
        /*if(isCoordRow) {
            console.log("ligne finale "+next);
        } else {
            console.log("colonne finale "+next);
        }*/
        return next;
    }

    Repeater {
        id: repeater
        model: 0
        property real itemHeight: computeMaxCoord(repeater, dataView, true)
        property real itemWidth: computeMaxCoord(repeater, dataView, false)
        delegate: Rectangle {
            color: "transparent"
            Layout.maximumHeight: repeater.itemHeight
            Layout.maximumWidth: repeater.itemWidth
            Layout.row: computeCoord(repeater, index, dataView, true)
            Layout.column: computeCoord(repeater, index, dataView, false)
            Layout.fillWidth: true
            Layout.fillHeight: true
            Loader {
                id: itemLoader
                source: itemDelegate
                Connections {
                    target: itemLoader.item
                    onClicked: {
                        dataView.selected(repeater.itemAt(index).value);
                    }
                }
            }
        }
    }
}
