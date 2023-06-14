import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: mainPage
    tools: commonTools

    // Invisible root item for button layout
    Item {
        id: buttonContainer
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }

        // Dynamic creation of buttons
        Repeater {
            model: buttonManager.buttons

            Button {
                text: modelData.text
                onClicked: {
                    console.log("Making call to: " + modelData.url);
                    networkManager.makeRequest(modelData.url);
                }
                // Position each button below the previous one
                anchors {
                    top: index === 0 ? parent.top : previousItem.bottom
                    horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
}
