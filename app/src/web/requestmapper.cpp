#include "requestmapper.h"

#include "template.h"

RequestMapper::RequestMapper(QObject *parent) :
    HttpRequestHandler(parent)
{

}

void RequestMapper::service(HttpRequest &request, HttpResponse &response)
{
    const QByteArray path = request.getPath();

    // api first
    if (path.startsWith("/api")) {
        m_restApiController.service(request, response);
        return;
    }

    // serve assets
    if ( path.startsWith("/css") ||
         path.startsWith("/fonts") ||
         path.startsWith("/img") ||
         path.startsWith("/js") ) {
            g_staticFileController->service(request, response);
            return;
    }

    const QByteArray language = request.getHeader("Accept-Language");
    response.setHeader("Content-Type", "text/html; charset=utf-8");

    Template dashboard = g_templateCache->getTemplate("/index");

    response.write(dashboard.toUtf8(), true);

    //response.write("Hello World", true);
}
