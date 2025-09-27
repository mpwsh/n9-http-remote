#include "responseviewer.h"
#include "recentfiles.h"
#include <QDebug>

const char *ResponseViewer::UNTITLED = QT_TRANSLATE_NOOP("ResponseViewer","Untitled");

ResponseViewer::ResponseViewer(QObject *qml, RecentFiles *recentfiles, QObject *parent) :
    QObject(parent)
{
    currentFolder = "file:///home/user";
    newFolder = currentFolder;
    currentFile = tr(UNTITLED);
    currentContent = "";
    recentFiles = recentfiles;

    // connect QML signals to ResponseViewer slots
    connect(qml, SIGNAL(menuCopyClicked(QString)),
             this, SLOT(menuCopyClicked(QString)));
    connect(qml, SIGNAL(menuSaveAsClicked()),
             this, SLOT(menuSaveAsClicked()));
    connect(qml, SIGNAL(saveAsRequested(QString,QString)),
             this, SLOT(saveAsRequested(QString,QString)));
    connect(qml, SIGNAL(saveAsConfirmed(QString)),
             this, SLOT(saveAsConfirmed(QString)));
    connect(qml, SIGNAL(saveBeforeClosed(QString)),
             this, SLOT(saveBeforeClosed(QString)));

    // connect ResponseViewer signals to QML signals
    connect(this, SIGNAL(browseRequested(QString,bool)),
               qml, SIGNAL(browseRequested(QString,bool)));
    connect(this, SIGNAL(saveFailed(QString,QString)),
               qml, SIGNAL(saveFailed(QString,QString)));
    connect(this, SIGNAL(saveAsCompleted(QString,QString)),
               qml, SIGNAL(saveAsCompleted(QString,QString)));
    connect(this, SIGNAL(editorCleared(QString,QString)),
               qml, SIGNAL(editorCleared(QString,QString)));
}

// QML menu: Copy to clipboard was clicked
void ResponseViewer::menuCopyClicked(QString content)
{
    QClipboard *clipboard = QApplication::clipboard();
    //qDebug() << "Copying content: " << content;
    clipboard->setText(content);
}

// QML menu: Save As was clicked
void ResponseViewer::menuSaveAsClicked()
{
    bool saveRequested = true;
    emit browseRequested(currentFolder, saveRequested);
}

// Overwrite during Menu>Save As was confirmed.
void ResponseViewer::saveAsConfirmed(QString content)
{
    currentContent = content;
    saveCurrentContent(SAVE_AS);
}

// Saving changed content before quitting was confirmed.
void ResponseViewer::saveBeforeClosed(QString content)
{
    // Did we have a valid file name?
    if(currentFile==tr(UNTITLED))
    {
        menuSaveAsClicked();
        return;
    }
    currentContent = content;
    newFolder = currentFolder;
    newFile = currentFile;
    saveCurrentContent(SAVE);
}

// QML listView: file name was selected for saving
void ResponseViewer::saveAsRequested(QString content, QString fileName)
{
    if (fileName.isEmpty())
        return;

    newFile = fileName;
    QUrl url(newFolder+"/"+newFile);
    QString localFile = url.toLocalFile();
    QFile file(localFile);
    if(file.exists())
    {
        emit saveAsToBeConfirmed(fileName);
    } else {
        currentContent = content;
        saveCurrentContent(SAVE_AS);
    }
}

// QML listView: folder was selected
void ResponseViewer::newFolderChanged(QString path)
{
    newFolder = path;
}

// Save the current response content to the current folder/file.
void ResponseViewer::saveCurrentContent(int saveMode)
{
    bool fileIsWritable;

    //qDebug() << "DBG> save"<<currentFile<<"to currentFolder:"<<currentFolder;

    QUrl url(newFolder+"/"+newFile);
    QString localFile = url.toLocalFile();
    QFile file(localFile);
    fileIsWritable = file.open(QIODevice::WriteOnly | QIODevice::Text);

    if ( fileIsWritable ) {
        QTextStream stream( &file );
        stream<<currentContent;
        file.close();
        currentFolder = newFolder;
        currentFile = newFile;
        if(saveMode==SAVE)
            emit saveCompleted();
        else {
            recentFiles->readRecentFiles();
            recentFiles->addFile(currentFolder+"|"+currentFile);
            emit saveAsCompleted(currentFolder,currentFile);
        }
    } else {
        emit saveFailed(newFile,file.errorString());
    }
}
