import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/**
  @class
  */
TableView {
    id: table
    model: 0
    signal selected(string selectedItem)
    Component.onCompleted:{
        /*var tmp = [];*/
        if(table.model !== 0) {
            table.model.fetch();
            var count = table.model.fieldsCount();
            for(var index = 0; index < count; index++) {
                if(!table.model.containsFilterKeyColumn(index)) {
                    var col = Qt.createQmlObject('import QtQuick 2.1; import QtQuick.Controls 1.0; TableViewColumn {title: table.model.field('+index+').text; role: table.model.field('+index+').role}',table,'column'+index);
                    /*tmp.push(col);*/
                    table.addColumn(col);
                }
            }
        }
        /*return tmp;*/
    }


    itemDelegate:
        Item {

        Text {
            width: parent.width
            anchors.margins: 4
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            elide: styleData.elideMode
            text: styleData.value !== undefined ? styleData.value : ""
            color: styleData.textColor
            visible: !styleData.selected
        }
        Loader { /* Initialize text input lazily to improve performance*/
            id: loaderEditor
            anchors.fill: parent
            anchors.margins: 4
            Connections {
                target: loaderEditor.item
                onAccepted: {
                    /*if (typeof styleData.value === 'number')*/
                    table.selected(styleData.row);
                    model.setData(styleData.row, styleData.role, styleData.value);
                }
            }
            sourceComponent: styleData.selected ? editor : null
            Component {
                id: editor
                TextInput {
                    id: textinput
                    color: styleData.textColor
                    text: styleData.value
                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            textinput.forceActiveFocus()
                        }
                    }
                    onFocusChanged: {
                        if(styleData.value !== textinput.text) {
                            textinput.accepted();
                        }
                    }

                }
            }
        }
    }
}
