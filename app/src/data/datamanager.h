#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

#include <QContactManager>

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);

    QByteArray contacts() const;

private:
    QtContacts::QContactManager *m_contactManager{new QtContacts::QContactManager(this)};
};

#endif // DATAMANAGER_H
