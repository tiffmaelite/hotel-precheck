import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Rectangle {
    id: output
    visible: true
    color: "lightgrey"
    property int lastVisibleRow: -1
    signal display(string text)
    signal displayNew(string text, bool editable)
    signal replace(string text)
    signal selected(string selectedItem)

    onReplace: {
        if(output.lastVisibleRow >= 0) {
            layout.changeTextDisplay(output.lastVisibleRow,text, rep.itemAt(output.lastVisibleRow).editable);
        } else {
            display(text);
        }
    }
    onDisplay: layout.continueTextDisplay(output.lastVisibleRow,text);
    onDisplayNew: layout.changeTextDisplay(output.lastVisibleRow+1,text, editable);

    function clear(row) {
        if(row <= output.lastVisibleRow) {
            rep.itemAt(row).text = "";
        }
    }
    function clearAll() {
        for(var currentRow = 0; currentRow<rep.count; currentRow++) {
            output.clear(currentRow);
        }
    }
    function displayText(text) {
        layout.changeTextDisplay(output.lastVisibleRow+1,text, false);
    }
    function displayCalendar() {
        var cal = Qt.createComponent("CalendarDialog.qml");
        output.lastVisibleRow++;
        var incubator = cal.incubateObject(rep.itemAt(output.lastVisibleRow));
        if (incubator.status !== Component.Ready) {
            incubator.onStatusChanged = function(status) {
                if (status === Component.Ready) {
                    cal.selected.connect(output.selected);
                    rep.itemAt(output.lastVisibleRow).children = [cal];
                }
            }
        } else {
            cal.selected.connect(output.selected);
            rep.itemAt(output.lastVisibleRow).children = [cal];
        }
    }
    function displaySqlDatas(sqlData, sqlDelegate) {
        var view = Qt.createComponent("ContentView.qml");
        output.lastVisibleRow++;
        var incubator = view.incubateObject(rep.itemAt(output.lastVisibleRow),{Layout: {fillHeight: true, fillWidth: true, minimumWidth: childrenRect.width, minimumHeight: childrenRect.height}, model: sqlData, dataDelegate: sqlDelegate});
        if (incubator.status !== Component.Ready) {
            incubator.onStatusChanged = function(status) {
                if (status === Component.Ready) {
                    view.selected.connect(output.selected);
                    rep.itemAt(output.lastVisibleRow).children = [view];
                }
            }
        } else {
            view.selected.connect(output.selected);
            rep.itemAt(output.lastVisibleRow).children = [view];
        }
    }
    function displaySqlDetail(table, row) {
        console.log(table+" "+row);
    }

    ColumnLayout {
        id:layout
        anchors.margins: 5
        anchors.fill: output
        height: output.height
        width: output.width
        function changeTextDisplay(row, text, editable) {
            if(row < rep.count) {
                if(row > output.lastVisibleRow) {
                    output.lastVisibleRow=row;
                }
                rep.itemAt(row).editable = editable;
                rep.itemAt(row).text = text;
            }
        }
        function continueTextDisplay(row, text) {
            if(row < 0) {
                layout.changeTextDisplay(row+1, text, false);
            } else if(row > output.lastVisibleRow) {
                layout.changeTextDisplay(row, text, false);
            } else {
                if(row >= rep.count) {
                    row = rep.count-1;
                }
                rep.itemAt(row).text = rep.itemAt(row).text+text;
            }
        }

        Repeater {
            id: rep
            model: 20
            delegate:
                RowLayout {
                id: row
                //pas d'alias car le "component" auquel ces propriétés font (implicitement) référence peut changer (pas forcément un composant de type "TextEdit")
                property string text: ""
                property bool editable: true
                Layout.minimumHeight: layout.height / rep.model - layout.spacing -layout.anchors.margins
                Layout.minimumWidth: layout.width-layout.anchors.margins
                Layout.fillWidth: true
                Layout.fillHeight: true
                visible: true
                TextEdit {
                    id: defaultContent
                    text: row.text
                    readOnly:  !row.editable
                    wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere;
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    font.pointSize: 12
                    color: defaultContent.readOnly ? "grey" : "darkgrey"
                }

            }
        }
    }
}
