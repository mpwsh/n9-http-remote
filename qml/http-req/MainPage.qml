import QtQuick 1.1
import com.nokia.meego 1.1

Page {
    id: mainPage
    tools: commonTools

    property bool spinnerRunning: false
    property bool spinnerVisible: false
    property string currentFolder: ""
    property string currentFile: ""

    // Instantiate the Tools component (defined in EditTools.qml)
    MainTools{
        id: commonTools
    }

    // Instantiate the EditMenu component (defined in EditMenu.qml)
    MainMenu {
        id: mainMenu
    }

    Header {
        id: header
        headerText: "HttpRemote"
        singleLineHeader: (currentFile=="")
        infoTopText: currentFile
        infoBottomText: currentFolder
    }
    // Root item for button layout
    Item {
        id: buttonContainer
        anchors.centerIn: parent

        // Column for managing vertical layout of buttons
        Column {
                id: buttonColumn
                spacing: 10
                anchors.centerIn: parent

                // Use Repeater to dynamically create buttons based on buttonManager's model
                Repeater {
                    model: buttonManager.buttons

                    Button {
                        text: modelData.text
                        onClicked: {
                            networkManager.makeRequest(modelData.url);
                        }
                    }
                }
            }
    }
    // Spinner for network request
    BusyIndicator {
        id: networkRequestSpinner
        running: mainPage.spinnerRunning
        visible: mainPage.spinnerVisible
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
    }
}
