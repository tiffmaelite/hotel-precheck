import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import QtQml 2.1
import QtQml.Models 2.1
import PreCheck 1.0

DelegateModel {
    id: delModel
    Component.onCompleted: {
        if(delModel.model.empty) {
            delModel.model.fetch();
        }
    }
    property real height
    property real width
    property string value
    property string text
    property bool visible
    property bool enabled
    property variant textStyle: ""
    property variant backgroundStyle: ""
    signal clicked();
    delegate: SH_DataDelegate {
        id: btn
        value: delModel.value
        text: delModel.text
        height: delModel.height
        width: delModel.width
        visible: delModel.visible
        enabled: delModel.enabled
        textStyle: delModel.textStyle === "" ? defaultTextStyle : delModel.textStyle
        backgroundStyle: delModel.backgroundStyle === "" ? defaultBackgroundStyle : delModel.backgroundStyle
        onClicked: {
            delModel.clicked();
        }
    }
}
