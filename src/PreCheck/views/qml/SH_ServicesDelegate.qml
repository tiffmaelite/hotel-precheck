import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

/*!
  \class  SH_ServicesDelegate
  */
SH_DataDelegate {
    id: service
    value: SERVICEFULLCODE
    text: SERVICENAME
    visible: ISAVAILABLE == true
    enabled: (TYPENEEDSROOM == false || App.billOpened() > 0)
}
