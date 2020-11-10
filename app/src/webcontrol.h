#ifndef WEBCONTROL_H
#define WEBCONTROL_H

#include <QObject>

#include "httplistener.h"
#include "httprequesthandler.h"

#include "web/webserver.h"

class WebControl : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(QString webUrl READ webUrl WRITE setWebUrl NOTIFY webUrlChanged)

    // listener properties
    Q_PROPERTY(quint32 cleanupInterval READ cleanupInterval WRITE setCleanupInterval NOTIFY cleanupIntervalChanged)
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(quint32 maxMultiPartSize READ maxMultiPartSize WRITE setMaxMultiPartSize NOTIFY maxMultiPartSizeChanged)
    Q_PROPERTY(quint32 maxRequestSize READ maxRequestSize WRITE setMaxRequestSize NOTIFY maxRequestSizeChanged)
    Q_PROPERTY(quint8 maxThreads READ maxThreads WRITE setMaxThreads NOTIFY maxThreadsChanged)
    Q_PROPERTY(quint8 minThreads READ minThreads WRITE setMinThreads NOTIFY minThreadsChanged)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(quint32 readTimeout READ readTimeout WRITE setReadTimeout NOTIFY readTimeoutChanged)

public:
    explicit WebControl(QObject *parent = nullptr);
    ~WebControl() override;

    Q_INVOKABLE void initialize();
    Q_INVOKABLE void saveSettings();
    Q_INVOKABLE void updateWebUrl();

    // properties
    bool active() const;
    QString webUrl() const;

    // listener properties
    quint32 cleanupInterval() const;
    QString host() const;
    quint32 maxMultiPartSize() const;
    quint32 maxRequestSize() const;
    quint8 maxThreads() const;
    quint8 minThreads() const;
    quint16 port() const;
    quint32 readTimeout() const;

signals:
    // properties
    void activeChanged(bool active);
    void webUrlChanged(const QString &url);

    // listener properties
    void cleanupIntervalChanged(quint32 interval);
    void hostChanged(const QString &host);
    void maxMultiPartSizeChanged(quint32 size);
    void maxRequestSizeChanged(quint32 size);
    void maxThreadsChanged(quint8 threads);
    void minThreadsChanged(quint8 threads);
    void portChanged(quint16 port);
    void readTimeoutChanged(quint32 timeout);

public slots:
    // properties
    void setActive(bool active = true);
    void setWebUrl(const QString &url);

    // listener properties
    void setCleanupInterval(quint32 interval);
    void setHost(const QString &host);
    void setMaxMultiPartSize(quint32 size);
    void setMaxRequestSize(quint32 size);
    void setMaxThreads(quint8 threads);
    void setMinThreads(quint8 threads);
    void setPort(quint16 port);
    void setReadTimeout(quint32 timeout);

private:
    void initSettings();
    void readSettings();
    void writeSettings();

    WebServer *m_server{nullptr};

    // properties
    bool m_active{false};
    QString m_webUrl;

    // listener properties
    quint32 m_cleanupInterval{60000};
    QString m_host{QStringLiteral("0.0.0.0")};
    quint32 m_maxMultiPartSize{10000000};
    quint32 m_maxRequestSize{16000};
    quint8 m_maxThreads{10};
    quint8 m_minThreads{2};
    quint16 m_port{8080};
    quint32 m_readTimeout{60000};

};

#endif // WEBCONTROL_H
