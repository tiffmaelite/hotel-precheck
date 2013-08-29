import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

Rectangle {
    id: output
    visible: true
    color: App.readStringSetting("backgroundColor","outputZone")
    property int nbMaxRows: 20
    property int currentRow: -1
    property int currentColumn: -1
    property int nbColumns: 1

    signal selected(string selectedItem)

    signal display(string text, int row, int column)
    signal displayTextAt(string text, int row)
    signal displayText(string text)
    signal replace(string text, int row, int column)
    signal replaceTextAt(string text, int row)
    signal replaceText(string text)
    signal displaySqlDatas(variant model)
    signal displaySqlDatasAt(variant model, int row)

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
}
