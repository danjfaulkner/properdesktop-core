#ifndef PROPERDESKTOP_SETTINGS_POWERMANAGER_H
#define PROPERDESKTOP_SETTINGS_POWERMANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "base/dbus.h"
#include "base/settings.h"
#include "base/signal.h"

class BrightnessManager;
class DisplayPolicy;
class PowerSupply;
class WaylandIdle;

class PowerManager
{
public:
    PowerManager(PowerSupply *powerSupply, BrightnessManager *brightness, WaylandIdle *idle,
                 properdesktop::base::Settings &settings, properdesktop::base::dbus::Connection *session,
                 properdesktop::base::dbus::Connection *system);
    ~PowerManager();

    PowerManager(const PowerManager &) = delete;
    PowerManager &operator=(const PowerManager &) = delete;

    // org.properdesktop.Services.Power at /org/properdesktop/Services/Power.
    bool publish();

    void setBatteryScreenOff(int timeout);
    void setACScreenOff(int timeout);
    void setACPreventSleep(bool prevent);
    void setDimDisplayTimeout(int timeout);

private:
    void onPowerSourceChanged();
    void onLidChanged();
    void loadSettings();
    void applyPolicy();
    template<typename T>
    void writePowerSetting(const std::string &key, const T &value);

    properdesktop::base::Settings &m_settings;
    properdesktop::base::dbus::Connection *m_session;
    PowerSupply *m_powerSupply;
    std::unique_ptr<DisplayPolicy> m_displayPolicy;
    std::unique_ptr<properdesktop::base::dbus::Object> m_object;
    std::vector<properdesktop::base::Subscription> m_subscriptions;

    int m_batteryScreenOff = 300;
    int m_acScreenOff = 1200;
    bool m_acPreventSleep = false;
    bool m_onBattery = false;
};

#endif
