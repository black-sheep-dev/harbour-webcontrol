#include "webcontrol.h"

#include <QFile>
#include <QNetworkInterface>
#include <QSettings>
#include <QStandardPaths>

#include "device/globaldevice.h"

WebControl::WebControl(QObject *parent) :
    QObject(parent),
    m_server(new WebServer(this))
{
    // global device control
    g_deviceControl = new DeviceControl(this);

    // create default settings file on first start
    QFile file(QSettings().fileName());

    if (!file.exists())
        writeSettings();

    readSettings();

    updateWebUrl();
}

WebControl::~WebControl()
{
    writeSettings();
}

void WebControl::initialize()
{

}

void WebControl::saveSettings()
{
    writeSettings();
}

void WebControl::updateWebUrl()
{
    QString ip;

    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost) {
             ip = address.toString();
             break;
        }
    }

    setWebUrl(QString("http://%1:%2").arg(ip, QString::number(m_port)));
}

bool WebControl::active() const
{
    return m_active;
}

QString WebControl::webUrl() const
{
    return m_webUrl;
}

quint32 WebControl::cleanupInterval() const
{
    return m_cleanupInterval;
}

QString WebControl::host() const
{
    return m_host;
}

quint32 WebControl::maxMultiPartSize() const
{
    return m_maxMultiPartSize;
}

quint32 WebControl::maxRequestSize() const
{
    return m_maxRequestSize;
}

quint8 WebControl::maxThreads() const
{
    return m_maxThreads;
}

quint8 WebControl::minThreads() const
{
    return m_minThreads;
}

quint16 WebControl::port() const
{
    return m_port;
}

quint32 WebControl::readTimeout() const
{
    return m_readTimeout;
}

void WebControl::setActive(bool active)
{
    if (m_active == active)
        return;

    m_active = active;
    emit activeChanged(m_active);

    // functions
    if (m_active) {
        m_server->start();
        updateWebUrl();
    } else {
        m_server->stop();
    }
}

void WebControl::setWebUrl(const QString &url)
{
    if (m_webUrl == url)
        return;

    m_webUrl = url;
    emit webUrlChanged(m_webUrl);
}

void WebControl::setCleanupInterval(quint32 interval)
{
    if (m_cleanupInterval == interval)
        return;

    m_cleanupInterval = interval;
    emit cleanupIntervalChanged(m_cleanupInterval);
}

void WebControl::setHost(const QString &host)
{
    if (m_host == host)
        return;

    m_host = host;
    emit hostChanged(m_host);
}

void WebControl::setMaxMultiPartSize(quint32 size)
{
    if (m_maxMultiPartSize == size)
        return;

    m_maxMultiPartSize = size;
    emit maxMultiPartSizeChanged(m_maxMultiPartSize);
}

void WebControl::setMaxRequestSize(quint32 size)
{
    if (m_maxRequestSize == size)
        return;

    m_maxRequestSize = size;
    emit maxRequestSizeChanged(m_maxRequestSize);
}

void WebControl::setMaxThreads(quint8 threads)
{
    if (m_maxThreads == threads)
        return;

    m_maxThreads = threads;
    emit maxThreadsChanged(m_maxThreads);
}

void WebControl::setMinThreads(quint8 threads)
{
    if (m_minThreads == threads)
        return;

    m_minThreads = threads;
    emit minThreadsChanged(m_minThreads);
}

void WebControl::setPort(quint16 port)
{
    if (m_port == port)
        return;

    m_port = port;
    emit portChanged(m_port);
}

void WebControl::setReadTimeout(quint32 timeout)
{
    if (m_readTimeout == timeout)
        return;

    m_readTimeout = timeout;
    emit readTimeoutChanged(m_readTimeout);
}

void WebControl::readSettings()
{
    QSettings settings;

    settings.beginGroup(QStringLiteral("APP"));
    setActive(settings.value(QStringLiteral("active"), false).toBool());
    settings.endGroup();
}

void WebControl::writeSettings()
{
    QSettings settings;

    settings.beginGroup(QStringLiteral("APP"));
    settings.setValue(QStringLiteral("active"), m_active);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("files"));
    settings.setValue(QStringLiteral("cacheSize"), 1000000);
    settings.setValue(QStringLiteral("cacheTime"), 60000);
    settings.setValue(QStringLiteral("encoding"), QStringLiteral("UTF-8"));
    settings.setValue(QStringLiteral("maxAge"), 90000);
    settings.setValue(QStringLiteral("maxCachedFileSize"), 65536);
    settings.setValue(QStringLiteral("path"), QStringLiteral("/usr/share/") + APP_TARGET + QStringLiteral("/frontend/"));
    settings.endGroup();

    settings.beginGroup(QStringLiteral("listener"));
    settings.setValue(QStringLiteral("host"), m_host);
    settings.setValue(QStringLiteral("port"), m_port);
    settings.setValue(QStringLiteral("minThreads"), m_minThreads);
    settings.setValue(QStringLiteral("maxThreads"), m_maxThreads);
    settings.setValue(QStringLiteral("cleanupInterval"), m_cleanupInterval);
    settings.setValue(QStringLiteral("readTimeout"), m_readTimeout);
    settings.setValue(QStringLiteral("maxRequestSize"), m_maxRequestSize);
    settings.setValue(QStringLiteral("maxMultiPartSize"), m_maxMultiPartSize);
    settings.endGroup();

    settings.beginGroup(QStringLiteral("templates"));
    settings.setValue(QStringLiteral("cacheSize"), 1000000);
    settings.setValue(QStringLiteral("cacheTime"), 60000);
    settings.setValue(QStringLiteral("encoding"), QStringLiteral("UTF-8"));
    settings.setValue(QStringLiteral("path"), QStringLiteral("/usr/share/") + APP_TARGET + QStringLiteral("/frontend/"));
    settings.setValue(QStringLiteral("suffix"), QStringLiteral(".html"));
    settings.endGroup();
}
