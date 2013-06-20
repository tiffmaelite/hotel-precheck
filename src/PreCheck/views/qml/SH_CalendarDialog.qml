import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Rectangle {
    color: "green"
    id: calendar
    property int firstWeekdayIndex: 1
    property string text
    readonly property alias currentDate: calendarBase.currentDate
    readonly property alias currentWeekday: calendarBase.currentWeekday
    readonly property alias currentDay: calendarBase.currentDay
    readonly property alias currentMonth: calendarBase.currentMonth
    readonly property alias currentYear: calendarBase.currentYear
    readonly property alias currentMonthLength: calendarBase.currentMonthLength
    readonly property variant monthsList: [qsTr("Janvier"),qsTr("Février"),qsTr("Mars"), qsTr("Avril"),qsTr("Mai"),qsTr("Juin"),qsTr("Juillet"),qsTr("Août"),qsTr("Septembre"),qsTr("Octobre"),qsTr("Novembre"),qsTr("Décembre")]
    readonly property variant weekdaysList: [qsTr("Di"),qsTr("Lu"),qsTr("Ma"),qsTr("Me"), qsTr("Je"),qsTr("Ve"),qsTr("Sa")]
    signal clicked(date selectedDate)
    signal refresh(date newDate)
    signal selected(string selectedDate)
    signal closed()
    signal opened()
    visible: true
    onClosed: {
        calendar.visible = false;
    }
    onOpened: {
        calendar.visible = true;
    }

    Component.onCompleted: {
        calendar.clicked(new Date());
        calendar.refresh(new Date());
    }
    onClicked: {
        //console.log("selected date "+selectedDate);
        var year = selectedDate.getFullYear();
        var month = selectedDate.getMonth();
        var day = selectedDate.getDate();
        dateDay.text = day;
        dateMonth.text = monthsList[month];
        dateYear.text = year;
        calendar.text = qsTr("%1 - %2 - %3").arg(day).arg(monthsList[month]).arg(year);
    }

    onRefresh: {
        calendarBase.ready = false;
        //console.log("refreshed with date "+newDate);
        calendarBase.currentDate = newDate;
        var year = newDate.getFullYear();
        var month = newDate.getMonth();
        var day = newDate.getDate();
        var monthLength = new Date(year, month+1, 0).getDate(); //javascript Date trick since day count "starts" at 1 whereas month count starts at 0
        var firstWeekday = new Date(year, month, 1).getDay();
        calendarBase.currentWeekday = newDate.getDay();
        calendarBase.currentDay = day;
        calendarBase.currentMonth = month;
        calendarBase.currentYear = year;
        calendarBase.currentMonthLength = monthLength;
        calendarBase.currentMonthFirstWeekday = (calendar.firstWeekdayIndex >= 0 && calendar.firstWeekdayIndex < 7) ? ((firstWeekday - calendar.firstWeekdayIndex) % 7) : firstWeekday;
        //calendarBase.currentMonthLastWeekday = new Date(year, month, new Date(year, month, 0).getDate()).getDay();
        month.text = qsTr("%1 %2").arg(monthsList[month]).arg(year);
        gridRepeater.model = 7 * (Math.ceil(monthLength / 7) + 1);
        calendarBase.ready = true;
    }

    ColumnLayout {
        id: calendarBase
        property date currentDate: new Date()
        property bool ready: true
        property string currentWeekday
        property string currentDay
        property string currentMonth
        property string currentYear
        property int currentMonthLength
        property int currentMonthFirstWeekday
        property int currentMonthLastWeekday
        spacing: 0
        anchors.fill: calendar
        RowLayout {
            id: dateDisplay
            Layout.minimumWidth: childrenRect.width
            Layout.preferredHeight: Math.max(Math.max(dateDay.paintedHeight,dateMonth.paintedHeight),dateYear.paintedHeight)+20
            Layout.fillWidth: true
            Text {
                id: dateDay
                Layout.preferredWidth: calendar.width / 3 - 2
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                id: dateMonth
                Layout.preferredWidth: calendar.width / 3 - 2
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                id: dateYear
                Layout.preferredWidth: calendar.width / 3 - 2
                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea {
                id: dateDisplayArea
                anchors.fill: dateDisplay
                onClicked: {
                    calendar.opened();
                }
                onDoubleClicked: {
                    dateDisplayArea.clicked(mouse);
                }
            }
        }

        Rectangle {
            id: headRow
            color: "red"
            Layout.minimumWidth: childrenRect.width
            Layout.minimumHeight: month.paintedHeight
            Layout.maximumHeight: 3*month.paintedHeight/2
            Layout.fillWidth: true
            RowLayout {
                anchors.fill:headRow
                spacing: 0
                Image {
                    id: previousMonth
                    Layout.preferredHeight: headRow.height
                    fillMode: Image.PreserveAspectFit
                    source: "../img/left.png"
                    Layout.alignment: Qt.AlignLeft
                    Layout.columnSpan: 1
                    MouseArea {
                        id: previousMonthArea
                        enabled: calendarBase.ready
                        anchors.fill: previousMonth
                        onClicked: {
                            calendar.refresh(new Date(calendarBase.currentYear, (calendarBase.currentMonth - 1 % 12), 1));
                        }
                        onDoubleClicked: {
                            previousMonthArea.clicked(mouse)
                        }
                    }
                }
                Text {
                    id: month
                    text:qsTr("%1 %L2").arg(monthsList[calendarBase.currentMonth]).arg(calendarBase.currentYear);
                    Layout.preferredHeight: headRow.height
                    Layout.alignment: Qt.AlignHCenter
                    Layout.columnSpan: 6
                }
                Image {
                    id:nextMonth
                    Layout.alignment: Qt.AlignRight
                    Layout.columnSpan: 1
                    Layout.preferredHeight: headRow.height
                    fillMode: Image.PreserveAspectFit
                    source: "../img/right.png"
                    MouseArea {
                        id:  nextMonthArea
                        enabled: calendarBase.ready
                        anchors.fill: nextMonth
                        onClicked: {
                            calendar.refresh(new Date(calendarBase.currentYear, (calendarBase.currentMonth + 1 % 12), 1));
                        }
                        onDoubleClicked: {
                            nextMonthArea.clicked(mouse)
                        }
                    }
                }
            }
        }
        Rectangle {
            id:grid
            color: "pink"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: childrenRect.height+2
            Layout.preferredWidth: childrenRect.width+2
            GridLayout {
                id: calendarGrid
                anchors.fill:grid
                columns: 7
                flow: Qt.LeftToRight
                //rows: 1 + Math.ceil(calendarBase.currentMonthLength / 7) //unnecessary because of the horizontal flow
                columnSpacing: 1
                rowSpacing: 1
                Repeater {
                    id: gridRepeater
                    //Layout.fillWidth: true //no effect
                    //Layout.fillHeight: true //no effect
                    model : 7 * (Math.ceil(calendarBase.currentMonthLength / 7) + 1)
                    delegate:
                        Rectangle {
                        id: cell
                        //anchors.fill:parent //hides the other cells
                        readonly property real preferredW: (grid.width /7) - calendarGrid.columnSpacing
                        readonly property real preferredH: (grid.height / (Math.ceil(calendarBase.currentMonthLength / 7) + 1)) - calendarGrid.RowSpacing
                        readonly property real minW: cellText.paintedWidth+3
                        readonly property real minH: cellText.paintedHeight+5
                        Layout.minimumHeight: Math.min(cell.preferredH, cell.minH)
                        Layout.minimumWidth: Math.min(cell.preferredW, cell.minW)
                        Layout.preferredWidth: Math.max(cell.preferredW, cell.minW)
                        Layout.preferredHeight: Math.max(cell.preferredH, cell.minH)
                        readonly property int previousMonthLength: new Date(currentYear, currentMonth, 0).getDate()
                        readonly property int dayIndexInMonth : (index < 7) ? // // 1ère ligne (liste des jours de la semaine) ?
                                                                              0 : //pas de compteur
                                                                              (index - 7 - calendarBase.currentMonthFirstWeekday + 1) // sinon, on soustrait du compteur les 7 cases sans compteurs, puis de nouveau le nombre de colonnes de décalage avec le début du mois
                        property int dayIndex: (index < 7) ? // 1ère ligne (liste des jours de la semaine) ?
                                                             0 : ( //pas de compteur
                                                                  (dayIndexInMonth <= 0 ) ? // avant le début du mois ?
                                                                                            (dayIndexInMonth + previousMonthLength) : ( // date dans le mois précédent
                                                                                                                                       (dayIndexInMonth > currentMonthLength) ? // après la fin du mois ?
                                                                                                                                                                                (dayIndexInMonth - currentMonthLength) : //date dans le mois suivant (nombre de jours du mois suivant)
                                                                                                                                                                                dayIndexInMonth // sinon : date dans le mois
                                                                                                                                       )
                                                                  )
                        color: (index < 7) ? "white" :
                                             (dayIndexInMonth <= 0 || dayIndexInMonth > currentMonthLength) ? // en dehors du mois ?
                                                                                                              "lightgrey" :
                                                                                                              ((cell.dayIndexInMonth === calendarBase.currentDay) ? "blue" : "lightsteelblue")
                        border.width: 1
                        border.color: "darkblue"

                        Text {
                            id: cellText
                            text: (index < 7) ? // 1ère ligne (liste des jours de la semaine) ?
                                                calendar.weekdaysList[(index+calendar.firstWeekdayIndex) % 7] :
                                                cell.dayIndex.toString() //sinon le numéro de jour
                            horizontalAlignment: Text.AlignHCenter
                            anchors.centerIn: cell
                        }
                        MouseArea {
                            id: cellArea
                            anchors.fill: cell
                            onPressed: {
                                cell.color = "lightblue";
                            }
                            onReleased: {
                                cell.color = (index < 7) ? "white" : ((cell.dayIndexInMonth === calendarBase.currentDay) ? "blue" : "lightsteelblue");
                            }

                            onClicked: {
                                var d = new Date(calendarBase.currentYear, calendarBase.currentMonth, cellText.text);
                                calendar.clicked(d);
                                calendar.selected(d.toLocaleDateString());
                                calendar.closed();
                            }
                            onDoubleClicked: {
                                cellArea.clicked(mouse)
                            }
                        }
                    }
                }
            }
        }
    }
}
