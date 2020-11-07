#ifndef RESTAPICONTROLLER_H
#define RESTAPICONTROLLER_H

#include "httprequesthandler.h"

#include "../globalweb.h"

class RestApiController : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit RestApiController(QObject *parent = nullptr);

    // HttpRequestHandler interface
public:
    void service(HttpRequest &request, HttpResponse &response) override;
};

#endif // RESTAPICONTROLLER_H
