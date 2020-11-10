#include "imagecache.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>

#include "globaltools.h"

ImageCache::ImageCache(QObject *parent) :
    QObject(parent)
{
    clear();
}

bool ImageCache::cacheImage(const QString &path, const QString &dest, const QList<QSize> &thumbnails)
{
    Q_UNUSED(thumbnails)

    QFile in(path);

    if (!in.exists()) {
        return false;
    }

    // copy file to cache
    const QString target = LOCAL_CACHE_PATH
            + LOCAL_IMAGE_CACHE_PATH
            + dest;

    QDir().mkpath(QFileInfo(target).absoluteDir().path());
    if (!in.copy(target)) {
        return false;
    }

//    for (const auto &size : thumbnails) {

//    }

    return true;
}

void ImageCache::clear()
{
    QDir().remove(LOCAL_CACHE_PATH + LOCAL_IMAGE_CACHE_PATH);
}

bool ImageCache::clearCacheDestination(const QString &dest)
{
    return QDir().remove(LOCAL_CACHE_PATH + LOCAL_IMAGE_CACHE_PATH + dest);
}
