import QtQuick 1.1
import com.nokia.meego 1.1

Page {
    id: responsePage
    tools: commonTools

    property alias content: textArea.text
    property string currentFolder: ""
    property string currentFile: ""
    property bool showSave: false
    property alias textAreaHeight: textArea.height

    signal responseCancelled

    onResponseCancelled: {
      pageStack.pop()
    }

    // Instantiate the Tools component (defined in ResponseTools.qml)
    ResponseTools {
       id: commonTools
       visible: true
    }

    // Instantiate the ResponseMenu component (defined in ResponseMenu.qml)
    ResponseMenu {
        id: responseMenu
   }

    Header {
        id: header
        headerText: "Response"
        singleLineHeader: (currentFile=="")
        infoTopText: currentFile
        infoBottomText: currentFolder
    }

    Flickable {
        id: flickable
        anchors.top: header.bottom
        width: parent.width
        height: parent.height-header.height
        clip: true
        contentHeight: textArea.height
        contentWidth: textArea.width

        TextArea {
            id: textArea
            width: responsePage.width
            text: networkManager.data
            smooth: true
            wrapMode: TextEdit.Wrap
            textFormat: TextEdit.PlainText
            font.pixelSize: appDefaults.cFONT_SIZE_SMALL
        }
    }

    // Called twice: 1) showSave=true 2) showSave=false
    // Change state from "saving" to "saved"
    onShowSaveChanged: {
        state = (showSave)?"saving":"saved"
        showSave = false
    }

    state: "saved"
    states: [
        State {
            name: "saving"
            PropertyChanges {target: statusLabel; opacity: 1.0}
            PropertyChanges {target: flickable; opacity: 0}
        },
        State {
            name: "saved"
        }
    ]

    // Status label to give some visual feedback for the "save" button click
    Label {
        id: statusLabel
        opacity: 0
        color:  "orange"
        font.pixelSize: 42
        text: qsTr("Saving")+"..."
        anchors.centerIn: parent
    }

    // Animations to give some visual feedback for the "save" button click
    transitions: [
        Transition {
            from: "saving"
            to: "saved"
            PropertyAnimation {
                target: statusLabel
                property: "opacity"
                to: 0
                duration: 1000
            }
            PropertyAnimation {
                target: flickable
                property: "opacity"
                to: 1
                duration: 1000
            }
        }
    ]
}
