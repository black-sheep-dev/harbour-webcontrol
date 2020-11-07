#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>

#include "httplistener.h"

#include "globalweb.h"

class WebServer : public QObject
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);

    void start();
    void stop();

private:
    HttpListener *m_listener{nullptr};
};

#endif // WEBSERVER_H
