import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

Rectangle {
    id: defaultOutputZone
    property Component zoneContent
    color: App.readStringSetting("backgroundColor","outputZone")
    state: "cleared"
    states: [
        State {
            name: "qa"
            PropertyChanges {
                target: defaultOutputZone
                zoneContent: qaOut
            }
        },
        State {
            name: "cleared"
            PropertyChanges {
                target: defaultOutputZone
                zoneContent: clearRect
            }
        }
    ]

    signal selected(string selectedItem)

    signal clearAll()
    signal displayProgressBar(real percentage)

    signal display(string text, int row, int column)
    signal displayTextAt(string text, int row)
    signal displayText(string text)
    signal replace(string text, int row, int column)
    signal replaceTextAt(string text, int row)
    signal replaceText(string text)
    signal displaySqlDatas(variant model)
    signal displaySqlDatasAt(variant model, int row)

    onDisplayProgressBar: {
        if(percentage >= progressBarContent.minimumValue && percentage <= progressBarContent.maximumValue) {
            progressBarContent.visible = true;
            progressBarContent.value = percentage;
        } else {
            progressBarContent.visible = false;
        }
    }


    Loader {
        id: contentLoader
        sourceComponent: zoneContent
        Binding {
            target: contentLoader.item
            property: "width"
            value: defaultOutputZone.width
        }
        Binding {
            target: contentLoader.item
            property: "height"
            value: defaultOutputZone.height
        }
        Connections {
            target: contentLoader.item
            onSelected: defaultOutputZone.selected(selectedItem);
        }
        Connections {
            target: defaultOutputZone
            onClearAll: {
                //defaultOutputZone.state = "cleared";
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.clearAll();
                }
            }
            onDisplay: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.display(text, row, column);
                }
            }
            onReplace: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.replace(text, row, column);
                }
            }
            onDisplayText: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.displayText(text);
                }
            }
            onReplaceText: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.replaceText(text);
                }
            }
            onDisplayTextAt: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.displayTextAt(text, row);
                }
            }
            onReplaceTextAt: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.replaceTextAt(text, row);
                }
            }
            onDisplaySqlDatas: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.displaySqlDatas(model);
                }
            }
            onDisplaySqlDatasAt: {
                if(defaultOutputZone.state != "cleared") {
                    contentLoader.item.displaySqlDatasAt(model, row);
                }
            }
        }
    }

    ProgressBar {
        id: progressBarContent
        visible: false
        minimumValue: 0
        maximumValue: 100
        value: 0
        width: defaultOutputZone.width
        height: 5
    }

    Component {
        id: qaOut
        SH_QAOutput { }
    }
    Component {
        id: clearRect
        Rectangle {
            color: "transparent"
            signal selected(string selectedItem);
        }
    }
}

