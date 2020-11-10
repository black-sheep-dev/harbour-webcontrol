#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

#include <QContactManager>

using namespace QtContacts;

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);

    QByteArray contacts() const;

public slots:
    void refreshContacts();

private:
    QJsonObject addressToJson(const QContactDetail &detail) const;
    QJsonObject emailAddressToJson(const QContactDetail &detail) const;
    QJsonObject nameToJson(const QContactDetail &detail) const;
    QJsonObject organizationToJson(const QContactDetail &detail) const;
    QJsonObject phoneNumberToJson(const QContactDetail &detail) const;

    QByteArray m_contacts;
    QContactManager *m_contactManager{new QtContacts::QContactManager(this)};
};

#endif // DATAMANAGER_H
