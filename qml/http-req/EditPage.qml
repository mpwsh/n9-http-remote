import QtQuick 1.1
import com.nokia.meego 1.1

Page {
    id: editPage
    signal editCancelled

    // Toolbar>Back was clicked in the EditPage
    onEditCancelled: {
        pageStack.pop()
    }

    // Instantiate the EditTools component (defined in EditTools.qml)
    EditTools {
        id: editTools
        visible: true
    }

    // The page header
    Header {
        id: header
        anchors.top: parent.top
        singleLineHeader: false
        headerText: qsTr("Edit Buttons")
        infoTopText: buttonManager.currentFile
        infoBottomText: buttonManager.currentFolder
    }

    // Create a ListModel from the ButtonManager's buttons
    ListModel {
        id: buttonData
    }

    // Load current button configuration on page load
    Component.onCompleted: {
        buttonData.clear();
        for (var i = 0; i < buttonManager.buttons.length; i++) {
            var button = buttonManager.buttons[i];
            buttonData.append({"text": button.text, "url": button.url});
        }
    }

    Flickable {
        anchors.top: header.bottom
        anchors.bottom: buttonRow.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10
        contentHeight: dataColumn.height + 20
        clip: true

        Column {
            id: dataColumn
            width: parent.width - 20
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15

            Repeater {
                model: buttonData

                delegate: Item {
                    width: parent.width
                    height: childColumn.height + 20

                    Rectangle {
                        anchors.fill: parent
                        color: "#303030"
                        radius: 8
                        border.color: "#505050"
                        border.width: 1

                        Column {
                            id: childColumn
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.margins: 10
                            spacing: 8

                            Row {
                                width: parent.width
                                Label {
                                    text: "Button " + (index + 1)
                                    color: "white"
                                    width: parent.width - 40
                                    font.pixelSize: 18
                                }
                                ToolIcon {
                                    platformIconId: "toolbar-delete"
                                    onClicked: {
                                        buttonData.remove(index);
                                    }
                                }
                            }

                            TextField {
                                width: parent.width
                                placeholderText: "Button text"
                                text: model.text
                                onTextChanged: {
                                    buttonData.setProperty(index, "text", text);
                                }
                            }

                            TextField {
                                width: parent.width
                                placeholderText: "Button URL"
                                text: model.url
                                font.pixelSize: 16
                                onTextChanged: {
                                    buttonData.setProperty(index, "url", text);
                                }
                            }
                        }
                    }
                }
            }

            Button {
                id: addButton
                text: "+ Add New Button"
                width: parent.width
                onClicked: {
                    buttonData.append({"text": "", "url": ""});
                }
            }
        }
    }

    Row {
        id: buttonRow
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10
        spacing: 10

        Button {
            id: cancelButton
            text: "Cancel"
            width: (parent.width - 10) / 2
            onClicked: {
                pageStack.pop();
            }
        }

        Button {
            id: saveButton
            text: "Save"
            width: (parent.width - 10) / 2
            onClicked: {
                // First clear all existing buttons
                while(buttonManager.buttons.length > 0) {
                    buttonManager.removeButton(0);
                }

                // Add all buttons from the form
                for (var i = 0; i < buttonData.count; i++) {
                    var item = buttonData.get(i);
                    if (item.text.length > 0 && item.url.length > 0) {
                        buttonManager.addButton(item.text, item.url);
                    }
                }

                // Save to INI file
                buttonManager.saveToIni();
                pageStack.pop();
            }
        }
    }
}
