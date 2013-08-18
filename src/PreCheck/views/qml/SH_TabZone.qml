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
            tabView.addTab(qsTr("Chambres"), roomsTab);
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

    function computeMaxCoord(rep, grid, height) {
        if(rep.model === 0 || rep.model.rowCount() <= 0) {
            return 0;
        }
        var dispositionFlow;
        var alongDispositionMaxSize;
        var alongDispositionDivisions;
        var otherDispositionDivisions;
        var alongDispositionSpacing;
        if(height) {
            dispositionFlow = GridLayout.TopToBottom;
            alongDispositionMaxSize = Math.max(0, grid.height);
            alongDispositionDivisions = Math.max(0, grid.rows);
            otherDispositionDivisions = Math.max(0, grid.columns);
            alongDispositionSpacing = Math.max(0, grid.rowSpacing);
        } else {
            dispositionFlow = GridLayout.LeftToRight;
            alongDispositionMaxSize = Math.max(0, grid.width);
            alongDispositionDivisions = Math.max(0, grid.columns);
            otherDispositionDivisions = Math.max(0, grid.rows);
            alongDispositionSpacing = Math.max(0, grid.columnSpacing);
        }
        var size;
        if(grid.flow === dispositionFlow) {
            size = Math.floor( alongDispositionMaxSize / alongDispositionDivisions);
        } else {
            size = Math.floor((alongDispositionMaxSize * otherDispositionDivisions) / rep.count);
        }
        return Math.max(0,size - alongDispositionSpacing);
    }

    /*!
          \fn computeCoord
          \param \type Repeater rep
          \param \type int index L'indice de l'élément pour lequel effectuer le calcul
          \param \type GridLayout grid
          \param \type bool isCoordRow Indique si l'on calcule un indice de ligne ou pas (un indice de colonne dans le cas contraire)
          \return int l'indice de la ligne désirée (1 étant la première ligne)
          \brief \~french Calcule la ligne à laquelle insérer un élément donné
          \details Prend en compte le tri des éléments et va à la ligne pour toute nouvelle section (définie par le changement de valeur du critère de tri)
          */
    function computeCoord(rep, index, grid, isCoordRow) {
        console.log("\n\nélément n°"+index);
        var model = rep.model;
        if(model === 0 || model.rowCount() <= 0) {
            console.log("Modèle vide");
            return 0;
        }
        var startShift = 0; //1;
        var next = startShift;
        var id = model.data(model.modelIndex(index, 0), 256);
        console.log("élément d'ID " + id+" ("+ model.data(model.modelIndex(index, 1), 256)+")");
        if(isCoordRow) {
            console.log("\ncalcul de l'indice de ligne");
        } else {
            console.log("\ncalcul de l'indice de colonne");
        }
        if(index >= 1) { // on n'a besoin de calculer que pour des éléments ultérieurs au premier car ligne 0 et colonne 0 pour élément d'index 0
            var sectionIndex = Math.max(0,model.sortKeyColumn); //L'indice du champ du modèle selon lequel est effectué le tri des éléments
            var sectioning = (sectionIndex > 0); //sectionIndex=0 <=> tri par les ID <=> pas de tri
            var currentSection = model.data(model.modelIndex(index, sectionIndex), 256+sectionIndex);
            var previousSection = model.data(model.modelIndex(index-1, sectionIndex), 256+sectionIndex);
            var previous = rep.itemAt(index-1);
            var previousRow = previous.Layout.row;
            var previousColumn = previous.Layout.column;

            var previousSameCoord;
            var previousOtherCoord;
            var totalSameCoord;
            var totalOtherCoord;
            var isAlongDisposition;
            if(isCoordRow) {
                previousSameCoord = previousRow;
                previousOtherCoord = previousColumn;
                totalOtherCoord = Math.max(0,grid.columns);
                totalSameCoord = Math.max(0,grid.rows);
                isAlongDisposition = (grid.flow === GridLayout.LeftToRight) && !(grid.flow === GridLayout.TopToBottom);
            } else {
                previousSameCoord = previousColumn;
                previousOtherCoord = previousRow;
                totalOtherCoord = Math.max(0,grid.rows);
                totalSameCoord = Math.max(0,grid.columns);
                isAlongDisposition = (grid.flow === GridLayout.TopToBottom) && !(grid.flow === GridLayout.LeftToRight);
            }
            console.log("indice prédécent selon la même coordonnée : "+previousSameCoord+"/"+totalSameCoord);
            console.log("indice prédécent selon l'autre coordonnée : "+previousOtherCoord+"/"+totalOtherCoord);
            if(isAlongDisposition) {
                console.log("le calcul se fait dans le sens non limité");
            }
            console.log("successeur de [" + previousRow + ", " + previousColumn+"]");
            if(sectioning) {
                if(previousSection !== currentSection) {
                    console.log("nouvelle section ["+model.field(sectionIndex).text+"] : "+currentSection);
                } else{
                    console.log("même section ["+model.field(sectionIndex).text+"] : "+currentSection);
                }
            }

            //dans le cas où la ligne/colonne de l'élément précédent avait atteint la limite, ou qu'il s'agit d'une nouvelle section
            console.log("previousOtherCoord: "+previousOtherCoord+", totalOtherCoord: "+totalOtherCoord+", startShift: "+startShift+", (previousOtherCoord - startShift % totalOtherCoord) + startShift="+((previousOtherCoord - startShift % totalOtherCoord) + startShift));
            if((sectioning && (previousSection !== currentSection)) || ((previousOtherCoord - startShift) >= totalOtherCoord && (totalOtherCoord > 0 && ((previousOtherCoord - startShift % totalOtherCoord) + startShift == 0)))) {
                if(isAlongDisposition) {
                    console.log("nouvelle ligne/colonne dans le sens non limité");
                    next = previousSameCoord + 1;
                } else {
                    console.log("retour au début dans le sens non limité")
                    next = startShift;
                }
                //dans le cas où on continue normalement
            } else {
                if(isAlongDisposition) {
                    console.log("même ligne/colonne");
                    next = previousSameCoord;
                } else {
                    console.log("ligne/colonne suivante");
                    next = previousSameCoord + 1;
                }
            }
            //on corrige les cas de dépassements étranges
            if(!isAlongDisposition) {
                next = next % totalSameCoord + startShift;
            }
        }

        if(isCoordRow) {
            console.log("ligne finale "+next);
        } else {
            console.log("colonne finale "+next);
        }

        return Math.max(next, startShift);//on adapte pour éviter les impossibilités*/
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
            GridLayout {
                id: servicesPanel
                flow: GridLayout.LeftToRight
                columns: servicesRep.model === 0 ? 0 : servicesPanel.maxColumns
                property int maxColumns: 4
                property variant model: SH_ServicesModel { }
                Component.onCompleted: {
                    if(servicesPanel.model.rowCount() > 0) {
                        servicesPanel.columns = Math.min(servicesPanel.model.rowCount(), servicesPanel.maxColumns);
                        servicesRep.model = servicesPanel.model;
                    }
                }
                Repeater {
                    id: servicesRep
                    model: 0
                    property real itemHeight: computeMaxCoord(servicesRep, servicesPanel, true)
                    property real itemWidth: computeMaxCoord(servicesRep, servicesPanel, false)
                    delegate: SH_ServicesDelegate {
                        Layout.minimumHeight: servicesRep.itemHeight
                        Layout.minimumWidth: servicesRep.itemWidth
                        Layout.row: computeCoord(servicesRep, index, servicesPanel, true)
                        Layout.column: computeCoord(servicesRep, index, servicesPanel, false)
                        Layout.fillWidth: true
                        Layout.fillHeight: true
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
            GridLayout {
                id: roomsPanel
                flow: GridLayout.LeftToRight
                columns: roomsRep.model === 0 ? 0 : roomsPanel.maxColumns
                property int maxColumns: 7
                property variant model: SH_RoomsModel { }
                Component.onCompleted: {
                    if(roomsPanel.model.rowCount() > 0) {
                        roomsPanel.columns = Math.min(roomsPanel.model.rowCount(), roomsPanel.maxColumns);
                        roomsRep.model = roomsPanel.model;
                    }
                }
                Repeater {
                    id: roomsRep
                    model: 0
                    property real itemHeight: computeMaxCoord(roomsRep, roomsPanel, true)
                    property real itemWidth: computeMaxCoord(roomsRep, roomsPanel, false)
                    delegate: SH_RoomsDelegate {
                        Layout.minimumHeight: roomsRep.itemHeight
                        Layout.minimumWidth: roomsRep.itemWidth
                        Layout.row: computeCoord(roomsRep, index, roomsPanel, true)
                        Layout.column: computeCoord(roomsRep, index, roomsPanel, false)
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        onClicked: {
                            tabView.selected(roomsRep.itemAt(index).value);
                        }
                    }
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
            /*SH_Sqlgrid {
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
            /*SH_Sqlgrid {
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
