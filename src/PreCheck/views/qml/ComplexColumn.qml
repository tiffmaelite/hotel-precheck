import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Column {
    id: col
    readonly property real innerHeight: col.height-col.anchors.topMargin-col.anchors.bottomMargin-2*col.spacing
    readonly property real innerWidth: col.width-col.anchors.rightMargin-col.anchors.leftMargin-2*col.spacing
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
