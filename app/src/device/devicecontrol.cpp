#include "devicecontrol.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

#include <mdm-applications.h>
#include <mdm-sysinfo.h>

#include <QContact>

#include "src/tools/imagetools.h"

DeviceControl::DeviceControl(QObject *parent) :
    QObject(parent)
{

}

QByteArray DeviceControl::applications() const
{
    QJsonArray array;

    const QList<Sailfish::Mdm::ApplicationEntry> apps = Sailfish::Mdm::Applications().getInstalledApplications();
    for (const auto &app : apps) {
        const Sailfish::Mdm::PackageEntry package = app.package();

        QJsonObject obj;
        obj.insert(QStringLiteral("name"), app.name());
        obj.insert(QStringLiteral("icon"), ImageTools::imageToBase64(app.iconPath()));
        obj.insert(QStringLiteral("package"), package.name());
        obj.insert(QStringLiteral("valid"), package.isValid());
        obj.insert(QStringLiteral("vendor"), package.vendor());
        obj.insert(QStringLiteral("version"), package.version());

        array.append(obj);
    }

    return QJsonDocument(array).toJson(QJsonDocument::Compact);
}

QByteArray DeviceControl::batteryInfo() const
{
    QJsonObject info;

    info.insert(QStringLiteral("charge_percentage"), m_batteryInfo->chargePercentage());
    info.insert(QStringLiteral("charger_status"), m_batteryInfo->chargerStatus());
    info.insert(QStringLiteral("status"), m_batteryInfo->status());

    return QJsonDocument(info).toJson(QJsonDocument::Compact);
}

QByteArray DeviceControl::deviceInfo() const
{
    QJsonObject info;

    info.insert(QStringLiteral("software_version"), Sailfish::Mdm::SysInfo::softwareVersion());
    info.insert(QStringLiteral("software_version_id"), Sailfish::Mdm::SysInfo::softwareVersionId());
    info.insert(QStringLiteral("device_model"), Sailfish::Mdm::SysInfo::deviceModel());
    info.insert(QStringLiteral("device_uid"), Sailfish::Mdm::SysInfo::deviceUid());
    info.insert(QStringLiteral("bluetooth_mac"), Sailfish::Mdm::SysInfo::bluetoothMacAddress());
    info.insert(QStringLiteral("wlan_mac"), Sailfish::Mdm::SysInfo::wlanMacAddress());
    info.insert(QStringLiteral("product_name"), Sailfish::Mdm::SysInfo::productName());
    info.insert(QStringLiteral("manufacturer"), Sailfish::Mdm::SysInfo::manufacturer());

    return QJsonDocument(info).toJson(QJsonDocument::Compact);
}

QByteArray DeviceControl::deviceStatus() const
{
    QJsonObject info;

    // battery
    QJsonObject battery;
    battery.insert(QStringLiteral("charge_percentage"), m_batteryInfo->chargePercentage());
    battery.insert(QStringLiteral("charger_status"), m_batteryInfo->chargerStatus());
    info.insert(QStringLiteral("battery"), battery);

    // device lock
    QJsonObject deviceLock;
    deviceLock.insert(QStringLiteral("state"), m_deviceLock->state());
    deviceLock.insert(QStringLiteral("home_encrypted"), m_deviceLock->isHomeEncrypted());
    info.insert(QStringLiteral("device_lock"), deviceLock);

    // software update available
//    QJsonObject software;
//    software.insert(QStringLiteral("update_available"), m_softwareUpdate->softwareUpdateIsAvailable());
//    software.insert(QStringLiteral("lastest_version"), m_softwareUpdate->latestAvailableUpdateVersion());
//    info.insert(QStringLiteral("software"), software);

    return QJsonDocument(info).toJson(QJsonDocument::Compact);
}

QByteArray DeviceControl::simInfo() const
{
    QJsonObject info;

    info.insert(QStringLiteral("available"), m_simInfo->available());
    info.insert(QStringLiteral("hotswap_support"), m_simInfo->hotSwappingSupported());
    info.insert(QStringLiteral("sim_count"), m_simInfo->cardIdentifier().count());

    // sim cards
    QJsonArray sims;
    int idx{0};
    const QList<Sailfish::Mdm::SimInfo::SimState> simStates = m_simInfo->simSlotStates();
    for (const auto &state : simStates) {
        QJsonObject sim;
        sim.insert(QStringLiteral("card_identifier"), state.cardIdentifier);
        sim.insert(QStringLiteral("data_sim"), state.dataSim);
        sim.insert(QStringLiteral("enabled"), state.enabled);
        sim.insert(QStringLiteral("imsi"), state.imsi);
        sim.insert(QStringLiteral("modem_path"), state.modemPath);


        sim.insert(QStringLiteral("present"), state.present);
        sim.insert(QStringLiteral("service_provider_name"), state.serviceProviderName);
        sim.insert(QStringLiteral("pin_required"), state.pinRequired);
        sim.insert(QStringLiteral("network_registration_status"), state.networkRegistrationStatus);

        QJsonArray numbers;
        for (const QString &number : state.subscriberNumbers) {
            numbers.append(number);
        }
        sim.insert(QStringLiteral("subcriber_numbers"), numbers);

        sim.insert(QStringLiteral("voice_sim"), state.voiceSim);
        sim.insert(QStringLiteral("imei"), m_simInfo->imeiCodes().at(idx).value);

        sims.append(sim);

        idx++;
    }
    info.insert(QStringLiteral("sim_cards"), sims);

    // other
    QJsonArray imeis;
    const QList<Sailfish::Mdm::SimInfo::SlotInfo> imeiInfos = m_simInfo->imeiCodes();
    for (const auto &info : imeiInfos) {
        imeis.append(info.value);
    }
    info.insert(QStringLiteral("IMEIS"), imeis);

    QJsonArray imsis;
    const QList<Sailfish::Mdm::SimInfo::SlotInfo> imsiInfos = m_simInfo->subscriberIdentities();
    for (const auto &info : imsiInfos) {
        imsis.append(info.value);
    }
    info.insert(QStringLiteral("IMSIS"), imsis);

    QJsonArray iccids;
    const QList<Sailfish::Mdm::SimInfo::SlotInfo> iccidInfos = m_simInfo->cardIdentifier();
    for (const auto &info : iccidInfos) {
        iccids.append(info.value);
    }
    info.insert(QStringLiteral("ICCIDS"), iccids);

    QJsonArray ssns;
    const QList<Sailfish::Mdm::SimInfo::SlotInfo> ssnsInfos = m_simInfo->subscriberNumbers();
    for (const auto &info : ssnsInfos) {
        ssns.append(info.value);
    }
    info.insert(QStringLiteral("SNNS"), ssns);

    return QJsonDocument(info).toJson(QJsonDocument::Compact);
}

QByteArray DeviceControl::softwareUpdate() const
{
    QJsonObject info;

    info.insert(QStringLiteral("update_available"), m_softwareUpdate->softwareUpdateIsAvailable());
    info.insert(QStringLiteral("lastest_version"), m_softwareUpdate->latestAvailableUpdateVersion());

    return QJsonDocument(info).toJson(QJsonDocument::Compact);
}
