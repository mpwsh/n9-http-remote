#include "buttonmanager.h"
#include "recentfiles.h"
#include "qmlapplicationviewer.h"
#include <QFileInfo>
#include <QInputDialog>
#include <QMessageBox>

const char *ButtonManager::UNTITLED = QT_TRANSLATE_NOOP("ButtonManager","buttons.ini");

QList<QObject*> ButtonManager::m_buttons;

Button::Button(QObject *parent)
    : QObject(parent)
{
}

Button::Button(const QString &text, const QString &url, QObject *parent)
    : QObject(parent), m_text(text), m_url(url)
{
}

QString Button::text() const
{
    return m_text;
}

void Button::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        emit textChanged();
    }
}

QString Button::url() const
{
    return m_url;
}

void Button::setUrl(const QString &url)
{
    if (m_url != url) {
        m_url = url;
        emit urlChanged();
    }
}

ButtonManager::ButtonManager(QObject *qml, RecentFiles *recentfiles, QObject *parent)
    : QObject(parent)
{
    m_currentFolder = "file:///home/developer/MyDocs";

    newFolder = m_currentFolder;
    m_currentFile = tr(UNTITLED);
    currentContent = "";
    recentFiles = recentfiles;

    connect(qml, SIGNAL(recentFileClicked(QString,QString,QString)),
             this, SLOT(recentFileClicked(QString,QString,QString)));
    connect(qml, SIGNAL(openRecentConfirmed()),
             this, SLOT(openRecentConfirmed()));
    connect(this, SIGNAL(openRecentToBeConfirmed(QString)),
               qml, SIGNAL(openRecentToBeConfirmed(QString)));
    connect(qml, SIGNAL(menuOpenClicked(QString)),
             this, SLOT(menuOpenClicked(QString)));
    connect(qml, SIGNAL(toolEditClicked(QString)),
             this, SLOT(toolEditClicked(QString)));
    connect(qml, SIGNAL(toolRecentClicked()),
             this, SLOT(toolRecentClicked()));
    connect(qml, SIGNAL(menuSaveAsClicked()),
             this, SLOT(menuSaveAsClicked()));
    connect(qml, SIGNAL(menuQuitClicked(QString)),
             this, SLOT(menuQuitClicked(QString)));
    connect(this, SIGNAL(appToBeClosed()),
               qml, SIGNAL(appToBeClosed()));
    connect(qml, SIGNAL(newOrOpenConfirmed(QString)),
             this, SLOT(newOrOpenConfirmed(QString)));
}

QString ButtonManager::currentFile() const
{
    return m_currentFile;
}

QString ButtonManager::currentFolder() const
{
    return m_currentFolder;
}

// EditPage toolbar: Edit button was clicked
void ButtonManager::toolEditClicked(QString content)
{
    Q_UNUSED(content);
    emit editRequested();
}

// Recent Files button was clicked
void ButtonManager::toolRecentClicked()
{
    bool statusOk = recentFiles->readRecentFiles();
    if (statusOk)
        emit recentRequested();
}

// Create new configuration
void ButtonManager::newConfig()
{
    // Clear all buttons
    while(m_buttons.size() > 0) {
        Button *button = qobject_cast<Button*>(m_buttons.takeAt(0));
        button->deleteLater();
    }

    m_currentFile = tr(UNTITLED);
    m_currentFolder = "file:///home/developer/MyDocs";
    emit buttonsChanged();
}

// Save configuration with new name
void ButtonManager::saveAsConfig()
{
    // For N9, we'll just save with a timestamp
    QString fileName = QString("buttons_%1.ini").arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));
    m_currentFile = fileName;
    saveToIni();

    // Add to recent files
    recentFiles->readRecentFiles();
    recentFiles->addFile(m_currentFolder + "|" + m_currentFile);
}

// QML menu: Open was clicked
void ButtonManager::menuOpenClicked(QString content)
{
    Q_UNUSED(content);
    toolRecentClicked();
}

// Discard changes and proceed with "New" or "Open"
void ButtonManager::newOrOpenConfirmed(QString op)
{
    if(op=="new") {
        newConfig();
    } else if(op=="open") {
        toolRecentClicked();
    }
}

