import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import PreCheck 1.0

/*!
  \class  SH_CommonPage
  */
Item {
    id: commonPage
    signal quit();
    signal selected(string selectedItem)
    signal keySelected(string selectedKey)
    signal cancelProcess()
    signal confirm()
    signal validate()
    signal replace(string field)
    signal cancelReplace()
    signal reload()
    property QtObject streamBuffer: buff
    QtObject {
        id: buff
        property string content: ""
        property bool upperCase: false
        property bool cleared: true
        signal buffer(string text)
        signal eraseLastChar()
        signal clearBuffer()
        onBuffer: {
            var value = (buff.upperCase) ? text.toLocaleUpperCase() : text;
            if(buff.content==="") {
                buff.content = value;
                rightOutput.displayNew(value, (value.length === 1));
            } else {
                buff.content += value;
                rightOutput.display(value);
            }
            buff.cleared = false;
        }
        onEraseLastChar: {
            if(buff.content!=="") {
                buff.content = buff.content.slice(0,-1);
                rightOutput.replace(buff.content);
            }
        }
        onClearBuffer: {
            if(!buff.cleared){
                commonPage.selected(buff.content);
            }
            buff.content = "";
            buff.cleared = true;
        }
    }
    onReload: {
        tabs.reload();
    }
    onSelected: {
        console.log("selection: "+selectedItem);
        App.receiveInput(selectedItem);
    }
    onCancelProcess: {
        App.stopRunningStateMachine();
        console.log("processus interrompu");
    }
    onValidate: {
        App.receiveValidation();
    }
    onConfirm: {
        App.receiveConfirmation();
    }
    onReplace: {
        App.replaceInput(field);
    }
    onCancelReplace: {
        App.cancelReplacement();
    }

    onKeySelected: {
        commonPage.streamBuffer.buffer(selectedKey);
    }
    function displayFileDialog() {
        fileDialog.open();
    }

    FileDialog {
        id: fileDialog
        title: "Veuillez choisir un fichier"
        selectMultiple: false
        selectFolder: false
        onAccepted: {
            if(fileDialog.filePath !== "") {
                commonPage.selected(fileDialog.filePath);
            }
        }
        onRejected: {
            fileDialog.close();
        }
    }
    GridLayout {
        id:main
        columnSpacing: 2
        rowSpacing: 4
        width: parent.width
        height: parent.height
        anchors.fill: parent
        flow: GridLayout.TopToBottom
        rows: 2
        columns: 2
        /*la partie supérieure du panel de gauche est remplie par des onglets et leur contenu*/
        SH_TabZone {
            id: tabs
            objectName: "TabView"
            Layout.alignment: Qt.AlignTop
            Layout.minimumWidth: main.width/2-main.columnSpacing
            Layout.minimumHeight: 7*main.height/12-main.rowSpacing
            Layout.fillWidth: true
            Layout.fillHeight: true
            enabled:true
            stdKeyboard: [
                char10Action, char11Action, char12Action, char13Action, char14Action, char15Action, char16Action, char17Action, char18Action, char19Action, capsAction,
                char20Action, char21Action, char22Action, char23Action, char24Action, char25Action, char26Action, char27Action, char28Action, char29Action, dotAction,
                char30Action, char31Action, char32Action, char33Action, char34Action, char35Action, char36Action, char37Action, char38Action, char39Action, spaceAction,
                char40Action, char41Action, char42Action, char43Action, char44Action, char45Action, char46Action, char47Action, char48Action, char49Action, commaAction,
                char50Action, char51Action, char52Action, char53Action, char54Action, char55Action, char56Action, char57Action, char58Action, char59Action, quoteAction,
                char60Action, char61Action, char62Action, char63Action, char64Action, char65Action, char66Action, char67Action, char68Action, char69Action, quote2Action
            ]

            onSelected: {
                commonPage.keySelected(selectedItem);
            }
            onSelectedForDetail: {
                rightOutput.selectedForDetail(datas.data(row));
            }
        }
        RowLayout {
            Layout.alignment: Qt.AlignBottom
            Layout.minimumWidth: main.width/2-main.columnSpacing
            Layout.minimumHeight: 5*main.height/12-main.rowSpacing
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0
            /*la partie inférieure du panel de gauche contient le clavier, avec les TVA à l'extrême gauche en mode RECEPTION*/
            SH_SqlColumn {
                id: vatSidePanel
                model: SH_VATModel { }
                delegateSource: "SH_VATDelegate.qml"
                onSelected: commonPage.keySelected(selectedItem);
                Layout.minimumWidth: parent.width/10;
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignTop
            }
            SH_Keyboard{
                id: keys
                enabled:true
                Layout.maximumWidth: parent.width*9/10;
                Layout.fillWidth: true
                Layout.fillHeight: true
                columns: 5
                actionsList: [
                    abandonAction, cancelAction, eraseAction, sellAction, backAction,
                    leavingRoomAction, digit7Action, digit8Action, digit9Action, plusAction,
                    arrivingAction, digit4Action, digit5Action, digit6Action, timesAction,
                    departureAction, digit1Action, digit2Action, digit3Action, dividesAction,
                    groupBillingAction, doubleNullAction, nullAction, decimalAction, minusAction,
                    escapeAction, enterAction, confirmAction, mainMenuAction, helpAction
                ]
            }
        }
        /*la zone d'affichage remplit toute la moitié de droite*/
        SH_OutputZone {
            id: rightOutput
            objectName: "RightOutput"
            Layout.rowSpan: 2
            Layout.minimumWidth: main.width/2-main.columnSpacing
            Layout.maximumWidth: main.width/2
            Layout.fillHeight: true
            onSelected: {
                commonPage.keySelected(selectedItem);
            }
        }
    }

    Binding {
        target: vatSidePanel
        property: "visible"
        value: true
        when: (App.currentMode === AppMode.RECEPTION)
    }


    Binding {
        target: leavingRoomAction
        property: "enabled"
        value: true
        when: (App.currentMode === AppMode.RECEPTION)
    }

    Binding {
        target: sellAction
        property: "enabled"
        value: true
        when: (App.currentMode === AppMode.RECEPTION)
    }

    Binding {
        target: arrivingAction
        property: "enabled"
        value: true
        when: (App.currentMode === AppMode.RECEPTION)
    }
    Binding {
        target: departureAction
        property: "enabled"
        value: true
        when: (App.currentMode === AppMode.RECEPTION)
    }


    SH_ComplexAction {
        id: abandonAction
        text: qsTr("VALIDER")
        keyShortcut: Qt.Key_unknown

        enabled: commonPage.visible
        onTriggered: commonPage.validate()
    }
    SH_ComplexAction {
        id: cancelAction
        text: qsTr("ANNULER")
        keyShortcut: Qt.Key_Cancel
        /*enabled: commonPage.visible
onTriggered: *//*TODO cancelAction
*/
    }
    SH_ComplexAction {
        id: eraseAction
        text: qsTr("EFFACER")
        keyShortcut: Qt.Key_Delete
        /*enabled: commonPage.visible
onTriggered: *//*TODO eraseAction*/
    }
    SH_ComplexAction {
        id: sellAction
        text: qsTr("VENDRE")
        keyShortcut: Qt.Key_unknown
        enabled: commonPage.visible
        onTriggered: {
            if(sellAction.enabled) {
                tabs.newSelling()
            }
        }
    }
    SH_ComplexAction {
        id: backAction
        text: qsTr("RETOUR")
        keyShortcut: Qt.Key_Backspace
        enabled: commonPage.visible
        onTriggered: commonPage.streamBuffer.eraseLastChar();
    }

    SH_ComplexAction {
        id: leavingRoomAction
        text: qsTr("LIBÉRER")
        keyShortcut: Qt.Key_unknown
        enabled: commonPage.visible
        onTriggered: {
            if(leavingRoomAction.enabled) {
                /*TODO leavingRoomAction*/
            }
        }
    }
    SH_ComplexAction {
        id: digit7Action
        text: qsTr("7")
        keyShortcut: Qt.Key_7
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit8Action
        text: qsTr("8")
        keyShortcut: Qt.Key_8
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit9Action
        text: qsTr("9")
        keyShortcut: Qt.Key_9
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: plusAction
        text: qsTr("+")
        keyShortcut: Qt.Key_Plus
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }

    SH_ComplexAction {
        id: arrivingAction
        text: qsTr("ARRIVÉE")
        keyShortcut: Qt.Key_unknown
        enabled: commonPage.visible
        onTriggered: {
            if(arrivingAction.enabled) {
                tabs.newBilling();
            }
        }
    }
    SH_ComplexAction {
        id: digit4Action
        text: qsTr("4")
        keyShortcut: Qt.Key_4

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit5Action
        text: qsTr("5")
        keyShortcut: Qt.Key_5

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit6Action
        text: qsTr("6")
        keyShortcut: Qt.Key_6

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: timesAction
        text: qsTr("*")
        keyShortcut: Qt.Key_multiply

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }

    SH_ComplexAction {
        id: departureAction
        text: qsTr("DÉPART")
        keyShortcut: Qt.Key_unknown
        /*enabled: commonPage.visible
onTriggered: */ /*TODO departureAction*/
    }
    SH_ComplexAction {
        id: digit1Action
        text: qsTr("1")
        keyShortcut: Qt.Key_1

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit2Action
        text: qsTr("2")
        keyShortcut: Qt.Key_2

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit3Action
        text: qsTr("3")
        keyShortcut: Qt.Key_3

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: dividesAction
        text: qsTr("/")
        keyShortcut: Qt.Key_division

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: groupBillingAction
        text: qsTr("GROUPES")
        keyShortcut: Qt.Key_unknown

        /*enabled: commonPage.visible
onTriggered: */ /*TODO groupBillingAction*/
    }
    SH_ComplexAction {
        id: doubleNullAction
        text: qsTr("00")
        keyShortcut: Qt.Key_unknown

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: nullAction
        text: qsTr("0")
        keyShortcut: Qt.Key_0

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: decimalAction
        text: qsTr(",")
        keyShortcut: Qt.Key_Period

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: minusAction
        text: qsTr("-")
        keyShortcut: Qt.Key_Minus

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text);
    }

    SH_ComplexAction {
        id: escapeAction
        text: qsTr("ÉCHAP")
        keyShortcut: Qt.Key_Escape
        enabled: commonPage.visible
        onTriggered: commonPage.cancelProcess()
    }
    SH_ComplexAction {
        id: enterAction
        text: qsTr("ENTRÉE")
        keyShortcut: Qt.Key_Enter
        enabled: commonPage.visible
        onTriggered: commonPage.streamBuffer.clearBuffer();
    }
    SH_ComplexAction {
        id: confirmAction
        text: qsTr("CONFIRMER")
        keyShortcut: Qt.Key_Return
        enabled: commonPage.visible
        onTriggered: {
            commonPage.confirm();
        }
    }
    SH_ComplexAction {
        id: mainMenuAction
        text: qsTr("MENU")
        keyShortcut: Qt.Key_unknown
        enabled: commonPage.visible
        onTriggered: {
            commonPage.cancelProcess();
            commonPage.quit();
        }
    }
    SH_ComplexAction {
        id: helpAction
        text: qsTr("AIDE")
        keyShortcut: Qt.Key_unknown
        /*enabled: commonPage.visible
onTriggered: */ /*TODO helpAction*/
    }


    SH_ComplexAction {
        id: char10Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Q") : qsTr("q")
        keyShortcut: Qt.Key_Q
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char11Action
        text: commonPage.streamBuffer.upperCase ? qsTr("W") : qsTr("w")
        keyShortcut: Qt.Key_W
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char12Action
        text: commonPage.streamBuffer.upperCase ? qsTr("E") : qsTr("e")
        keyShortcut: Qt.Key_E
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char13Action
        text: commonPage.streamBuffer.upperCase ? qsTr("R") : qsTr("r")
        keyShortcut: Qt.Key_R
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char14Action
        text: commonPage.streamBuffer.upperCase ? qsTr("T") : qsTr("t")
        keyShortcut: Qt.Key_T
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char15Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Z") : qsTr("z")
        keyShortcut: Qt.Key_Z
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char16Action
        text: commonPage.streamBuffer.upperCase ? qsTr("U") : qsTr("u")
        keyShortcut: Qt.Key_U
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char17Action
        text: commonPage.streamBuffer.upperCase ? qsTr("I") : qsTr("i")
        keyShortcut: Qt.Key_I
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char18Action
        text: commonPage.streamBuffer.upperCase ? qsTr("O") : qsTr("o")
        keyShortcut: Qt.Key_O
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char19Action
        text: commonPage.streamBuffer.upperCase ? qsTr("P") : qsTr("p")
        keyShortcut: Qt.Key_P
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char20Action
        text: commonPage.streamBuffer.upperCase ? qsTr("É") : qsTr("é")
        keyShortcut: Qt.Key_Eacute
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char21Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ẽ") : qsTr("è")
        keyShortcut: Qt.Key_Egrave
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char22Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ê") : qsTr("ê")
        keyShortcut: Qt.Key_Ecircumflex
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char23Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ë") : qsTr("ë")
        keyShortcut: Qt.Key_Ediaeresis
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char24Action
        text: commonPage.streamBuffer.upperCase ? qsTr("À") : qsTr("à")
        keyShortcut: Qt.Key_Agrave
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char25Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Â") : qsTr("â")
        keyShortcut: Qt.Key_Acircumflex
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char26Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ä") : qsTr("ä")
        keyShortcut: Qt.Key_Adiaeresis
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char27Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ï") : qsTr("ï")
        keyShortcut: Qt.Key_Idiaeresis
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char28Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ù") : qsTr("ù")
        keyShortcut: Qt.Key_Ugrave
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char29Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Û") : qsTr("û")
        keyShortcut: Qt.Key_Ucircumflex
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char30Action
        text: commonPage.streamBuffer.upperCase ? qsTr("A") : qsTr("a")
        keyShortcut: Qt.Key_A
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char31Action
        text: commonPage.streamBuffer.upperCase ? qsTr("S") : qsTr("s")
        keyShortcut: Qt.Key_S
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char32Action
        text: commonPage.streamBuffer.upperCase ? qsTr("D") : qsTr("d")
        keyShortcut: Qt.Key_D
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char33Action
        text: commonPage.streamBuffer.upperCase ? qsTr("F") : qsTr("f")
        keyShortcut: Qt.Key_F
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char34Action
        text: commonPage.streamBuffer.upperCase ? qsTr("G") : qsTr("g")
        keyShortcut: Qt.Key_G
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char35Action
        text: commonPage.streamBuffer.upperCase ? qsTr("H") : qsTr("h")
        keyShortcut: Qt.Key_H
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char36Action
        text: commonPage.streamBuffer.upperCase ? qsTr("J") : qsTr("j")
        keyShortcut: Qt.Key_J
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char37Action
        text: commonPage.streamBuffer.upperCase ? qsTr("K") : qsTr("k")
        keyShortcut: Qt.Key_K
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char38Action
        text: commonPage.streamBuffer.upperCase ? qsTr("L") : qsTr("l")
        keyShortcut: Qt.Key_L
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char39Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ö") : qsTr("ö")
        keyShortcut: Qt.Key_Odiaeresis
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char40Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Y") : qsTr("y")
        keyShortcut: Qt.Key_Y
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char41Action
        text: commonPage.streamBuffer.upperCase ? qsTr("X") : qsTr("x")
        keyShortcut: Qt.Key_X
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char42Action
        text: commonPage.streamBuffer.upperCase ? qsTr("C") : qsTr("c")
        keyShortcut: Qt.Key_C
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char43Action
        text: commonPage.streamBuffer.upperCase ? qsTr("V") : qsTr("v")
        keyShortcut: Qt.Key_V
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char44Action
        text: commonPage.streamBuffer.upperCase ? qsTr("B") : qsTr("b")
        keyShortcut: Qt.Key_B
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char45Action
        text: commonPage.streamBuffer.upperCase ? qsTr("N") : qsTr("n")
        keyShortcut: Qt.Key_N
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char46Action
        text: commonPage.streamBuffer.upperCase ? qsTr("M") : qsTr("m")
        keyShortcut: Qt.Key_M
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char47Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Î") : qsTr("î")
        keyShortcut: Qt.Key_Icircumflex
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char48Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ç") : qsTr("ç")
        keyShortcut: Qt.Key_Ccedilla

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char49Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ô") : qsTr("ô")
        keyShortcut: Qt.Key_Ocircumflex

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char50Action
        text: commonPage.streamBuffer.upperCase ? qsTr("Ñ") : qsTr("ñ")
        keyShortcut: Qt.Key_Ntilde

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char51Action
        text: qsTr("&")
        keyShortcut: Qt.Key_Ampersand

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char52Action
        text: qsTr("@")
        keyShortcut: Qt.Key_At

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char53Action
        text: qsTr("+")
        keyShortcut: Qt.Key_Plus

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char54Action
        text: qsTr("_")
        keyShortcut: Qt.Key_Underscore

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char55Action
        text: qsTr("(")
        keyShortcut: Qt.Key_BracketLeft

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char56Action
        text: qsTr(")")
        keyShortcut: Qt.Key_BracketRight

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char57Action
        text: qsTr("-")
        keyShortcut: Qt.Key_hyphen

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char58Action
        text: qsTr("?")
        keyShortcut: Qt.Key_Question

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char59Action
        text: qsTr("!")
        keyShortcut: Qt.Key_Exclam

        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char60Action
        text: qsTr("%")
        keyShortcut: Qt.Key_Percent
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char61Action
        text: qsTr(":")
        keyShortcut: Qt.Key_Semicolon
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char62Action
        text: qsTr("<")
        keyShortcut: Qt.Key_Less
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char63Action
        text: qsTr(">")
        keyShortcut: Qt.Key_Greater
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char64Action
        text: qsTr("\\")
        keyShortcut: Qt.Key_Backslash
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char65Action
        text: qsTr("/")
        keyShortcut: Qt.Key_Slash
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char66Action
        text: qsTr("=")
        keyShortcut: Qt.Key_Equal
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char67Action
        text: qsTr("*")
        keyShortcut: Qt.Key_Asterisk
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char68Action
        text: qsTr("°")
        keyShortcut: Qt.Key_degree
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char69Action
        text: qsTr(";")
        keyShortcut: Qt.Key_Colon
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: capsAction
        text: commonPage.streamBuffer.upperCase ? qsTr("min.") : qsTr("MAJ.")
        keyShortcut: Qt.Key_CapsLock
        enabled: commonPage.visible
        onTriggered: commonPage.streamBuffer.upperCase = !commonPage.streamBuffer.upperCase;
    }
    SH_ComplexAction {
        id: dotAction
        text: qsTr(".")
        keyShortcut: Qt.Key_Period
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: commaAction
        text: qsTr(",")
        keyShortcut: Qt.Key_Comma
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: quoteAction
        text: qsTr("'")
        keyShortcut: Qt.Key_Apostrophe
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: quote2Action
        text: qsTr("\"")
        keyShortcut: Qt.Key_QuoteDbl
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: spaceAction
        text: qsTr("ESPACE")
        keyShortcut: Qt.Key_Space
        enabled: commonPage.visible
        onTriggered: commonPage.keySelected(" ");
    }
}

