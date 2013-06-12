import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0

Tab {
    property var headers
    property var tableModel
    property var dataDelegate
    SqlDataView {
        filterFields: headers
        sqlModel: tableModel
        itemsDelegate: dataDelegate
    }
}
