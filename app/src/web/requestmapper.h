#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"

#include "globalweb.h"

#include "controller/restapicontroller.h"

class RequestMapper : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit RequestMapper(QObject *parent = nullptr);

private:
    RestApiController m_restApiController{new RestApiController(this)};

    // HttpRequestHandler interface
public:
    void service(HttpRequest &request, HttpResponse &response) override;
};

#endif // REQUESTMAPPER_H
