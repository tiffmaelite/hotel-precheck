import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Row {
    id: row
    readonly property real innerHeight: row.height-row.anchors.topMargin-row.anchors.bottomMargin-2*row.spacing
    readonly property real innerWidth: row.width-row.anchors.rightMargin-row.anchors.leftMargin-2*row.spacing
}
