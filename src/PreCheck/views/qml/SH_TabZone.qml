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
    signal openingBill()
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
    onOpeningBill: {
        openTab(3);
    }
    style: TabViewStyle {
        id:style
        frameOverlap: 0
        frame:
            Rectangle {
            anchors.centerIn: parent
            height: tabView.implicitHeight
            width: tabView.implicitWidth
            color: App.readStringSetting("backgroundColor","globalGUI")
            border.color: "silver"

            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.color: "silver"
                anchors.margins: -1
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
        //console.log("\n\nélément n°"+index);
        var model = rep.model;
        if(model === 0 || model.rowCount() <= 0) {
            console.log("Modèle vide");
            return 0;
        }
        var next = 0;
        var id = model.data(model.modelIndex(index, 0), 256);
        /*console.log("élément d'ID " + id+" ("+ model.data(model.modelIndex(index, 1), 256+1)+")");
        if(isCoordRow) {
            console.log("\ncalcul de l'indice de ligne");
        } else {
            console.log("\ncalcul de l'indice de colonne");
        }*/
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
            /*if(isAlongDisposition) {
                console.log("le calcul se fait dans le sens non limité");
            }
            if(sectioning) {
                if(previousSection !== currentSection) {
                    console.log("nouvelle section ("+model.field(sectionIndex).text+") : "+currentSection);
                } else{
                    console.log("même section ("+model.field(sectionIndex).text+") : "+currentSection);
                }
            }
            console.log("previousOtherCoord: "+previousOtherCoord+", totalOtherCoord: "+totalOtherCoord+", previousSameCoord:"+previousSameCoord+", totalSameCoord:"+totalSameCoord);*/

            //dans le cas où la ligne/colonne de l'élément précédent avait atteint la limite, ou qu'il s'agit d'une nouvelle section
            if((sectioning && (previousSection !== currentSection)) || (totalOtherCoord > 0 && ((previousOtherCoord + 1) % totalOtherCoord == 0))) {
                if(isAlongDisposition) {
                    //console.log("nouvelle ligne/colonne dans le sens non limité");
                    next = previousSameCoord + 1;
                } else {
                    //console.log("retour au début dans le sens non limité")
                    next = 0;
                }
                //dans le cas où on continue normalement
            } else {
                if(isAlongDisposition) {
                    //console.log("même ligne/colonne");
                    next = previousSameCoord;
                } else {
                    //console.log("ligne/colonne suivante");
                    next = previousSameCoord + 1;
                }
            }
            //on corrige les cas de dépassements étranges
            if(!isAlongDisposition && (next >= totalSameCoord)) {
                next = next % totalSameCoord;
            }
            /*on adapte pour éviter les impossibilités*/
            next = Math.max(next, 0);
            if(totalSameCoord > 0) {
                next = Math.min(next, totalSameCoord);
            }
            //console.log("successeur de [" + previousRow + ", " + previousColumn+"]");
        }
        /*if(isCoordRow) {
            console.log("ligne finale "+next);
        } else {
            console.log("colonne finale "+next);
        }*/
        return next;
    }


    resources: [
        Component {
            id:fullKeyboardTab
            SH_Keyboard {
                id:fullKeyboard
                actionsList: stdKeyboard
                columns: 11
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
            }
        },
        Component {
            id: servicesTab
            GridLayout {
                id: servicesPanel
                enabled: tabView.enabled
                height: tabView.implicitHeight-2*servicesPanel.rowSpacing
                width: tabView.implicitWidth-2*servicesPanel.columnSpacing
                flow: GridLayout.LeftToRight
                columns: servicesRep.model === 0 ? 0 : servicesPanel.maxColumns
                rowSpacing: 1
                columnSpacing: 1
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
                        Layout.maximumHeight: servicesRep.itemHeight
                        Layout.maximumWidth: servicesRep.itemWidth
                        Layout.row: computeCoord(servicesRep, index, servicesPanel, true)
                        Layout.column: computeCoord(servicesRep, index, servicesPanel, false)
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        onClicked: {
                            tabView.selected(servicesRep.itemAt(index).value);
                        }
                        /*Component.onCompleted: {
                            console.log(index+": ["+Layout.row+", "+Layout.column+"]");
                        }*/
                    }
                }
            }
        },
        Component {
            id: servicesEditTab
            SH_SqlTableView {
                id: servicesEditView
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
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
                rowSpacing: 1
                columnSpacing: 1
                enabled: tabView.enabled
                height: tabView.implicitHeight-2*roomsPanel.rowSpacing
                width: tabView.implicitWidth-2*roomsPanel.columnSpacing
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
                        Layout.maximumHeight: roomsRep.itemHeight
                        Layout.maximumWidth: roomsRep.itemWidth
                        Layout.row: computeCoord(roomsRep, index, roomsPanel, true)
                        Layout.column: computeCoord(roomsRep, index, roomsPanel, false)
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        onClicked: {
                            tabView.selected(roomsRep.itemAt(index).value);
                        }
                        Component.onCompleted: {
                            console.log(index+": ["+Layout.row+", "+Layout.column+"]");
                        }
                    }
                }
            }
        },
        Component {
            id: roomsEditTab
            SH_SqlTableView {
                id: roomsEditView
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
                model: SH_RoomsModel { }
                onSelectedRow: {
                    tabView.selectedForDetail(roomsEditView.model.data(selectedData));
                }
            }
        },
        Component {
            id: billingsTab
            GridLayout {
                id: billingsPanel
                enabled: tabView.enabled
                height: tabView.implicitHeight-2*billingsPanel.rowSpacing
                width: tabView.implicitWidth-2*billingsPanel.columnSpacing
                flow: GridLayout.LeftToRight
                columns: billingsRep.model === 0 ? 0 : billingsPanel.maxColumns
                rowSpacing: 1
                columnSpacing: 1
                property int maxColumns: 4
                property variant model: SH_BillingsModel { }
                Component.onCompleted: {
                    if(billingsPanel.model.rowCount() > 0) {
                        billingsPanel.columns = Math.min(billingsPanel.model.rowCount(), billingsPanel.maxColumns);
                        billingsRep.model = billingsPanel.model;
                    }
                }
                Repeater {
                    id: billingsRep
                    model: 0
                    property real itemHeight: computeMaxCoord(billingsRep, billingsPanel, true)
                    property real itemWidth: computeMaxCoord(billingsRep, billingsPanel, false)
                    delegate: SH_BillingsDelegate {
                        Layout.maximumHeight: billingsRep.itemHeight
                        Layout.maximumWidth: billingsRep.itemWidth
                        Layout.row: computeCoord(billingsRep, index, billingsPanel, true)
                        Layout.column: computeCoord(billingsRep, index, billingsPanel, false)
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        onClicked: {
                            tabView.selected(billingsRep.itemAt(index).value);
                        }
                        Component.onCompleted: {
                            console.log(index+": ["+Layout.row+", "+Layout.column+"]");
                        }
                    }
                }
            }
        },
        Component {
            id: bookingsTab
            GridLayout {
                id: bookingsPanel
                enabled: tabView.enabled
                height: tabView.implicitHeight-2*bookingsPanel.rowSpacing
                width: tabView.implicitWidth-2*bookingsPanel.columnSpacing
                flow: GridLayout.LeftToRight
                columns: bookingsRep.model === 0 ? 0 : bookingsPanel.maxColumns
                rowSpacing: 1
                columnSpacing: 1
                property int maxColumns: 4
                property variant model: SH_BookingsModel { }
                Component.onCompleted: {
                    if(bookingsPanel.model.rowCount() > 0) {
                        bookingsPanel.columns = Math.min(bookingsPanel.model.rowCount(), bookingsPanel.maxColumns);
                        bookingsRep.model = bookingsPanel.model;
                    }
                }
                Repeater {
                    id: bookingsRep
                    model: 0
                    property real itemHeight: computeMaxCoord(bookingsRep, bookingsPanel, true)
                    property real itemWidth: computeMaxCoord(bookingsRep, bookingsPanel, false)
                    delegate: SH_BookingsDelegate {
                        Layout.maximumHeight: bookingsRep.itemHeight
                        Layout.maximumWidth: bookingsRep.itemWidth
                        Layout.row: computeCoord(bookingsRep, index, bookingsPanel, true)
                        Layout.column: computeCoord(bookingsRep, index, bookingsPanel, false)
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        onClicked: {
                            tabView.selected(bookingsRep.itemAt(index).value);
                        }
                        Component.onCompleted: {
                            console.log(index+": ["+Layout.row+", "+Layout.column+"]");
                        }
                    }
                }
            }
        },
        Component {
            id: groupsEditTab
            SH_SqlTableView {
                id: groupsEditView
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
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
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
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
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
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
                enabled: tabView.enabled
                height: tabView.implicitHeight
                width: tabView.implicitWidth
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
