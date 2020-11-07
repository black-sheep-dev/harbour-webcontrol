#ifndef DEVICECONTROL_H
#define DEVICECONTROL_H

#include <QObject>

#include <mdm-batteryinfo.h>
#include <mdm-siminfo.h>

class DeviceControl : public QObject
{
    Q_OBJECT
public:
    explicit DeviceControl(QObject *parent = nullptr);

    QByteArray batteryInfo() const;
    QByteArray deviceInfo() const;
    QByteArray simInfo() const;

private:
    Sailfish::Mdm::BatteryInfo *m_batteryInfo{new Sailfish::Mdm::BatteryInfo(this)};
    Sailfish::Mdm::SimInfo *m_simInfo{new Sailfish::Mdm::SimInfo(this)};
};

#endif // DEVICECONTROL_H
