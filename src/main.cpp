#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "networkmanager.h"
#include "buttonmanager.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    NetworkManager networkManager;
    viewer.rootContext()->setContextProperty("networkManager", &networkManager);
    ButtonManager buttonManager;
    buttonManager.parseIniFile("/home/developer/MyDocs/buttons.ini");
    viewer.rootContext()->setContextProperty("buttonManager", &buttonManager);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/http_req/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
