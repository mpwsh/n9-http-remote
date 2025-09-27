#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "networkmanager.h"
#include "buttonmanager.h"
#include "responseviewer.h"
#include "recentfiles.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    ResponseViewer *responseviewer;
    RecentFiles *recentfiles;
    ButtonManager *buttonmanager;
    NetworkManager networkManager;

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("networkManager", &networkManager);
    //Orientation
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    //UI
    viewer.setMainQmlFile(QLatin1String("qml/http-req/main.qml"));
    viewer.showExpanded();

    // get the QML root object for signal-slot connections
    QObject *qml = viewer.rootObject();

    // Create the recent files list model and put it to the root context
    // Make viewer the parent object.
    recentfiles = new RecentFiles(qml, &viewer);
    viewer.rootContext()->setContextProperty("recentFiles",recentfiles);

    // Create the back-end processor and pass in the root object and the recent files model.
    // Make viewer the parent object.
    responseviewer = new ResponseViewer(qml, recentfiles, &viewer);
    buttonmanager = new ButtonManager(qml, recentfiles, &viewer);
    viewer.rootContext()->setContextProperty("buttonManager", buttonmanager);

    // Load the button configuration after the ButtonManager instance has been created
    buttonmanager->parseIniFile("/home/developer/MyDocs/buttons.ini");

    return app->exec();
}
