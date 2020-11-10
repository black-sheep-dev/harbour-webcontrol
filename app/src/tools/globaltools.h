#ifndef GLOBALIMAGE_H
#define GLOBALIMAGE_H

#include <QStandardPaths>

static const QString LOCAL_CACHE_PATH = QStandardPaths::writableLocation(QStandardPaths::CacheLocation)
                                        + QStringLiteral("/") + APP_TARGET;

#include "imagecache.h"

extern ImageCache* g_imageCache;


#endif // GLOBALIMAGE_H
