#include "devicecontrol.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <mdm-sysinfo.h>

DeviceControl::DeviceControl(QObject *parent) :
    QObject(parent)
{

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

QByteArray DeviceControl::simInfo() const
{
    QJsonObject info;

    info.insert(QStringLiteral("available"), m_simInfo->available());
    info.insert(QStringLiteral("hotswap_support"), m_simInfo->hotSwappingSupported());
    info.insert(QStringLiteral("sim_count"), m_simInfo->cardIdentifier().count());

    // sim cards
    QJsonArray sims;
    int idx{0};
    for (const auto &state : m_simInfo->simSlotStates()) {
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
    for (const auto &info : m_simInfo->imeiCodes()) {
        imeis.append(info.value);
    }
    info.insert(QStringLiteral("IMEIS"), imeis);

    QJsonArray imsis;
    for (const auto &info : m_simInfo->subscriberIdentities()) {
        imsis.append(info.value);
    }
    info.insert(QStringLiteral("IMSIS"), imsis);

    QJsonArray iccids;
    for (const auto &info : m_simInfo->cardIdentifier()) {
        iccids.append(info.value);
    }
    info.insert(QStringLiteral("ICCIDS"), iccids);

    QJsonArray ssns;
    for (const auto &info : m_simInfo->subscriberNumbers()) {
        ssns.append(info.value);
    }
    info.insert(QStringLiteral("SNNS"), ssns);

    return QJsonDocument(info).toJson(QJsonDocument::Compact);
}