// QML menu: Save As was clicked
void ButtonManager::menuSaveAsClicked()
{
    saveAsConfig();
}

// Menu>Quit was selected.
void ButtonManager::menuQuitClicked(QString content)
{
    Q_UNUSED(content);
    emit appToBeClosed();
}

void ButtonManager::parseIniFile(const QString &filePath)
{
    // Parse the path to update current folder and file
    QFileInfo fileInfo(filePath);
    m_currentFolder = "file://" + fileInfo.absolutePath();
    m_currentFile = fileInfo.fileName();

    QSettings settings(filePath, QSettings::IniFormat);

    // Clear existing buttons
    while(m_buttons.size() > 0) {
        Button *button = qobject_cast<Button*>(m_buttons.takeAt(0));
        button->deleteLater();
    }

    QStringList groups = settings.childGroups();
    for (int i = 0; i < groups.size(); ++i) {
        const QString& group = groups[i];
        settings.beginGroup(group);
        Button *button = new Button(settings.value("text").toString(), settings.value("url").toString(), this);
        m_buttons.append(button);
        settings.endGroup();
    }
    emit buttonsChanged();
}

QList<QObject*> ButtonManager::buttons()
{
    return m_buttons;
}

void ButtonManager::addButton(const QString &text, const QString &url)
{
    Button *button = new Button(text, url, this);
    m_buttons.append(button);
    emit buttonAdded();
    emit buttonsChanged();
}

void ButtonManager::removeButton(int index)
{
    if (index >= 0 && index < m_buttons.size()) {
        Button *button = qobject_cast<Button*>(m_buttons.takeAt(index));
        button->deleteLater();
        emit buttonRemoved();
        emit buttonsChanged();
    }
}

void ButtonManager::updateButton(int index, const QString &text, const QString &url)
{
    if (index >= 0 && index < m_buttons.size()) {
        Button *button = qobject_cast<Button*>(m_buttons.at(index));
        if (button) {
            button->setText(text);
            button->setUrl(url);
            emit buttonUpdated();
            emit buttonsChanged();
        }
    }
}

// Load an INI file from recent files
void ButtonManager::fileOpenRequested(QString fileName)
{
    QUrl url(newFolder + "/" + fileName);
    QString localFile = url.toLocalFile();
    QFile file(localFile);

    if (file.exists()) {
        parseIniFile(localFile);

        // Update recent files list
        recentFiles->readRecentFiles();
        recentFiles->addFile(m_currentFolder + "|" + m_currentFile);

        emit openCompleted("", m_currentFolder, m_currentFile);
    } else {
        recentFiles->removeFile(newFolder + "|" + fileName);
        emit openFailed(fileName, file.errorString());
    }
}

void ButtonManager::recentFileClicked(QString fileName, QString folderName, QString content)
{
    Q_UNUSED(content);
    newFolder = folderName;
    newFile = fileName;
    fileOpenRequested(newFile);
}

// QML listView: folder was selected
void ButtonManager::newFolderChanged(QString path)
{
    newFolder = path;
}

void ButtonManager::openRecentConfirmed()
{
    fileOpenRequested(newFile);
}

void ButtonManager::saveToIni()
{
    // Use current file if we have one
    QUrl url(m_currentFolder + "/" + m_currentFile);
    QString localFile = url.toLocalFile();

    QSettings settings(localFile, QSettings::IniFormat);
    settings.clear();

    // Write each button
    for (int i = 0; i < m_buttons.size(); ++i) {
        Button *button = qobject_cast<Button*>(m_buttons.at(i));
        if (button) {
            QString group = QString("button%1").arg(i + 1);
            settings.beginGroup(group);
            settings.setValue("text", button->text());
            settings.setValue("url", button->url());
            settings.endGroup();
        }
    }

    settings.sync();
}

// Unused legacy methods - kept for compatibility
void ButtonManager::saveCurrentContent(int saveMode) { Q_UNUSED(saveMode); }
void ButtonManager::saveBeforeClosed(QString content) { Q_UNUSED(content); }
void ButtonManager::menuNewClicked(QString content) { Q_UNUSED(content); newConfig(); }
