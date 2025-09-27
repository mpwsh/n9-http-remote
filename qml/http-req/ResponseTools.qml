import QtQuick 1.1
import com.nokia.meego 1.1

// Toolbar for the response page
ToolBar {
    anchors.bottom: parent.bottom
    tools:
        ToolBarLayout {
        // Back to the MainPage
        ToolIcon {
            platformIconId: inPortrait?"toolbar-back-dimmed-white":
                                        "toolbar-back-landscape-dimmed-white"
            onClicked: responseCancelled()
        }
        // Menu button
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (responseMenu.status === DialogStatus.Closed) ?
                           responseMenu.open() : responseMenu.close()
        }
    }
}
