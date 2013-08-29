import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

ScrollView {
    id: output
    property int nbMaxRows: 25
    property int currentRow: -1
    property int currentColumn: -1
    property int nbColumns: 2

    signal selected(string selectedItem)

    signal display(string text, int row, int column)
    signal displayTextAt(string text, int row)
    signal displayText(string text)
    signal replace(string text, int row, int column)
    signal replaceTextAt(string text, int row)
    signal replaceText(string text)
    signal displaySqlDatas(variant model)
    signal displaySqlDatasAt(variant model, int row)

    signal clearAll()

    onClearAll: {
        for(var i = 0; i < output.nbMaxRows; i++) {
            for(var j = 0; j < output.nbColumns;j++) {
                qRep.itemAt(j+output.nbColumns*i).enabled = true;
            }
            qRep.itemAt(output.nbColumns*i).text="";
            qRep.itemAt(1+output.nbColumns*i).text="";
            qRep.itemAt(1+output.nbColumns*i).model=0;
            for(j = 0; j < output.nbColumns;j++) {
                qRep.itemAt(j+output.nbColumns*i).enabled = false;
            }
        }
    }
    onDisplay: {
        setText(text, row, column, false);
    }
    onDisplayTextAt: {
        setText(text, row, currentColumn, false);
    }
    onDisplayText: {
        setText(text, currentRow, currentColumn, false);
    }
    onReplace: {
        setText(text, row, column, true);
    }
    onReplaceTextAt: {
        setText(text, row, currentColumn, true);
    }
    onReplaceText: {
        setText(text, currentRow, currentColumn, true);
    }
    onDisplaySqlDatas: {
        setSqlDatas(model, currentRow);
    }
    onDisplaySqlDatasAt: {
        setSqlDatas(model, row);
    }

    function setText(text, row, column, replace) {
        cols.setText(text, row, column, replace);
    }
    function setSqlDatas(model, row) {
        cols.setSqlDatas(model, row);
    }

    Rectangle {
        color: "transparent"
        GridLayout {
            id: cols
            objectName: "colsGridLayout"
            height: output.height
            width: output.width
            rowSpacing: 1
            columnSpacing: 2
            flow: GridLayout.LeftToRight
            columns: output.nbColumns
            rows: output.nbMaxRows
            Repeater {
                id: qRep
                property real cellHeight: Math.max(0, Math.floor((cols.height / cols.rows) - 2*cols.rowSpacing))
                property real cellWidth: Math.max(0, Math.floor((cols.width / cols.columns) - 2*cols.columnSpacing))
                model: cols.columns * cols.rows
                delegate:
                    Loader {
                    id: compLoader
                    property string text
                    property variant model
                    sourceComponent: (index % cols.columns === 0) ? question : answer
                    Binding {
                        target: compLoader.item
                        property: "text"
                        value: compLoader.text
                    }
                    Binding {
                        target: compLoader.item
                        property: "model"
                        value: compLoader.model
                    }
                    Binding {
                        target: compLoader.item
                        property: "Layout.alignment"
                        value: (index % cols.columns === 0) ? Qt.AlignLeft : Qt.AlignRight
                    }
                    Binding {
                        target: compLoader.item
                        property: "Layout.fillHeight"
                        value: true
                    }
                    Binding {
                        target: compLoader.item
                        property: "Layout.fillWidth"
                        value: true
                    }
                    /*Binding {
                    target: compLoader.item
                    property: "Layout.minimumWidth"
                    value: qRep.cellWidth
                }
                Binding {
                    target: compLoader.item
                    property: "Layout.minimumHeight"
                    value: qRep.cellHeight
                }
                Binding {
                    target: compLoader.item
                    property: "Layout.maximumWidth"
                    value: qRep.cellWidth
                }
                Binding {
                    target: compLoader.item
                    property: "Layout.maximumHeight"
                    value: qRep.cellHeight
                }*/
                    Binding {
                        target: compLoader.item
                        property: "Layout.preferredWidth"
                        value: qRep.cellWidth
                    }
                    Binding {
                        target: compLoader.item
                        property: "Layout.preferredHeight"
                        value: qRep.cellHeight
                    }
                    Binding {
                        target: compLoader.item
                        property: "width"
                        value: qRep.cellWidth
                    }
                    Binding {
                        target: compLoader.item
                        property: "height"
                        value: qRep.cellHeight
                    }
                    Connections {
                        target: compLoader.item
                        onFocusChanged: {
                            if(compLoader.item.focus) {
                                output.currentRow = index < cols.columns ? index : Math.floor(index / cols.columns);
                                output.currentColumn = index % cols.columns;
                            }
                        }
                        Component.onCompleted: {
                            compLoader.item.height = qRep.cellHeight;
                            compLoader.item.width = qRep.cellWidth;
                        }
                        onTextChanged: {
                            compLoader.item.height = qRep.cellHeight;
                            compLoader.item.width = qRep.cellWidth;
                        }
                    }
                }
            }
            function setText(text, row, column, replace) {
                /*if(replace) {
                    console.log("change displayed text");
                } else {
                    console.log("display new text");
                }
                console.log("text to display '"+text+"' at ["+row+", "+column+"]");*/
                var c = column % cols.columns;
                var r = Math.min(Math.max(0, row),cols.rows);
                for(var j = 0; j < cols.columns;j++) {
                    qRep.itemAt(j+cols.columns*r).enabled = true;
                }
                if(!replace && (c === 1 || (qRep.itemAt(c+cols.columns*r).text !== ""  && qRep.itemAt(c+cols.columns*r).text !== text))) {
                    c=1;
                    var pos = qRep.itemAt(c+cols.columns*r).cursorPosition;
                    var end = qRep.itemAt(c+cols.columns*r).text.size - 1;
                    if(pos >= 0 && pos <= end) {
                        qRep.itemAt(c+cols.columns*r).text=qRep.itemAt(c+cols.columns*r).text.substring(0, pos)+text+qRep.itemAt(c+cols.columns*r).text.substring(pos, end);
                    } else {
                        qRep.itemAt(c+cols.columns*r).text += text;
                    }
                } else {
                    qRep.itemAt(c+cols.columns*r).text=text;
                }
                output.currentRow = r;
                output.currentColumn = c;
                /*console.log("text displayed at ["+r+", "+c+"]");*/
            }
            function setSqlDatas(sqlData, row) {
                var r = Math.min(Math.max(0, row),cols.rows);
                output.currentRow = r;
                for(var j = 0; j < cols.columns;j++) {
                    qRep.itemAt(j+cols.columns*r).enabled = true;
                }
                qRep.itemAt(1+cols.columns*r).model = sqlData;
            }
        }
        Component {
            id: question
            Text {
                height: qRep.cellHeight
                width: qRep.cellWidth
                property variant model: 0
                fontSizeMode: Text.Fit
                font.pointSize: 6
                text: ""
                color: "black"
                enabled: false
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                verticalAlignment: Text.AlignVCenter
                onTextChanged: {
                    if(text != "") {
                        enabled = true;
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        aLayout.focus = true;
                    }
                }
            }
        }
        Component {
            id:answer
            ColumnLayout {
                id: aLayout
                height: qRep.cellHeight
                width: qRep.cellWidth
                spacing: 0
                property alias text: aText.text
                property alias model: aPropositions.model
                property alias cursorPosition: aText.cursorPosition
                property bool enabled: false
                SH_ContentView {
                    id: aPropositions
                    Layout.maximumHeight: aLayout.height - aText.height - aLayout.spacing
                    width: aLayout.width
                    enabled: aLayout.enabled
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignRight
                    itemDelegate: SH_DataDelegate {}
                    onSelected: {
                        output.selected(selectedItem);
                        aLayout.focus = true;
                    }
                }
                TextEdit{
                    id: aText
                    text: ""
                    font.pointSize: 7.5
                    color: "black"
                    enabled: aLayout.enabled
                    Layout.minimumHeight: aLayout.height / 5
                    Layout.maximumHeight: aLayout.height - aLayout.spacing
                    width: aLayout.width
                    activeFocusOnPress: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignBottom
                    verticalAlignment: Text.AlignVCenter
                    onFocusChanged: {
                        if(focus) {
                            aLayout.focus = true;
                        }
                    }
                    onTextChanged: {
                        if(text!="") {
                            enabled = true;
                        }
                        aLayout.textChanged(text);
                    }
                }
            }
        }
    }
}
