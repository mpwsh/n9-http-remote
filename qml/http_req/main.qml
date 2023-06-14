import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    MainPage {
        id: mainPage
    }

    SidePage {
        id: sidePage
    }

    initialPage: mainPage

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status === DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem { text: qsTr("Sample menu item") }
        }
    }

    // When the network manager signals a successful request, navigate to the side page.
    Connections {
        target: networkManager
        onRequestSuccess: pageStack.push(sidePage)
    }
}
