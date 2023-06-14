TEMPLATE = app
TARGET = http_req
QT += network

CONFIG += qt quick qml

# Application versioning
VERSION = 1.0.0

# specify where the target should go
DESTDIR = build/

# speed up launching on MeeGo/Harmattan when using applauncherd daemon
#CONFIG += qdeclarative-boostable

# Specify source and header files
SOURCES += \
    src/main.cpp \
    src/networkmanager.cpp \
    src/buttonmanager.cpp

HEADERS += \
    src/networkmanager.h \
    src/buttonmanager.h

# Additional import path used to resolve QML modules in Creators code model
QML_IMPORT_PATH = src/qml

# Add more folders to ship with the application, here
folder_01.source = src/qml/http_req
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Include the QML Application Viewer
include(src/qmlapplicationviewer/qmlapplicationviewer.pri)

# Add deployment rules (required for deployment)
qtcAddDeployment()

# Define symbian specific settings
symbian {
    TARGET.UID3 = 0xE0E53C8F
    TARGET.CAPABILITY += NetworkServices
}

# Other Files
OTHER_FILES += \
    debian_harmattan/rules \
    debian_harmattan/README \
    debian_harmattan/manifest.aegis \
    debian_harmattan/copyright \
    debian_harmattan/control \
    debian_harmattan/compat \
    debian_harmattan/changelog
