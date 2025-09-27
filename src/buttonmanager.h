#pragma once
#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <QSettings>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QObject>
#include <QStringList>
#include <QDateTime>
#include "recentfiles.h"

#define SAVE 0
#define SAVE_AS 1

class Button : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

public:
    explicit Button(QObject *parent = NULL);
    Button(const QString &text, const QString &url, QObject *parent = NULL);

    QString text() const;
    void setText(const QString &text);

    QString url() const;
    void setUrl(const QString &url);

signals:
    void textChanged();
    void urlChanged();

private:
    QString m_text;
    QString m_url;
};

class ButtonManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> buttons READ buttons NOTIFY buttonsChanged)
    Q_PROPERTY(QString currentFile READ currentFile NOTIFY currentFileChanged)
    Q_PROPERTY(QString currentFolder READ currentFolder NOTIFY currentFolderChanged)

public:
    explicit ButtonManager(QObject *qml, RecentFiles *recentfiles, QObject *parent = NULL);
    QList<QObject*> buttons();
    QString currentFile() const;
    QString currentFolder() const;
    void parseIniFile(const QString &filePath);
    Q_INVOKABLE void addButton(const QString &text, const QString &url);
    Q_INVOKABLE void removeButton(int index);
    Q_INVOKABLE void updateButton(int index, const QString &text, const QString &url);
    Q_INVOKABLE void saveToIni();
    Q_INVOKABLE void newConfig();
    Q_INVOKABLE void saveAsConfig();

signals:
    void editRequested();
    void saveCompleted();
    void saveFailed(QString fileName, QString errorString);
    void saveAsCompleted(QString currentFolder, QString currentFile);
    void appToBeClosed();
    void openRecentToBeConfirmed(QString fileName);
    void newOrOpenToBeConfirmed(QString op, QString fileName);
    void buttonsChanged();
    void buttonAdded();
    void buttonRemoved();
    void buttonUpdated();
    void currentFileChanged();
    void currentFolderChanged();
    void browseRequested(QString currentFolder, bool saveRequested);
    void recentRequested();
    void openCompleted(QString content, QString currentFolder, QString currentFile);
    void openFailed(QString fileName, QString errorString);

public slots:
    void newOrOpenConfirmed(QString);
    void openRecentConfirmed();
    void saveBeforeClosed(QString);
    void recentFileClicked(QString,QString,QString);
    void fileOpenRequested(QString);
    void newFolderChanged(QString);
    void menuNewClicked(QString);
    void menuOpenClicked(QString);
    void menuSaveAsClicked();
    void menuQuitClicked(QString);
    void toolEditClicked(QString);
    void toolRecentClicked();

private slots:
    void saveCurrentContent(int);

private:
    static const char *UNTITLED;
    QString m_currentFolder;
    QString m_currentFile;
    QString currentContent;
    QString newFolder;
    QString newFile;

    RecentFiles *recentFiles;
    static QList<QObject*> m_buttons;
};

#endif // BUTTONMANAGER_H
