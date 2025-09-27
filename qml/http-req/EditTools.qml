import QtQuick 1.1
import com.nokia.meego 1.1

// Toolbar for the Edit page
ToolBar {
    anchors.bottom: parent.bottom
    tools:
        ToolBarLayout {
        // Back to the MainPage
        ToolIcon {
            platformIconId: inPortrait?"toolbar-back-dimmed-white":
                                        "toolbar-back-landscape-dimmed-white"
            onClicked: editCancelled()
        }
        // Quick save button
        ToolIcon {
            platformIconId: "toolbar-directory-move-to"
            anchors.left: (parent === undefined) ? undefined : parent.left
            onClicked: {
                toolSaveClicked(editPage.content)
            }
        }
    }
}
