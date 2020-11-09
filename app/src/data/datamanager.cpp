#include "datamanager.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

#include "src/tools/imagetools.h"

DataManager::DataManager(QObject *parent) :
    QObject(parent)
{

}

QByteArray DataManager::contacts() const
{
    QJsonArray array;

    const QList<QtContacts::QContact> contacts = m_contactManager->contacts();
    for (const auto &contact : contacts) {
        if (contact.isEmpty()) {
            continue; }

        QJsonObject obj;
        obj.insert(QStringLiteral("id"), contact.id().toString());

        // avatar
        QJsonObject avatar;
        const QMap<int, QVariant> avatarMap = contact.detail(QtContacts::QContactDetail::TypeAvatar).values();
        avatar.insert(QStringLiteral("image"), ImageTools::imageToBase64(avatarMap.value(0).toUrl().toLocalFile()));
        obj.insert(QStringLiteral("avatar"), avatar);

        // name
        QJsonObject name;
        const QMap<int, QVariant> nameMap = contact.detail(QtContacts::QContactDetail::TypeName).values();
        name.insert(QStringLiteral("first"), nameMap.value(1).toString());
        name.insert(QStringLiteral("last"), nameMap.value(3).toString());
        obj.insert(QStringLiteral("name"), name);

#ifdef QT_DEBUG
        qDebug() << avatarMap;
#endif
        array.append(obj);
    }

    return QJsonDocument(array).toJson(QJsonDocument::Compact);
}
