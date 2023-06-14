#pragma once
#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <QSettings>
#include <QList>
#include <QObject>

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

public:
    explicit ButtonManager(QObject *parent = NULL);
    static QList<QObject*> buttons();
    void parseIniFile(const QString &filePath);

signals:
    void buttonsChanged();

private:
    static QList<QObject*> m_buttons;
};

#endif // BUTTONMANAGER_H
