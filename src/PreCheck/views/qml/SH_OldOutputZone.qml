import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_OutputZone
  */
Rectangle {
    id: output
    visible: true
    color: App.readStringSetting("backgroundColor","outputZone")
    property int lastVisibleRow: -1

    /*onLastVisibleRowChanged: {
        if(output.lastVisibleRow < -1) {
            output.lastVisibleRow = -1;
        }
    }*/
    signal displayProgressBar(real percentage)
    signal display(string text)
    signal displayNewFixed(string text)
    signal displayNew(string text, bool editable)
    signal replace(string text)
    signal selected(string selectedItem)
    signal selectedForDetail(var sqlDatas)
    signal selectedForTableDetail(var sqlTableModel)
    onDisplayProgressBar: {
        if(output.lastVisibleRow < 0) {
            output.lastVisibleRow = 0;
        } else {
            if(rep.itemAt(output.lastVisibleRow).model !== "" && rep.itemAt(output.lastVisibleRow).state !== "progress") {
                output.lastVisibleRow++;
            }
        }
        rep.itemAt(output.lastVisibleRow).model = percentage;
        rep.itemAt(output.lastVisibleRow).state="progress";
    }
    onSelectedForDetail: {
        if(output.lastVisibleRow < 0) {
            output.lastVisibleRow = 0;
        } else {
            if(rep.itemAt(output.lastVisibleRow).model !== "") {
                output.lastVisibleRow++;
            }
        }
        rep.itemAt(output.lastVisibleRow).model = sqlDatas;
        rep.itemAt(output.lastVisibleRow).state="detail";
    }

    onSelectedForTableDetail: {
        if(output.lastVisibleRow < 0) {
            output.lastVisibleRow = 0;
        } else {
            if(rep.itemAt(output.lastVisibleRow).model !== "") {
                output.lastVisibleRow++;
            }
        }
        rep.itemAt(output.lastVisibleRow).model = sqlTableModel;
        rep.itemAt(output.lastVisibleRow).state="table";
    }

    onReplace: {
        if(output.lastVisibleRow > -1) {
            if(rep.itemAt(output.lastVisibleRow).model === "") {
                output.lastVisibleRow = Math.max(0, output.lastVisibleRow-1);
            }
            console.log(text);
            if(text!=="") {
                layout.changeTextDisplay(output.lastVisibleRow,text, rep.itemAt(output.lastVisibleRow).editable);
            } else {
                display(text);
            }
        } else {
            displayNewFixed(text);
        }
    }
    onDisplay: layout.continueTextDisplay(output.lastVisibleRow,text);
    onDisplayNew: layout.changeTextDisplay(output.lastVisibleRow+1,text, editable);
    onDisplayNewFixed: output.displayNew(text, false);

    /*!
      \fn
      \param
      \return

      \brief
      \details
      */
    function clear(row) {
        if(row <= output.lastVisibleRow) {
            if(rep.itemAt(row).model !== "") {
                rep.itemAt(row).model = "";
            } else {
                if(row === output.lastVisibleRow) {
                    output.lastVisibleRow = -1;
                }
                clear(row-1);
            }
        }
    }
    /*!
      \fn
      \param
      \return

      \brief
      \details
      */
    function clearAll() {
        for(var currentRow = 0; currentRow<rep.count; currentRow++) {
            output.clear(currentRow);
        }
        output.lastVisibleRow = -1;
    }
    /*!
      \fn
      \param
      \return

      \brief
      \details
      */
    function displayText(text) {
        layout.changeTextDisplay(output.lastVisibleRow+1,text, false);
    }
    /*!
      \fn
      \param
      \return
      \brief
      \details
      */
    function displayCalendar() {
        if(output.lastVisibleRow < 0) {
            output.lastVisibleRow = 0;
        }
        /*TODO displayCalendar*/
    }

    signal displaySqlDatas(variant sqlData);
    onDisplaySqlDatas: {
        if(output.lastVisibleRow < 0) {
            output.lastVisibleRow = 0;
        }
        rep.itemAt(output.lastVisibleRow).model = sqlData;
        rep.itemAt(output.lastVisibleRow).state="choices";
    }


    ColumnLayout {
        id:layout
        anchors.margins: 5
        anchors.fill: output
        height: output.height
        width: output.width
        /*!
          \fn
          \param
          \return

          \brief
          \details
          */
        function changeTextDisplay(row, text, editable) {
            if(text!=="") {
                console.log("change text at "+row+" with "+text);
                if(row < rep.count) {
                    /*if(rep.itemAt(row-1).model === "") {
                    row--;
                }*/
                    if(row > output.lastVisibleRow) {
                        //output.lastVisibleRow = Math.max(0, row);
                        output.lastVisibleRow = row;
                    }
                    rep.itemAt(row).editable = editable;
                    rep.itemAt(row).model = text;
                }
            }
        }
        /*!
          \fn
          \param
          \return

          \brief
          \details
          */
        function continueTextDisplay(row, text) {
            console.log("continue text at "+row+" with "+text);
            if(output.lastVisibleRow<0) {
                output.lastVisibleRow=0;
            }

            if(row < 0) {
                console.log("row < 0");
                layout.changeTextDisplay(row+1, text, false);
            } else {
                /*if(rep.itemAt(row-1).model === "") {
                    row--;
                }*/
                if(row > output.lastVisibleRow) {
                    console.log("row > "+output.lastVisibleRow);
                    layout.changeTextDisplay(output.lastVisibleRow, text, false);
                } else {
                    console.log("row <= 0");
                    if(row >= rep.count) {
                        row = rep.count-1;
                    }
                    rep.itemAt(row).model = rep.itemAt(row).model+text;
                }
            }
        }

        Repeater {
            id: rep
            model: 25
            delegate:
                RowLayout {
                id: row
                property variant model: ""
                property bool editable: true
                Layout.minimumHeight: layout.height / rep.model - layout.spacing -layout.anchors.margins
                Layout.minimumWidth: layout.width-layout.anchors.margins
                Layout.fillWidth: true
                Layout.fillHeight: true
                visible: true
                state: "text"
                states: [
                    State{
                        name: "text"
                        PropertyChanges {
                            target: defaultContent
                            text: row.model
                            readOnly:  !row.editable
                            visible: true
                        }
                        PropertyChanges {
                            target: choiceContent
                            model: 0
                            visible: false
                        }
                        /*PropertyChanges {
                            target: calendarContent
                            visible: false
                        }*/
                        PropertyChanges {
                            target: detailedContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: tableContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: progressBarContent
                            value: 0
                            visible: false
                        }
                    },
                    State{
                        name: "choices"
                        PropertyChanges {
                            target: defaultContent
                            visible: false
                        }
                        PropertyChanges {
                            target: choiceContent
                            model: row.model===""? 0  : row.model
                            visible: true
                        }
                        /*PropertyChanges {
                            target: calendarContent
                            visible: false
                        }*/
                        PropertyChanges {
                            target: detailedContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: tableContent
                            model: 0
                            visible: false
                        }

                        PropertyChanges {
                            target: progressBarContent
                            value: 0
                            visible: false
                        }
                    },
                    State{
                        name: "detail"
                        PropertyChanges {
                            target: defaultContent
                            visible: false
                        }
                        PropertyChanges {
                            target: detailedContent
                            model: row.model===""? 0  : row.model
                            visible: true
                        }
                        PropertyChanges {
                            target: tableContent
                            model: 0
                            visible: false
                        }
                        /*PropertyChanges {
                            target: calendarContent
                            visible: false
                        }*/
                        PropertyChanges {
                            target: choiceContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: progressBarContent
                            value: 0
                            visible: false
                        }
                    },
                    State{
                        name: "progress"
                        PropertyChanges {
                            target: defaultContent
                            visible: false
                        }
                        PropertyChanges {
                            target: detailedContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: tableContent
                            model: 0
                            visible: false
                        }
                        /*PropertyChanges {
                            target: calendarContent
                            visible: false
                        }*/
                        PropertyChanges {
                            target: choiceContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: progressBarContent
                            value: row.model === ""? 0  : row.model
                            visible: true
                        }
                    },
                    State{
                        name: "table"
                        PropertyChanges {
                            target: defaultContent
                            visible: false
                        }
                        PropertyChanges {
                            target: detailedContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: tableContent
                            model: row.model === ""? 0  : 100*row.model
                            visible: true
                        }
                        /*PropertyChanges {
   target: calendarContent
                      visible: false
                                        }*/
                        PropertyChanges {
                            target: choiceContent
                            model: 0
                            visible: false
                        }
                        PropertyChanges {
                            target: progressBarContent
                            value: 0
                            visible: false
                        }
                    }
                ]
                Column {
                    TextEdit {
                        id: defaultContent
                        textFormat: TextEdit.AutoText
                        readOnly:  !row.editable
                        wrapMode: TextEdit.Wrap;
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        font.pointSize: 8
                        color: defaultContent.readOnly ? "gray" : "dimgray"
                    }
                    SH_ContentView {
                        id: choiceContent
                        maxColumns: 4
                        model: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    TableView {
                        id: tableContent
                        model: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    ListView {
                        id: detailedContent
                        model: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
                    ProgressBar {
                        id: progressBarContent
                        minimumValue: 0
                        maximumValue: 100
                        value: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

                    /*SH_CalendarDialog {
                        id: calendarContent
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }*/
                }
            }
        }
    }
}
