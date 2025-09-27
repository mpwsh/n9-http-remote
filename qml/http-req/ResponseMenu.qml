import QtQuick 1.1
import com.nokia.meego 1.1

Menu {
    MenuLayout {
        MenuItem {
            text: qsTr("Copy to clipboard")
            onClicked: {
                menuCopyClicked(responsePage.content)
            }
        }

        MenuItem {
            text: qsTr("Save to file")
            onClicked: {
                menuSaveAsClicked()
            }
        }
    }
}
