#include <QtQuick>

#include <sailfishapp.h>

#include "webcontrol.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationVersion(APP_VERSION);
    QCoreApplication::setOrganizationName(QStringLiteral("nubecula.org"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("nubecula.org"));

    qmlRegisterSingletonType<WebControl>("org.nubecula.harbour.webcontrol",
                                         1,
                                         0,
                                         "WebControl",
                                         [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {

        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        auto *control = new WebControl();

        return control;
    });

    return SailfishApp::main(argc, argv);
}
