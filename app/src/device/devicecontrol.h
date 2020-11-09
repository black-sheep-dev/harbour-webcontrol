#ifndef DEVICECONTROL_H
#define DEVICECONTROL_H

#include <QObject>

#include <mdm-batteryinfo.h>
#include <mdm-devicelock.h>
#include <mdm-siminfo.h>
#include <mdm-softwareupdate.h>

class DeviceControl : public QObject
{
    Q_OBJECT
public:
    explicit DeviceControl(QObject *parent = nullptr);

    QByteArray applications() const;
    QByteArray batteryInfo() const;
    QByteArray deviceInfo() const;
    QByteArray deviceStatus() const;
    QByteArray simInfo() const;
    QByteArray softwareUpdate() const;

private:
    Sailfish::Mdm::BatteryInfo *m_batteryInfo{new Sailfish::Mdm::BatteryInfo(this)};
    Sailfish::Mdm::DeviceLock *m_deviceLock{new Sailfish::Mdm::DeviceLock(this)};
    Sailfish::Mdm::SimInfo *m_simInfo{new Sailfish::Mdm::SimInfo(this)};
    Sailfish::Mdm::SoftwareUpdate *m_softwareUpdate{new Sailfish::Mdm::SoftwareUpdate(this)};
};

#endif // DEVICECONTROL_H
