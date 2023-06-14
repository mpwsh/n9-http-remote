#include "networkmanager.h"
#include <QDebug>
#include <QNetworkReply>

NetworkManager* NetworkManager::m_instance = NULL;

NetworkManager::NetworkManager(QObject *parent) : QObject(parent), m_ongoingRequest(false)
{
    connect(&m_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onFinished(QNetworkReply*)));
}

NetworkManager::~NetworkManager()
{
}

QString NetworkManager::data() const
{
    return m_data;
}

void NetworkManager::makeRequest(const QString &url)
{
    qDebug() << "Making request: " << url << " Ongoing Request: " << m_ongoingRequest;

    if (m_ongoingRequest) {
        qDebug() << "Found ongoing request. exiting";
        return;
    }

    m_ongoingRequest = true;

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    m_networkAccessManager.get(request);
}

void NetworkManager::onFinished(QNetworkReply *reply)
{
    m_ongoingRequest = false;
    qDebug() << "onFinished called. Ongoing Request: " << m_ongoingRequest;  // new debug message
    if (reply->error() == QNetworkReply::NoError) {
        m_data = QString(reply->readAll());
        qDebug() << "Response: " << m_data;
        emit dataChanged();
        emit requestSuccess();
    } else {
        qDebug() << "Network request error: " << reply->errorString();
    }
    reply->deleteLater();
}


NetworkManager* NetworkManager::instance()
{
    if (m_instance == NULL) {
        m_instance = new NetworkManager();
    }
    return m_instance;
}
