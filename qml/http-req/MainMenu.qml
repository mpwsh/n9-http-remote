import QtQuick 1.1
import com.nokia.meego 1.1

Menu {
    MenuLayout {
        MenuItem {
            text: qsTr("New")
            onClicked: {
                buttonManager.newConfig();
            }
        }

        MenuItem {
            text: qsTr("Open")
            onClicked: {
                toolRecentClicked();
            }
        }

        MenuItem {
            text: qsTr("Save As")
            onClicked: {
                buttonManager.saveAsConfig();
            }
        }

        MenuItem {
            text: qsTr("About")
            onClicked: {
                var component = Qt.createComponent("AboutDialog.qml");
                var dialog = component.createObject(mainPage);
                dialog.open();
            }
        }

        MenuItem {
            text: qsTr("Quit")
            onClicked: {
                Qt.quit();
            }
        }
    }
}
