import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_SqlTableView
  */
TableView {
    id: table
    model: 0
    signal selected(string selectedItem)
    signal selectedRow(int selectedData)
    Component.onCompleted:{
        if(table.model !== 0) {
            table.model.fetch();
            var count = table.model.fieldsCount();
            for(var index = 0; index < count; index++) {
                if(!table.model.isHidingColumn(index)) {
                    var col = Qt.createQmlObject('import QtQuick 2.1; import QtQuick.Controls 1.0; TableViewColumn {title: table.model.field('+index+').text; role: table.model.field('+index+').role}',table,'column'+index);
                    /*tmp.push(col);*/
                    table.addColumn(col);
                }
            }
        }
    }

    headerDelegate:
        Rectangle {
        color: "white"
        //border.color: "black"
        border.width: 0
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "white";
            }
            GradientStop {
                position: 0.8;
                color: "lemonchiffon";
            }
            GradientStop {
                position: 1;
                color: "wheat";
            }
        }
        width: headerText.width
        height: 1.5*headerText.height
        Label {
            id:headerText
            text: styleData.value !== undefined ? styleData.value : ""
            font.bold: true
            font.pointSize: 10
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            maximumLineCount: 2
            anchors.centerIn: parent
            styleColor: "tan"
            renderType: Text.NativeRendering
            wrapMode: Text.Wrap
        }
    }

    itemDelegate:
        Item {
        id: cellDelegate
        height: Math.max(16, label.implicitHeight)
        property int implicitWidth: sizehint.paintedWidth + 16
        Text {
            id: label
            height: contentHeight
            visible: !styleData.selected
            width: parent.width
            anchors.leftMargin: 8
            maximumLineCount: 3
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: styleData.textAlignment
            anchors.verticalCenter: parent.verticalCenter
            elide: styleData.elideMode
            wrapMode: Text.Wrap
            text: styleData.value !== undefined ? styleData.value : ""
            color: styleData.textColor
            renderType: Text.NativeRendering
        }
        Text {
            id: sizehint
            font: label.font
            text: styleData.value ? styleData.value : ""
            visible: false
        }
        Loader { /* Initialize text input lazily to improve performance*/
            id: loaderEditor
            anchors.fill: parent
            anchors.margins: 4
            Connections {
                target: loaderEditor.item
                onAccepted: {
                    /*if (typeof styleData.value === 'NUMBER')*/
                    table.selected(styleData.value);
                    table.selectedRow(styleData.row)
                    model.setData(styleData.row, styleData.role, styleData.value);
                }
            }
            sourceComponent: styleData.selected ? editor : null
            Component {
                id: editor
                TextInput {
                    id: textinput
                    wrapMode: Text.Wrap
                    text: styleData.value !== undefined ? styleData.value : ""
                    color: styleData.textColor
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
