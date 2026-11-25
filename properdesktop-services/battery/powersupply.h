// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include <memory>
#include <set>
#include <string>
#include <vector>

#include "base/dbus.h"
#include "base/settings.h"
#include "base/signal.h"

class Battery;

// What UPower knows of the power source and the lid, and the computer's batteries.
class PowerSupply
{
public:
    // UPower on `system`; the batteries, taken together, are published on `session`.
    PowerSupply(properdesktop::base::dbus::Connection *system, properdesktop::base::dbus::Connection *session,
                properdesktop::base::Settings &settings);
    ~PowerSupply();

    PowerSupply(const PowerSupply &) = delete;
    PowerSupply &operator=(const PowerSupply &) = delete;

    bool onBattery() const { return m_onBattery; }
    bool hasLid() const { return m_hasLid; }
    bool lidClosed() const { return m_lidClosed; }

    properdesktop::base::Signal<> powerSourceChanged;
    properdesktop::base::Signal<> lidPresenceChanged;
    properdesktop::base::Signal<> lidChanged;

private:
    void load();
    void readFlags(const properdesktop::base::dbus::VariantMap &values);
    bool isBattery(const std::string &path) const;
    void addBattery(const std::string &path);
    void removeBattery(const std::string &path);
    void publishBatteries();

    properdesktop::base::dbus::Connection *m_system;
    properdesktop::base::dbus::Connection *m_session;
    properdesktop::base::Settings &m_settings;
    properdesktop::base::dbus::Proxy m_upower;
    properdesktop::base::dbus::PendingCall m_activation;
    properdesktop::base::dbus::NameWatch m_upowerWatch;
    std::string m_upowerOwner;
    std::vector<properdesktop::base::dbus::Match> m_matches;
    // The UPower device paths of the batteries that power the computer.
    std::set<std::string> m_batteries;
    std::unique_ptr<Battery> m_published;
    bool m_onBattery = false;
    bool m_hasLid = false;
    bool m_lidClosed = false;
};

#endif // POWERSUPPLY_H
