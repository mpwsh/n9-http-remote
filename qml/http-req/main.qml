import QtQuick 1.1
import com.nokia.meego 1.1

PageStackWindow {
    id: appWindow

    // UI constants
    property int defaultMargin : appDefaults.cDEFAULT_MARGIN
    property bool orientationIsPortrait
    property bool spinnerRunning: false
    property bool spinnerVisible: false
    showStatusBar: false;
    // Select the color scheme before instantiating any QML elements
    // that need the color...
    onDefaultMarginChanged: theme.colorScheme = appDefaults.cCOLOR_SCHEME

    signal loadConfigClicked
    signal requestSuccess

    property bool appIsClosing: false
    property alias response: responsePage.content

     // These QML signals will be used in the QML side only
    signal browseCancelled
    signal menuAboutClicked

    // These QML signals will be connected to the corresponding TextEditor slots
    signal menuNewClicked(string content)
    signal menuOpenClicked(string content)
    signal menuCopyClicked(string content)
    signal menuSaveAsClicked()
    signal menuQuitClicked(string content)
    signal toolSaveClicked(string content)
    signal toolRecentClicked()
    signal toolEditClicked(string content)
    signal newFolderChanged(string newFolder)
    signal saveAsRequested(string content, string fileName)
    signal fileOpenRequested(string fileName)
    signal saveAsConfirmed(string content)
    signal newOrOpenConfirmed(string op)
    signal openRecentConfirmed()
    signal saveBeforeClosed(string content)
    signal recentFileClicked(string fileName, string folderName, string content)
    signal clearRecentClicked()

    // The corresponding TextEditor signals will be connected to these QML signals
    signal browseRequested(string currentFolder, bool saveRequested)
    signal recentRequested()
    signal editRequested(string fileName)
    signal openCompleted(string content,string currentFolder, string currentFile)
    signal openFailed(string fileName, string errorString)
    signal saveCompleted
    signal saveFailed(string fileName, string errorString)
    signal saveAsCompleted(string currentFolder, string currentFile)
    signal saveAsToBeConfirmed(string fileName)
    signal newOrOpenToBeConfirmed(string op, string fileName)
    signal openRecentToBeConfirmed(string fileName)
    signal appCloseToBeConfirmed(string fileName)
    signal appToBeClosed
    signal editorCleared(string folderPath,string fileName)
    initialPage: mainPage

    MainPage {
        id: mainPage
    }

    // Application defaults, visible in all pages
    AppDefaults {
        id: appDefaults
    }

    // QML component loader
    Loader {
        id: myLoader
    }

    ResponsePage {
        id: responsePage
    }

    //Event Handlers

    // TextEditor requested RecentPage to be opened for selecting a file.
    onRecentRequested: {
        pageStack.push(Qt.resolvedUrl("RecentPage.qml"))
    }


    onEditRequested: {
        pageStack.push(Qt.resolvedUrl("EditPage.qml"))
    }

    // Menu>Quit was selected but editor contents were not saved.
    onAppCloseToBeConfirmed: {
        myLoader.source = "DialogConfirmQuit.qml"
        myLoader.item.title = qsTr("%1 changed.").arg(fileName)
        myLoader.item.show()
    }
    Connections {
        target: networkManager
        onRequestSuccess: {
            requestSuccess()
            pageStack.push(responsePage)
        }
        onRequestStarted: {
          mainPage.spinnerRunning = true;
          mainPage.spinnerVisible = true
        }
        onRequestFinished: {
          mainPage.spinnerRunning = false;
          mainPage.spinnerVisible = false
        }
    }
}
