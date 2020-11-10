#include "datamanager.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QUuid>

#include <QContactAddress>
#include <QContactDetail>
#include <QContactEmailAddress>
#include <QContactName>
#include <QContactPhoneNumber>
#include <QContactOrganization>

#include "src/tools/globaltools.h"
#include "src/tools/imagetools.h"

DataManager::DataManager(QObject *parent) :
    QObject(parent)
{
    connect(m_contactManager, &QtContacts::QContactManager::contactsAdded, this, &DataManager::refreshContacts);
    connect(m_contactManager, &QtContacts::QContactManager::contactsChanged, this, &DataManager::refreshContacts);
    connect(m_contactManager, &QtContacts::QContactManager::contactsRemoved, this, &DataManager::refreshContacts);

    refreshContacts();
}

QByteArray DataManager::contacts() const
{
    return m_contacts;
}

void DataManager::refreshContacts()
{
    g_imageCache->clearCacheDestination(QStringLiteral("/avatars"));

    QJsonArray array;

    const QList<QtContacts::QContact> contacts = m_contactManager->contacts();
    for (const auto &contact : contacts) {
        if (contact.isEmpty()) {
            continue;
        }

        QJsonObject obj;
        obj.insert(QStringLiteral("id"), contact.id().toString());

        // guid
        QString guid = QUuid::createUuid().toString();
        guid = guid.mid(1, guid.length() - 2);
        obj.insert(QStringLiteral("guid"), guid);

        // avatar
        QJsonObject avatar;
        const QString avatarFile = contact.detail(QContactDetail::TypeAvatar).value(0).toUrl().toLocalFile();
        const QString avatarCache = QStringLiteral("/avatars/")
                + guid
                + QStringLiteral(".")
                + QFileInfo(avatarFile).suffix();

        if (g_imageCache->cacheImage(avatarFile, avatarCache)) {
            avatar.insert(QStringLiteral("image"), LOCAL_IMAGE_CACHE_PATH + avatarCache);
        } else {
            avatar.insert(QStringLiteral("image"), QString());
        }
        obj.insert(QStringLiteral("avatar"), avatar);

        // name
        obj.insert(QStringLiteral("name"), nameToJson(contact.detail(QContactDetail::TypeName)));

        // numbers
        const QList<QContactDetail> numberDetails = contact.details(QContactDetail::TypePhoneNumber);

        QJsonArray phoneNumbers;
        for (const auto &nr : numberDetails) {
            phoneNumbers.append(phoneNumberToJson(nr));
        }
        obj.insert(QStringLiteral("phone_numbers"), phoneNumbers);

        // emails
        QJsonArray emailAddresses;
        for (const auto &addr : contact.details(QContactDetail::TypeEmailAddress)) {
            emailAddresses.append(emailAddressToJson(addr));
        }
        obj.insert(QStringLiteral("email"), emailAddresses);

        // addresses
        const QList<QContactDetail> addressDetails = contact.details(QContactDetail::TypeAddress);

        QJsonArray addresses;
        for (const auto &addr : addressDetails) {
            addresses.append(addressToJson(addr));
        }
        obj.insert(QStringLiteral("addresses"), addresses);

        // company
        const QJsonObject organization = organizationToJson(contact.detail(QContactDetail::TypeOrganization));

        if (!organization.isEmpty()) {
            obj.insert(QStringLiteral("organization"), organization);
        }


#ifdef QT_DEBUG
        //qDebug() << contact.detail(QContactDetail::TypeOrganization).values();
#endif

        array.append(obj);
    }

    m_contacts = QJsonDocument(array).toJson(QJsonDocument::Compact);
}

QJsonObject DataManager::addressToJson(const QContactDetail &detail) const
{
    const QContactAddress addrDetail = static_cast<QContactAddress>(detail);

    QJsonObject address;

    address.insert(QStringLiteral("street"), addrDetail.street());
    address.insert(QStringLiteral("locality"), addrDetail.locality());
    address.insert(QStringLiteral("region"), addrDetail.region());
    address.insert(QStringLiteral("postcode"), addrDetail.postcode());
    address.insert(QStringLiteral("country"), addrDetail.country());
    address.insert(QStringLiteral("post_box"), addrDetail.postOfficeBox());

    QJsonArray types;
    for (int type : addrDetail.subTypes()) {
        types.append(type);
    }
    address.insert(QStringLiteral("types"), types);

    return address;
}

QJsonObject DataManager::emailAddressToJson(const QContactDetail &detail) const
{
    const QContactEmailAddress emailDetails = static_cast<QContactEmailAddress>(detail);

    QJsonObject email;

    email.insert(QStringLiteral("address"), emailDetails.emailAddress());

    return email;
}

QJsonObject DataManager::nameToJson(const QContactDetail &detail) const
{
    const QContactName nameDetail = static_cast<QContactName>(detail);

    QJsonObject name;
    name.insert(QStringLiteral("prefix"), nameDetail.prefix());
    name.insert(QStringLiteral("first"), nameDetail.firstName());
    name.insert(QStringLiteral("middle"), nameDetail.middleName());
    name.insert(QStringLiteral("last"), nameDetail.lastName());
    name.insert(QStringLiteral("suffix"), nameDetail.suffix());

    return name;
}

QJsonObject DataManager::organizationToJson(const QContactDetail &detail) const
{
    const QContactOrganization organizationDetail = static_cast<QContactOrganization>(detail);

    QJsonObject organization;

    organization.insert(QStringLiteral("valid"), !organizationDetail.name().isEmpty());

    organization.insert(QStringLiteral("name"), organizationDetail.name());
    organization.insert(QStringLiteral("logo_url"), organizationDetail.logoUrl().toString());

    QJsonArray departments;
    for (const auto &department : organizationDetail.department()) {
        departments.append(department);
    }
    organization.insert(QStringLiteral("department"), departments);

    organization.insert(QStringLiteral("location"), organizationDetail.location());
    organization.insert(QStringLiteral("role"), organizationDetail.role());
    organization.insert(QStringLiteral("title"), organizationDetail.title());
    organization.insert(QStringLiteral("assistant_name"), organizationDetail.assistantName());

    return organization;
}

QJsonObject DataManager::phoneNumberToJson(const QContactDetail &detail) const
{
    const QContactPhoneNumber nrDetail = static_cast<QContactPhoneNumber>(detail);

    QJsonObject number;
    number.insert(QStringLiteral("number"), nrDetail.number());

    QJsonArray types;
    for (int type : nrDetail.subTypes()) {
        types.append(type);
    }
    number.insert(QStringLiteral("types"), types);

    return number;
}
