#pragma once
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>

class NetworkManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ data NOTIFY dataChanged)
public:
    explicit NetworkManager(QObject *parent = NULL);
    ~NetworkManager();
    QString data() const;

    Q_INVOKABLE void makeRequest(const QString &url);

    static NetworkManager* instance();

signals:
    void dataChanged();
    void requestSuccess();

private slots:
    void onFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager m_networkAccessManager;
    QString m_data;
    static NetworkManager* m_instance;
    bool m_ongoingRequest;
};

#endif // NETWORKMANAGER_H
