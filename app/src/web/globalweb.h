#ifndef GLOBALWEB_H
#define GLOBALWEB_H

#include "httpsessionstore.h"
#include "staticfilecontroller.h"
#include "templatecache.h"

using namespace stefanfrings;

extern StaticFileController* g_cacheFileController;
extern HttpSessionStore* g_sessionStore;
extern StaticFileController* g_staticFileController;
extern TemplateCache* g_templateCache;

#endif // GLOBALWEB_H
