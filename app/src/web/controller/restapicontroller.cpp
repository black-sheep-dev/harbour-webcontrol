#include "restapicontroller.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "src/data/gobaldata.h"
#include "src/device/globaldevice.h"

RestApiController::RestApiController(QObject *parent) :
    HttpRequestHandler(parent)
{

}

void RestApiController::service(HttpRequest &request, HttpResponse &response)
{
    // CORS
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Cache-Control", "no-cache");
    response.setHeader("Access-Control-Allow-Origin", "*");
    response.setHeader("Access-Control-Allow-Methods", "*");
    response.setHeader("Access-Control-Allow-Headers", "*");
    response.setStatus(200, "OK");

    const QByteArray path = request.getPath();

    // handel enpoints
    if (path == "/api") {
        response.write("{\"api_version\":1}");
    } else if (path == "/api/device/status") {
        response.write(g_deviceControl->deviceStatus());
    } else if (path == "/api/device/info") {
        response.write(g_deviceControl->deviceInfo());
    } else if (path == "/api/siminfo") {
        response.write(g_deviceControl->simInfo());
    } else if (path == "/api/batteryinfo") {
        response.write(g_deviceControl->batteryInfo());
    } else if (path == "/api/apps") {
        response.write(g_deviceControl->applications());
    } else if (path == "/api/contacts") {
        response.write(g_dataManager->contacts());
    } else if (path == "/api/update") {
        response.write(g_deviceControl->softwareUpdate());
    } else {
        response.write(R"({"error":"not found"})");
    }

}
