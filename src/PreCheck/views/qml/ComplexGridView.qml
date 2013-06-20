#ifndef DOXYGEN_SHOULD_SKIP_THIS

import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import PreCheck 1.0

GridView {
    id:grid
    property real cellSpacing: 0
    property bool fillWithEmpty: true
    readonly property real innerHeight: grid.height-grid.anchors.topMargin-grid.anchors.bottomMargin-2*grid.cellSpacing
    readonly property real innerWidth: grid.width-grid.anchors.rightMargin-grid.anchors.leftMargin-2*grid.cellSpacing
    property int maxNbRowsFew:3
    property int maxNbColsFew:2
    property int maxNbRowsStd:4
    property int maxNbColsStd:3
    property int maxNbFlowMany:5
    flow:GridView.LeftToRight
    
    cellWidth: ((grid.flow==GridView.LeftToRight) ?
                   ((grid.count > maxNbColsStd*maxNbRowsStd) ? Math.floor(width/maxNbFlowMany) : ((grid.count > maxNbColsFew*maxNbRowsFew) ? Math.floor(width / maxNbColsStd) : Math.floor(width / maxNbColsFew))) :
                   ((grid.count > maxNbColsStd*maxNbRowsStd) ? Math.floor(width/maxNbFlowMany) : ((grid.count > maxNbColsFew*maxNbRowsFew) ? Math.floor(width / maxNbRowsStd) : Math.floor(width / maxNbRowsFew))))
                   
    /*hauteur divisée par le nombre nécessaire de lignes, c'est-à-dire le nombre d'éléments divisés par le nombre de colonnes (qui lui-même, étant variable, est calculé à partir de la largeur totale divisée par la largeur de chaque cellule)*/
    /*cellHeight: Math.floor(grid.innerHeigh / (grid.count/(grid.innerWidth/grid.cellWidth)))*/
    /*idem que ci-dessus mais plus clair : aire disponible divisée par la largeur totale occupée par les cellules*/
    cellHeight: (grid.count > 0) ? Math.floor((grid.innerHeight*grid.innerWidth) / (grid.count*grid.cellWidth)) : 10 
    currentIndex: -1
    focus: true
    signal selected(string selectedItem)
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
