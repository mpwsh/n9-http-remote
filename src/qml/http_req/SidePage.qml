import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    tools: commonTools

    Label {
        id: label
        anchors.centerIn: parent
        text: networkManager.data
        font.pixelSize: 32
        color: "steelblue"
        visible: true
    }

    Button{
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: label.bottom
            topMargin: 10
        }
        text: qsTr("OK")
        onClicked: pageStack.pop()
    }
}
