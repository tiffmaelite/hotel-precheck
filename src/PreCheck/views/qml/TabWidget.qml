import QtQuick 2.0

Rectangle {
    // height of the tab bar
    property int tabsHeight : 64

    // index of the active tab
    property int currentIndex : 0

    // the model used to build the tabs
    property VisualItemModel tabsList

    anchors.fill: parent

    // will contain the tab views
    Rectangle {
        id: tabViewContainer
        width: parent.width

        anchors.top: tabBar.bottom
        anchors.bottom: parent.bottom

        // build all the tab views
        Repeater {
            model: tabsList
        }
    }

    //When the component has been completely initialized, the default tab has to be selected
    Component.onCompleted:
    {
        // hide all the tab views
        for(var i = 0; i < tabsList.children.length; i++)
        {
            tabsList.children[i].visible = false;
        }
        // select the default tab index
        tabClicked(currentIndex);
    }

    function tabClicked(index)
    {
        // unselect the currently selected tab
        tabBar.unselectTab(currentIndex);
        // hide the currently selected tab view
        tabsList.children[currentIndex].visible = false;

        // change the current tab index
        currentIndex = index;

        //highlight the right tab
        tabBar.selectTab(currentIndex);
        // show the new tab view
        tabsList.children[currentIndex].visible = true;
    }

    Component {
        id: tabItem

        Pushable {
            height: parent.height
            width: parent.width / tabsList.count

            color: "transparent"
            radius: 3

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                color: "white"
                text: tabsList.children[index].name
            }

            onPushed: {
                tabClicked(index)
            }
        }
    }

    // the tab bar
    TabBar {
        id: tabBar
        nbTabs: tabsList.count
        h: tabsHeight
    }
}
