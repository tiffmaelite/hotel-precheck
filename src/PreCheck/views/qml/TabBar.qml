import QtQuick 2.0

Rectangle {
    id: tabBar

    property int h
    property int nbTabs

    height: h
    width: parent.width

    anchors {
        // take the whole parent width
        left: parent.left
        right: parent.right

        // attach it to the view top
        top: parent.top
    }

    gradient: Gradient {
        GradientStop {position: 0.0; color: "#666666"}
        GradientStop {position: 1.0; color: "#000000"}
    }

    function unselectTab(index) {
        tabsItems.children[index].color = "transparent";
    }

    function selectTab(index) {
        tabsItems.children[index].color = "#30ffffff";

    }

    // place all the tabs in a row
    Row {
        id: tabsItems
        anchors.fill: parent

        Repeater {
            model: nbTabs
            delegate: tabItem
        }
    }
}
