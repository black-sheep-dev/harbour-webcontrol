#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H

#include <QFile>

class ImageTools {

public:
    static QString imageToBase64(const QString &path){
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly))
            return QByteArray();

        const QString data = file.readAll().toBase64();

        file.close();

        return data;
    }
};



#endif // IMAGETOOLS_H
