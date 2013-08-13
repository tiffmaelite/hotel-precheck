import QtQuick 2.1
import QtQml.Models 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_TabZone
  */
TabView {
    id: tabView
    currentIndex: 0
    signal selected(string selectedItem)
    signal selectedForDetail(var datas, int row)
    property variant stdKeyboard: []
    signal reload()
    signal newBilling()
    signal newSelling()
    signal newBooking()
    /*!
      \fn openTab
      \param \type int tabIndex
      \return

      \brief
      \details
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
        frame:
            Rectangle {
            anchors.fill: parent
            height: tabView.height-style.frameOverlap
            width: tabView.width
            color: App.readStringSetting("backgroundColor","globalGUI")
            border.color: "silver"

            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.color: "silver"
                anchors.margins: 2
            }
        }
        /*tab:
            Rectangle {
            color: styleData.selected ? "lightgrey" :"whitesmoke"
            border.color:  "silver"
            implicitWidth: Math.max(text.width + 4, 80)
            implicitHeight: 20
            radius: 2
            RowLayout {
                Image {
                    visible:(styleData.title===qsTr("Clavier complet"))
                    source: (styleData.title===qsTr("Clavier complet")) ? "../icons/keyboard.png" : "" ;
                    Layout.maximumHeight: 15
                    fillMode: Image.PreserveAspectFit
                }
                Text {
                    id: text
                    anchors.centerIn: parent
                    text: styleData.title
                    color: styleData.selected ? "black" : "grey"
                }
            }
        }*/
    }

    Component.onCompleted: {
        tabView.addTab(qsTr("Clavier complet"), fullKeyboardTab);
        tabView.reload();
    }
    onReload: {
        var nbTabs = tabView.count;
        for(var i = nbTabs-1; i > 0; i--) {
            tabView.removeTab(i);
        }
        switch(App.currentMode) {
        case AppMode.RECEPTION:
            tabView.addTab(qsTr("Prestations"), servicesTab);
            //tabView.addTab(qsTr("Chambres"), roomsTab);
            //tabView.addTab(qsTr("Facturations"), billingsTab);
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
            tabView.addTab(qsTr("Utilisateurs"), usersTab);
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
            /*SH_SqlDataView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                enabled: tabView.enabled
                //columns: 5 //6
                filtersTitle: qsTr("Tri des prestations")
                sqlModel: SH_ServicesModel { }
                itemDelegate: "SH_ServicesDelegate.qml"
                emptyDelegate: "SH_DataDelegate.qml"
                sectionDelegate: "SH_DataDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
            }*/
            GridLayout {
                id: servicesGrid
                Layout.fillWidth: true
                Layout.fillHeight: true
                enabled: tabView.enabled
                columns: 5 //6
                Repeater {
                    id: servicesRep
                    model: SH_VATDelegate {
                        property double maxHeight: servicesRep.count <= 0 ? 0 : ((servicesGrid.flow === GridLayout.TopToBottom) ? Math.floor(servicesGrid.height / servicesGrid.rows) : (Math.floor(servicesGrid.height * (servicesGrid.columns) / servicesRep.count)))
                        property double maxWidth: servicesRep.count <= 0 ? 0 : ((layout.flow === GridLayout.LeftToRight) ? Math.floor(servicesGrid.width / servicesGrid.columns) : (Math.floor(servicesGrid.width * (servicesGrid.rows / servicesRep.count))))
                        Layout.maximumHeight: Math.max(0,maxHeight - servicesGrid.rowSpacing)
                        Layout.maximumWidth: Math.max(0,maxWidth - servicesGrid.columnSpacing)
                        onClicked: {
                            tabView.selected(servicesRep.itemAt(index).value);
                        }
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
                    tabView.selectedForDetail(servicesEditView.model.data(selectedData));
                }
            }
        },
        Component {
            id: roomsTab
            /*SH_SqlDataView {
                filtersTitle: qsTr("Tri des chambres")
                sqlModel: SH_RoomsModel { }
                itemDelegate: "SH_RoomsDelegate.qml"
                emptyDelegate: "SH_DataDelegate.qml"
                sectionDelegate: "RoomsSectionDelegate.qml"
                onSelected: {
                    tabView.selected(selectedItem);
                }
            }*/
            SH_SqlGrid {
                delegateSource: "SH_RoomsDelegate.qml"
                columns: 6
                model: SH_RoomsModel { }
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
                    tabView.selectedForDetail(roomsEditView.model.data(selectedData));
                }
            }
        },
        Component {
            id: billingsTab
            /*SH_SqlDataView {
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
            }*/
            SH_SqlGrid {
                delegateSource: "SH_BillingsDelegate.qml"
                columns: 6
                model: SH_BillingsModel { }
                onSelected: {
                    tabView.selected(selectedItem);
                }
            }
        },
        Component {
            id: bookingsTab
            /*SH_SqlDataView {
                sqlModel: SH_BookingsModel { }
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
            }*/
            SH_SqlGrid {
                delegateSource: "SH_BookingsDelegate.qml"
                columns: 6
                model: SH_BookingsModel { }
                onSelected: {
                    tabView.selected(selectedItem);
                }
            }
        },
        Component {
            id: groupsEditTab
            SH_SqlTableView {
                id: groupsEditView
                model: SH_GroupsModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(groupsEditView.model.data(selectedData));
                }
            }
        },
        Component {
            id: clientsEditTab
            SH_SqlTableView {
                id: clientsEditView
                model: SH_ClientsModel {  }
                onSelectedRow: {
                    tabView.selectedForDetail(clientsEditView.model.data(selectedData));
                }
            }
        },
        Component {
            id: reportsTab
            SH_SqlTableView {
                id: reportsTypesEditView
                model: SH_ReportsTypesModel { }
                onSelectedRow: {
                    if(!reportsTypesEditView.model.empty) {
                        reportComponentModel.functionCall=reportsTypesEditView.model.data(selectedData,reportsTypesEditView.model.fieldsCount()-1);
                        reportComponentModel.fetch();
                        tabView.selectedForTableDetail(reportComponentModel);
                    }
                }
                property Component reportComponentModel: SH_ReportsModel { }
            }
        },
        Component {
            id: usersTab
            Rectangle {
                ColumnLayout {
                    GroupBox {
                        title: "Nouvel utilisateur"
                        RowLayout {
                            anchors.centerIn: parent
                            width: parent.width
                            height: parent.height
                            Label {
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                text: "Nom d'utilisateur"
                            }
                            TextEdit {
                                id: loginEdit
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }
                            Label {
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                text: "Mot de passe"
                            }
                            TextEdit {
                                id: passEdit
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }
                        }
                        RowLayout {
                            Label {
                                text : "Droits/Accès"
                            }

                            CheckBox {
                                id: traineeCbx
                                text: "Formation (pas encore fonctionnel)"
                                checked: false
                            }
                            CheckBox {
                                id: receptionistCbx
                                text: "Réception"
                                checked: true
                            }
                            CheckBox {
                                id: managerXCbx
                                text: "Responsable avec droits X"
                                checked: false
                            }
                            CheckBox {
                                id: managerZCbx
                                text: "Responsable avec droits Z"
                                checked: false
                            }
                            CheckBox {
                                id:administratorCbx
                                text: "Administrateur"
                                checked: false
                            }
                            Button {
                                text: "Enregistrer"
                                onClicked: {
                                    App.saveUser(loginEdit.text,passEdit.text,traineeCbx.checked, receptionistCbx.checked,  managerXCbx.checked, managerZCbx.checked, administratorCbx.checked);
                                }
                            }
                        }
                    }
                    GroupBox {
                        title: "Utilisateurs existants"
                        ColumnLayout {
                            SH_SqlTableView {
                                id: usersList
                                model: SH_UsersListModel { }
                                onSelectedRow: {
                                    tabView.selectedForDetail(usersList.model.data(selectedData));
                                }
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }

                            SH_SqlTableView {
                                id: traineesList
                                model: SH_TraineesListModel { }
                                onSelectedRow: {
                                    tabView.selectedForDetail(traineesList.model.data(selectedData));
                                }
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }
                        }
                    }
                }
            }
        }
    ]
}
