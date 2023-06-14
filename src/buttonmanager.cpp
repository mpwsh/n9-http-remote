#include "buttonmanager.h"
#include <QStringList>
#include <QSettings>
#include <QObject>

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

ButtonManager::ButtonManager(QObject *parent)
    : QObject(parent)
{
    // here you can add code that should be executed when a ButtonManager object is created
}

void ButtonManager::parseIniFile(const QString &filePath)
{
    QSettings settings(filePath, QSettings::IniFormat);
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
