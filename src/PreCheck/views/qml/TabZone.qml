import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

TabView {
    id: tabView
    currentIndex: 0
    signal selected(string selectedItem)
    signal selectedForDetail(string selectedTable, int selectedRow)
    property var stdKeyboard: []
    signal reload()
    signal newBilling()
    signal newSelling()
    signal newBooking()
    function openTab(tabIndex) {
        tabView.currentIndex = tabIndex;
    }
    onNewBilling: {
        App.launchBillingsThread();
    }
    onNewBooking: {
        App.launchBookingsThread();
    }
    onNewSelling: {
        App.launchBillThread();
    }


    style: TabViewStyle {
        id:style
        frame: Rectangle {
            anchors.fill: parent
            height: tabView.height-style.frameOverlap
            width: tabView.width
            color: "#dcdcdc"
            border.color: "#aaa"

            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.color: "#66ffffff"
                anchors.margins: 2
            }
        }
    }

    Component.onCompleted: {
        tabView.addTab(qsTr("Clavier complet"), fullKeyboardTab);
        tabView.reload();
    }
    onReload: {
        var nbTabs = tabView.count;
        for(var i = 1; i < nbTabs; i++) {
            tabView.removeTab(i)
        }
        switch(App.currentMode) {
        case AppMode.RECEPTION:
            tabView.addTab(qsTr("Prestations"), servicesTab);
            tabView.addTab(qsTr("Chambres"), roomsTab);
            tabView.addTab(qsTr("Facturations"), billingsTab);
            tabView.addTab(qsTr("Réservations"), bookingsTab);
            //tabView.addTab(qsTr("Offres"), offersTab);
            break;
        case AppMode.MANAGEMENT_Z:
            //tabView.addTab(qsTr("Clôtures"), accountsTab);
        case AppMode.MANAGEMENT_X:
            //tabView.addTab(qsTr("Prestations"), servicesEditTab);
            tabView.addTab(qsTr("Chambres"), roomsEditTab);
            //tabView.addTab(qsTr("Clients privés"), clientsEditTab);
            //tabView.addTab(qsTr("Groupes"), groupsEditTab);
            //tabView.addTab(qsTr("Rapports"), reportsTab);
            break;
        case AppMode.ADMINISTRATION :
            //tabView.addTab(qsTr("Paramètres"), settingsTab);
            //tabView.addTab(qsTr("Utilisateurs"), usersTab);
            //tabView.addTab(qsTr("Design"), skinTab);
            break;
        }
    }

    resources: [
        Component {
            id:fullKeyboardTab
            Keyboard {
                id:fullKeyboard
                actionsList: stdKeyboard
                columns: 11
                enabled: tabView.enabled
                height: tabView.height-style.frameOverlap
                width: tabView.width
            }
        },
        Component {
            id: servicesTab
            ColumnLayout {
                Rectangle {
                    color:"transparent"
                    Layout.fillWidth: true
                    Layout.minimumHeight: 20
                    RowLayout {
                        DataDelegate {
                            Layout.minimumHeight: childrenRect.height
                            Layout.minimumWidth: childrenRect.width
                            text: qsTr("Autre");
                            value: "0"
                            onClicked: {
                                tabView.selected(value);
                            }
                        }
                        DataDelegate {
                            Layout.minimumHeight: childrenRect.height
                            Layout.minimumWidth: childrenRect.width
                            text: qsTr("Autre...");
                            value: "-1"
                            onClicked: {
                                tabView.selected(value);
                            }
                        }
                    }
                }
                SqlDataView {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    enabled: tabView.enabled
                    filtersTitle: qsTr("Tri des prestations")
                    sqlModel: ServicesModel { }
                    itemDelegate: "ServicesDelegate.qml"
                    emptyDelegate: "DataDelegate.qml"
                    sectionDelegate: "DataDelegate.qml"
                    onSelected: {
                        tabView.selected(selectedItem);
                    }
                }
            }
        },
        Component {
            id: roomsTab
            SqlDataView {
                filtersTitle: qsTr("Tri des chambres")
                sqlModel: RoomsModel { }
                itemDelegate: "RoomsDelegate.qml"
                emptyDelegate: "DataDelegate.qml"
                sectionDelegate: "RoomsSectionDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
            }
        },
        Component {
            id: roomsEditTab
            SqlTableView {
                id: roomsEditView
                model: RoomsModel { }
                onSelected: {
                    tabView.selectedForDetail(roomsEditView.model.table, selectedItem);
                }
            }
        },
        Component {
            id: billingsTab
            SqlDataView {
                sqlModel: BillingsModel {}
                filtersTitle: qsTr("Tri des facturations")
                itemDelegate: "BillingsDelegate.qml"
                emptyDelegate: "DataDelegate.qml"
                sectionDelegate: "DataDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
                onNewItem: {
                    tabView.newBilling();
                }
            }
        },
        Component {
            id: bookingsTab
            SqlDataView {
                sqlModel: BookingsModel
                filtersTitle: qsTr("Tri des réservations")
                itemDelegate: "BookingsDelegate.qml"
                emptyDelegate: "DataDelegate.qml"
                sectionDelegate: "DataDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
                onNewItem: {
                    tabView.newBooking();
                }
            }
        }

    ]
}
