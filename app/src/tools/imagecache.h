#ifndef IMAGECACHE_H
#define IMAGECACHE_H

#include <QObject>

static const QString LOCAL_IMAGE_CACHE_PATH = QStringLiteral("/images");

#include <QList>
#include <QSize>

class ImageCache : public QObject
{
    Q_OBJECT

public:
    explicit ImageCache(QObject *parent = nullptr);

    bool cacheImage(const QString &path,
                    const QString &dest,
                    const QList<QSize> &thumbnails = QList<QSize>());

    bool clearCacheDestination(const QString &dest);

private:
    void clear();
};

#endif // IMAGECACHE_H
