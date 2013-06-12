import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Rectangle {
    id:display
    property var sqlModel
    property string itemDelegate
    property string emptyDelegate : "DataDelegate.qml"
    property string sectionDelegate : "DataDelegate.qml"
    property bool filterIndicatorsVisibles: true
    property string filtersTitle
    signal selected(string selectedItem)
    signal newItem
    property bool isEmpty: !display.sqlModel.fetch()
    enabled: true
    height: childrenRect.height
    width: childrenRect.width
    anchors.margins: 3
    Text{
        text: qsTr("Aucun résultat")
        visible: display.isEmpty
        color: "#dd1f1f"
    }

    ColumnLayout {
        id:colView
        spacing: 3
        visible: !display.isEmpty
        anchors.fill:parent
        /*Rectangle {
            id:upArea
            Layout.fillWidth: true
            Layout.minimumWidth: childrenRect.width
            Layout.minimumHeight: childrenRect.height
            visible: filterIndicatorsVisibles
            border.width: 1
            border.color: "black"
            ColumnLayout {
                id: upCol
                anchors.fill: upArea
                Text {
                    id: upTitle
                    text: filtersTitle
                    Layout.fillWidth: true
                    Layout.preferredWidth: upTitle.paintedWidth
                    Layout.preferredHeight: upTitle.paintedHeight
                    Layout.alignment: Qt.AlignLeft
                }
                HeaderView {
                    id: filterGrid
                    visible: upArea.visible
                    enabled: display.enabled
                    Layout.minimumWidth: childrenRect.width
                    Layout.minimumHeight: childrenRect.height
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: display.isEmpty? 0 : display.sqlModel.fieldsCount();
                    delegateModel: display.sqlModel;
                    Component.onCompleted: {
                        model = Qt.binding(function() {return display.isEmpty ? 0 : display.sqlModel.fieldsCount();});
                        delegateModel = Qt.binding(function() {return display.sqlModel;});
                    }
                    onUp: dataView.sort(index);
                    onChecked: dataView.filter(index, ch);
                }
            }
        }*/
        ContentView {
            id:dataView
            model: (display.isEmpty) ? 0 : display.sqlModel
            Layout.fillHeight: true
            Layout.fillWidth: true
            dataDelegate: display.itemDelegate
            emptyDelegate:  display.emptyDelegate
            sectionDelegate:  display.sectionDelegate
            enabled: display.enabled
            Layout.minimumWidth: childrenRect.width
            Layout.minimumHeight: childrenRect.height
            Layout.maximumHeight: parent.height//-upArea.height
            Layout.maximumWidth: parent.width
            onSelected: {
                display.selected(selectedItem);
            }
        }
    }

}
