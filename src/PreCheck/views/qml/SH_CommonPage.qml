import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

Item {
    id: SH_CommonPage
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
        signal buffer(string text)
        signal eraseLastChar()
        signal clearBuffer()
        onBuffer: {
            var value = (buff.upperCase) ? text.toLocaleUpperCase() : text.toLocaleLowerCase();
            if(buff.content==="") {
                buff.content = value;
                rightOutput.displayNew(value, (value.length === 1));
            } else {
                buff.content += value;
                rightOutput.display(value);
            }
        }
        onEraseLastChar: {
            buff.content = buff.content.slice(0,-1);
            rightOutput.replace(buff.content);
        }
        onClearBuffer: {
            SH_CommonPage.selected(buff.content);
            buff.content = "";
        }
    }
    onReload: {
        tabs.reload();
    }
    onSelected: {
        console.log("selection: "+selectedItem);
        SH_App.receiveInput(selectedItem);
    }
    onCancelProcess: {
        SH_App.cancelRunningThread();
        console.log("processus interrompu");
    }
    onValidate: {
        SH_App.receiveValidation();
    }
    onConfirm: {
        SH_App.receiveConfirmation();
    }
    onReplace: {
        SH_App.replaceInput(field);
    }
    onCancelReplace: {
        SH_App.cancelReplacement();
    }

    onKeySelected: {
        SH_CommonPage.streamBuffer.buffer(selectedKey);
    }
    GridLayout {
        id:main
        columnSpacing: 2
        rowSpacing: 2
        width: parent.width
        height: parent.height
        anchors.fill: parent
        flow: GridLayout.TopToBottom
        rows: 2
        columns: 2
        //la partie supérieure du panel de gauche est remplie par des onglets et leur contenu
        SH_TabZone {
            id: tabs
            objectName: "TabView"
            Layout.alignment: Qt.AlignTop
            Layout.minimumWidth: main.width/2-main.columnSpacing
            Layout.minimumHeight: main.height/2-main.rowSpacing
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
                SH_CommonPage.keySelected(selectedItem);
            }
            onSelectedForDetail: {
                rightOutput.displaySqlDetail(data);
            }
        }
        //la partie inférieure du panel de gauche contient le clavier
        SH_Keyboard{
            id: keys
            columns: 5
            actionsList: [
                abandonAction, cancelAction, eraseAction, replaceAction, backAction,
                leavingRoomAction, digit7Action, digit8Action, digit9Action, plusAction,
                arrivingAction, digit4Action, digit5Action, digit6Action, timesAction,
                departureAction, digit1Action, digit2Action, digit3Action, dividesAction,
                vatAction, doubleNullAction, nullAction, decimalAction, minusAction,
                escapeAction, enterAction, confirmAction, quitAction, helpAction
            ]
            enabled:true
            Layout.alignment: Qt.AlignBottom
            Layout.minimumWidth: main.width/2-main.columnSpacing
            Layout.minimumHeight: main.height/2-main.rowSpacing
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        //la zone d'affichage remplit toute la moitié de droite
        SH_OutputZone {
            id: rightOutput
            objectName: "RightOutput"
            Layout.rowSpan: 2
            Layout.minimumWidth: main.width/2-main.columnSpacing
            Layout.maximumWidth: main.width/2
            Layout.fillHeight: true
            onSelected: {
                SH_CommonPage.keySelected(selectedItem);
            }
        }
    }


    SH_ComplexAction {
        id: abandonAction
        text: qsTr("VALIDER")
        keyShortcut: Qt.Key_unknown
        onTriggered: SH_CommonPage.validate()
    }
    SH_ComplexAction {
        id: cancelAction
        text: qsTr("ANNULER")
        keyShortcut: Qt.Key_Cancel
        //onTriggered: //TODO
    }
    SH_ComplexAction {
        id: eraseAction
        text: qsTr("EFFACER")
        keyShortcut: Qt.Key_Delete
        //onTriggered: //TODO
    }
    SH_ComplexAction {
        id: replaceAction
        text: qsTr("VENDRE")
        keyShortcut: Qt.Key_unknown
        onTriggered: tabs.newSelling()
    }
    SH_ComplexAction {
        id: backAction
        text: qsTr("RETOUR")
        keyShortcut: Qt.Key_Backspace
        onTriggered: SH_CommonPage.streamBuffer.eraseLastChar();
    }

    SH_ComplexAction {
        id: leavingRoomAction
        text: qsTr("LIBÉRER")
        keyShortcut: Qt.Key_unknown

        //onTriggered: //TODO
    }
    SH_ComplexAction {
        id: digit7Action
        text: qsTr("7")
        keyShortcut: Qt.Key_7

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit8Action
        text: qsTr("8")
        keyShortcut: Qt.Key_8

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit9Action
        text: qsTr("9")
        keyShortcut: Qt.Key_9

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: plusAction
        text: qsTr("+")
        keyShortcut: Qt.Key_Plus

        onTriggered: SH_CommonPage.keySelected(text);
    }

    SH_ComplexAction {
        id: arrivingAction
        text: qsTr("ARRIVÉE")
        keyShortcut: Qt.Key_unknown
        onTriggered: tabs.newBilling();
    }
    SH_ComplexAction {
        id: digit4Action
        text: qsTr("4")
        keyShortcut: Qt.Key_4

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit5Action
        text: qsTr("5")
        keyShortcut: Qt.Key_5

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit6Action
        text: qsTr("6")
        keyShortcut: Qt.Key_6

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: timesAction
        text: qsTr("*")
        keyShortcut: Qt.Key_multiply

        onTriggered: SH_CommonPage.keySelected(text);
    }

    SH_ComplexAction {
        id: departureAction
        text: qsTr("DÉPART")
        keyShortcut: Qt.Key_unknown
        //onTriggered: //TODO
    }
    SH_ComplexAction {
        id: digit1Action
        text: qsTr("1")
        keyShortcut: Qt.Key_1

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit2Action
        text: qsTr("2")
        keyShortcut: Qt.Key_2

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: digit3Action
        text: qsTr("3")
        keyShortcut: Qt.Key_3

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: dividesAction
        text: qsTr("/")
        keyShortcut: Qt.Key_division

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: vatAction
        text: qsTr("TVA")
        keyShortcut: Qt.Key_unknown

        //onTriggered: //TODO
    }
    SH_ComplexAction {
        id: doubleNullAction
        text: qsTr("00")
        keyShortcut: Qt.Key_unknown

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: nullAction
        text: qsTr("0")
        keyShortcut: Qt.Key_0

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: decimalAction
        text: qsTr(",")
        keyShortcut: Qt.Key_Period

        onTriggered: SH_CommonPage.keySelected(text);
    }
    SH_ComplexAction {
        id: minusAction
        text: qsTr("-")
        keyShortcut: Qt.Key_Minus

        onTriggered: SH_CommonPage.keySelected(text);
    }

    SH_ComplexAction {
        id: escapeAction
        text: qsTr("ÉCHAP")
        keyShortcut: Qt.Key_Escape
        onTriggered: SH_CommonPage.cancelProcess()
    }
    SH_ComplexAction {
        id: enterAction
        text: qsTr("ENTRÉE")
        keyShortcut: Qt.Key_Enter
        onTriggered: SH_CommonPage.streamBuffer.clearBuffer();
    }
    SH_ComplexAction {
        id: confirmAction
        text: qsTr("CONFIRMER")
        keyShortcut: Qt.Key_Return
        onTriggered: {
            SH_CommonPage.confirm();
        }
    }
    SH_ComplexAction {
        id: quitAction
        text: qsTr("QUITTER")
        keyShortcut: Qt.Key_unknown
        onTriggered: {
            SH_CommonPage.cancelProcess();
            SH_CommonPage.quit();
        }
    }
    SH_ComplexAction {
        id: helpAction
        text: qsTr("AIDE")
        keyShortcut: Qt.Key_unknown
        //onTriggered: //TODO
    }


    SH_ComplexAction {
        id: char10Action
        text: qsTr("Q")
        keyShortcut: Qt.Key_Q

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char11Action
        text: qsTr("W")
        keyShortcut: Qt.Key_W

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char12Action
        text: qsTr("E")
        keyShortcut: Qt.Key_E

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char13Action
        text: qsTr("R")
        keyShortcut: Qt.Key_R

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char14Action
        text: qsTr("T")
        keyShortcut: Qt.Key_T

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char15Action
        text: qsTr("Z")
        keyShortcut: Qt.Key_Z

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char16Action
        text: qsTr("U")
        keyShortcut: Qt.Key_U

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char17Action
        text: qsTr("I")
        keyShortcut: Qt.Key_I

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char18Action
        text: qsTr("O")
        keyShortcut: Qt.Key_O

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char19Action
        text: qsTr("P")
        keyShortcut: Qt.Key_P

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char20Action
        text: qsTr("É")
        keyShortcut: Qt.Key_Eacute

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char21Action
        text: qsTr("È")
        keyShortcut: Qt.Key_Egrave

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char22Action
        text: qsTr("Ê")
        keyShortcut: Qt.Key_Ecircumflex

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char23Action
        text: qsTr("Ë")
        keyShortcut: Qt.Key_Ediaeresis

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char24Action
        text: qsTr("À")
        keyShortcut: Qt.Key_Agrave

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char25Action
        text: qsTr("Â")
        keyShortcut: Qt.Key_Acircumflex

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char26Action
        text: qsTr("Ä")
        keyShortcut: Qt.Key_Adiaeresis

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char27Action
        text: qsTr("Ï")
        keyShortcut: Qt.Key_Idiaeresis

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char28Action
        text: qsTr("Ù")
        keyShortcut: Qt.Key_Ugrave

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char29Action
        text: qsTr("Û")
        keyShortcut: Qt.Key_Ucircumflex

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char30Action
        text: qsTr("A")
        keyShortcut: Qt.Key_A

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char31Action
        text: qsTr("S")
        keyShortcut: Qt.Key_S

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char32Action
        text: qsTr("D")
        keyShortcut: Qt.Key_D

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char33Action
        text: qsTr("F")
        keyShortcut: Qt.Key_F

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char34Action
        text: qsTr("G")
        keyShortcut: Qt.Key_G

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char35Action
        text: qsTr("H")
        keyShortcut: Qt.Key_H

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char36Action
        text: qsTr("J")
        keyShortcut: Qt.Key_J

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char37Action
        text: qsTr("K")
        keyShortcut: Qt.Key_K

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char38Action
        text: qsTr("L")
        keyShortcut: Qt.Key_L

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char39Action
        text: qsTr("Ö")
        keyShortcut: Qt.Key_Odiaeresis

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char40Action
        text: qsTr("Y")
        keyShortcut: Qt.Key_Y

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char41Action
        text: qsTr("X")
        keyShortcut: Qt.Key_X

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char42Action
        text: qsTr("C")
        keyShortcut: Qt.Key_C

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char43Action
        text: qsTr("V")
        keyShortcut: Qt.Key_V

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char44Action
        text: qsTr("B")
        keyShortcut: Qt.Key_B

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char45Action
        text: qsTr("N")
        keyShortcut: Qt.Key_N

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char46Action
        text: qsTr("M")
        keyShortcut: Qt.Key_M

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char47Action
        text: qsTr("Î")
        keyShortcut: Qt.Key_Icircumflex

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char48Action
        text: qsTr("Ç")
        keyShortcut: Qt.Key_Ccedilla

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char49Action
        text: qsTr("Ô")
        keyShortcut: Qt.Key_Ocircumflex

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char50Action
        text: qsTr("Ñ")
        keyShortcut: Qt.Key_Ntilde

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char51Action
        text: qsTr("&")
        keyShortcut: Qt.Key_Ampersand

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char52Action
        text: qsTr("@")
        keyShortcut: Qt.Key_At

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char53Action
        text: qsTr("+")
        keyShortcut: Qt.Key_Plus

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char54Action
        text: qsTr("_")
        keyShortcut: Qt.Key_Underscore

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char55Action
        text: qsTr("(")
        keyShortcut: Qt.Key_BracketLeft

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char56Action
        text: qsTr(")")
        keyShortcut: Qt.Key_BracketRight

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char57Action
        text: qsTr("-")
        keyShortcut: Qt.Key_hyphen

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char58Action
        text: qsTr("?")
        keyShortcut: Qt.Key_Question

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char59Action
        text: qsTr("!")
        keyShortcut: Qt.Key_Exclam

        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }

    SH_ComplexAction {
        id: char60Action
        text: qsTr("%")
        keyShortcut: Qt.Key_Percent
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char61Action
        text: qsTr(":")
        keyShortcut: Qt.Key_Semicolon
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char62Action
        text: qsTr("<")
        keyShortcut: Qt.Key_Less
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char63Action
        text: qsTr(">")
        keyShortcut: Qt.Key_Greater
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char64Action
        text: qsTr("\\")
        keyShortcut: Qt.Key_Backslash
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char65Action
        text: qsTr("/")
        keyShortcut: Qt.Key_Slash
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char66Action
        text: qsTr("=")
        keyShortcut: Qt.Key_Equal
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char67Action
        text: qsTr("*")
        keyShortcut: Qt.Key_Asterisk
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char68Action
        text: qsTr("°")
        keyShortcut: Qt.Key_degree
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: char69Action
        text: qsTr(";")
        keyShortcut: Qt.Key_Colon
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: capsAction
        text: qsTr("MAJ.")
        keyShortcut: Qt.Key_CapsLock
        onTriggered: SH_CommonPage.streamBuffer.upperCase = !SH_CommonPage.streamBuffer.upperCase;
    }
    SH_ComplexAction {
        id: dotAction
        text: qsTr(".")
        keyShortcut: Qt.Key_Period
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: commaAction
        text: qsTr(",")
        keyShortcut: Qt.Key_Comma
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: quoteAction
        text: qsTr("'")
        keyShortcut: Qt.Key_Apostrophe
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: quote2Action
        text: qsTr("\"")
        keyShortcut: Qt.Key_QuoteDbl
        onTriggered: SH_CommonPage.keySelected(text.toLocaleLowerCase());
    }
    SH_ComplexAction {
        id: spaceAction
        text: qsTr("ESPACE")
        keyShortcut: Qt.Key_Space
        onTriggered: SH_CommonPage.keySelected(" ");
    }
}

