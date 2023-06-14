
import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: mainPage
    tools: commonTools

    // Root item for button layout
    Item {
        id: buttonContainer
        anchors.centerIn: parent

        // Column for managing vertical layout of buttons
        Column {
            id: buttonColumn
            spacing: 10  // Adjust the spacing between buttons to your needs
            anchors.centerIn: parent

            // Dynamic creation of buttons
            Repeater {
                model: buttonManager.buttons

                Button {
                    text: modelData.text
                    onClicked: {
                        console.log("Making call to: " + modelData.url);
                        networkManager.makeRequest(modelData.url);
                    }
                }
            }
        }
    }
}
