import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import QtQml 2.0
import QtQml.Models 2.1
import PreCheck 1.0

/*!
  \class  SH_VATDelegate
  */
SH_DataModelDelegate {
    id: delModel
    model: SH_VATModel { }
    value: model.empty ? "-1" : PERCENTAGE
    text: model.empty ? "" : LABEL
}
