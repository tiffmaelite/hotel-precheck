import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/**
  @class
  */
TabView {
    id: tabView
    currentIndex: 0
    signal selected(string selectedItem)
    signal selectedForDetail(var datas, int row)
    property var stdKeyboard: []
    signal reload()
    signal newBilling()
    signal newSelling()
    signal newBooking()
    /**
      @fn openTab
      @param \type int tabIndex
      @return

      @brief
      @details
      */
    function openTab(tabIndex) {
        tabView.currentIndex = tabIndex;
    }
    onNewBilling: {
        App.launchBillingCreation();
    }
    onNewBooking: {
        App.launchBookingCreation();
    }
    onNewSelling: {
        App.launchServiceCharging();
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
            /*tabView.addTab(qsTr("Réservations"), bookingsTab);*/
            /*tabView.addTab(qsTr("Offres"), offersTab);*/
            break;
        case AppMode.MANAGEMENT_Z:
            /*tabView.addTab(qsTr("Clôtures"), accountsTab);*/
        case AppMode.MANAGEMENT_X:
            tabView.addTab(qsTr("Prestations"), servicesEditTab);
            tabView.addTab(qsTr("Chambres"), roomsEditTab);
            tabView.addTab(qsTr("Clients privés"), clientsEditTab);
            tabView.addTab(qsTr("Groupes"), groupsEditTab);
            tabView.addTab(qsTr("Rapports"), reportsTab);
            break;
        case AppMode.ADMINISTRATION :
            /*tabView.addTab(qsTr("Paramètres"), settingsTab);*/
            /*tabView.addTab(qsTr("Utilisateurs"), usersTab);*/
            /*tabView.addTab(qsTr("Design"), skinTab);*/
            break;
        }
    }

    resources: [
        Component {
            id:fullKeyboardTab
            SH_Keyboard {
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
                        SH_DataDelegate {
                            Layout.minimumHeight: childrenRect.height
                            Layout.minimumWidth: childrenRect.width
                            text: qsTr("Autre");
                            value: "0"
                            onClicked: {
                                tabView.selected(value);
                            }
                        }
                        SH_DataDelegate {
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
                SH_SqlDataView {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    enabled: tabView.enabled
                    columns: 6
                    filtersTitle: qsTr("Tri des prestations")
                    sqlModel: SH_ServicesModel { }
                    itemDelegate: "SH_ServicesDelegate.qml"
                    emptyDelegate: "SH_DataDelegate.qml"
                    sectionDelegate: "SH_DataDelegate.qml"
                    onSelected: {
                        tabView.selected(selectedItem);
                    }
                }
            }
        },
        Component {
            id: servicesEditTab
            SH_SqlTableView {
                id: servicesEditView
                model: SH_ServicesModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(servicesEditView.model, selectedData);
                }
            }
        },
        Component {
            id: roomsTab
            SH_SqlDataView {
                filtersTitle: qsTr("Tri des chambres")
                sqlModel: SH_RoomsModel { }
                itemDelegate: "SH_RoomsDelegate.qml"
                emptyDelegate: "SH_DataDelegate.qml"
                sectionDelegate: "RoomsSectionDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
            }
        },
        Component {
            id: roomsEditTab
            SH_SqlTableView {
                id: roomsEditView
                model: SH_RoomsModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(roomsEditView.model, selectedData);
                }
            }
        },
        Component {
            id: billingsTab
            SH_SqlDataView {
                sqlModel: SH_BillingsModel {}
                filtersTitle: qsTr("Tri des facturations")
                itemDelegate: "SH_BillingsDelegate.qml"
                emptyDelegate: "SH_DataDelegate.qml"
                sectionDelegate: "SH_DataDelegate.qml"
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
            SH_SqlDataView {
                sqlModel: SH_BookingsModel
                filtersTitle: qsTr("Tri des réservations")
                itemDelegate: "SH_BookingsDelegate.qml"
                emptyDelegate: "SH_DataDelegate.qml"
                sectionDelegate: "SH_DataDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
                onNewItem: {
                    tabView.newBooking();
                }
            }
        },
        Component {
            id: groupsEditTab
            SH_SqlTableView {
                id: groupsEditView
                model: SH_GroupsModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(groupsEditView.model, selectedData);
                }
            }
        },
        Component {
            id: clientsEditTab
            SH_SqlTableView {
                id: clientsEditView
                model: SH_ClientsModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(clientsEditView.model, selectedData);
                }
            }
        },
        Component {
            id: reportsTab
            Rectangle {

            }
            /*SH_SqlTableView {
                id: reportsEditView
                model: SH_ServicesModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(reportsEditView.model, selectedData);
                }
            }*/
        }
    ]
}
