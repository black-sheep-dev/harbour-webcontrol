#include "webserver.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "httprequesthandler.h"
#include "httpsessionstore.h"

#include "requestmapper.h"

WebServer::WebServer(QObject *parent) :
    QObject(parent)
{

}

void WebServer::start()
{
    // cache file controller
    auto* cacheSettings = new QSettings(this);
    cacheSettings->beginGroup(QStringLiteral("cache"));
    g_cacheFileController = new StaticFileController(cacheSettings, this);

    // static file controller
    auto* fileSettings = new QSettings(this);
    fileSettings->beginGroup(QStringLiteral("files"));
    g_staticFileController = new StaticFileController(fileSettings, this);

    // Configure template cache
    auto* templateSettings=new QSettings(this);
    templateSettings->beginGroup(QStringLiteral("templates"));
    g_templateCache = new TemplateCache(templateSettings, this);

    // HTTP server
    auto* listenerSettings = new QSettings(this);
    listenerSettings->beginGroup(QStringLiteral("listener"));

    m_listener = new HttpListener(listenerSettings, new RequestMapper(this), this);

#ifdef QT_DEBUG
    qDebug() << QStringLiteral("Server started");
#endif
}

void WebServer::stop()
{
    m_listener->close();
    m_listener->deleteLater();
    m_listener = nullptr;

#ifdef QT_DEBUG
    qDebug() << QStringLiteral("Server stopped");
#endif
}
