#ifndef RESPONSEVIEWER_H
#define RESPONSEVIEWER_H

#include <QDeclarativeItem>
#include <QFile>
#include <QClipboard>
#include <QApplication>
#include "recentfiles.h"

#define SAVE 0
#define SAVE_AS 1

class ResponseViewer : public QObject
{
    Q_OBJECT

public:
    explicit ResponseViewer(QObject *qml, RecentFiles *recentfiles, QObject *parent = 0);

private:
    static const char *UNTITLED;    // default file name for File>New

    QString currentFolder;
    QString currentFile;
    QString currentContent;

    // File info for open/save as, copied to current if operation is succesfull

    QString newFolder;
    QString newFile;

    RecentFiles *recentFiles;

private slots:
    void saveCurrentContent(int);

public slots:
    void menuCopyClicked(QString);
    void menuSaveAsClicked();
    void saveAsRequested(QString,QString);
    void newFolderChanged(QString);
    void saveAsConfirmed(QString);
    void saveBeforeClosed(QString);

signals:
    void browseRequested(QString currentFolder, bool saveRequested);
    void saveCompleted();
    void saveFailed(QString fileName, QString errorString);
    void saveAsCompleted(QString currentFolder, QString currentFile);
    void saveAsToBeConfirmed(QString fileName);
    void editorCleared(const QString &folder, const QString &file);  // Declare the missing signal
};

#endif // RESPONSEVIEWER_H
