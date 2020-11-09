# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# VERSION
VERSION = 0.0.2
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# The name of your application
TARGET = harbour-webcontrol
DEFINES += APP_TARGET=\\\"$$TARGET\\\"

QT += dbus

CONFIG += sailfishapp
PKGCONFIG += \
    sailfishmdm \
    TelepathyQt5 \
    Qt5Contacts

SOURCES += src/harbour-webcontrol.cpp \
    src/data/datamanager.cpp \
    src/data/gobaldata.cpp \
    src/device/devicecontrol.cpp \
    src/device/globaldevice.cpp \
    src/web/controller/restapicontroller.cpp \
    src/web/globalweb.cpp \
    src/web/requestmapper.cpp \
    src/web/webserver.cpp \
    src/webcontrol.cpp

DISTFILES += qml/harbour-webcontrol.qml \
    qml/cover/CoverPage.qml \
    qml/pages/SettingsPage.qml \
    qml/pages/StartPage.qml \
    rpm/harbour-webcontrol.changes.in \
    rpm/harbour-webcontrol.changes.run.in \
    rpm/harbour-webcontrol.spec \
    rpm/harbour-webcontrol.yaml \
    translations/*.ts \
    harbour-webcontrol.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172 512x512

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += \
    translations/harbour-webcontrol-de.ts \
    translations/harbout-webcontorl-zh_CN.ts

RESOURCES += \
    ressources.qrc

include(../QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/templateengine/templateengine.pri)

HEADERS += \
    src/data/datamanager.h \
    src/data/gobaldata.h \
    src/device/devicecontrol.h \
    src/device/globaldevice.h \
    src/tools/imagetools.h \
    src/web/controller/restapicontroller.h \
    src/web/globalweb.h \
    src/web/requestmapper.h \
    src/web/webserver.h \
    src/webcontrol.h
