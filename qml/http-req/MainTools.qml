import QtQuick 1.1
import com.nokia.meego 1.1

// Toolbar for the Main page
ToolBar {
    anchors.bottom: parent.bottom
    tools:
        ToolBarLayout {
        // Edit buttons config
        ToolIcon {
            platformIconId: "toolbar-edit"
            anchors.left: (parent === undefined) ? undefined : parent.left
            onClicked: {
                editRequested(mainPage.currentFile)
            }
        }
        // Recent files button
        ToolIcon {
            platformIconId: "toolbar-list"
            anchors.left: (parent === undefined) ? undefined : parent.center
            onClicked: {
                toolRecentClicked()
            }
        }
        // Menu button
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (mainMenu.status === DialogStatus.Closed) ?
                           mainMenu.open() : mainMenu.close()
        }
    }
}
