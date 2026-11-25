#pragma once

#include <functional>
#include <string>

#include "base/file.h"
#include "base/file_watcher.h"
#include "base/timer.h"

class XwaylandEnvironment final
{
public:
    XwaylandEnvironment();
    std::string readinessFile() const;
    void waitForReady(int timeoutMs = 12000);

    std::function<void(bool available)> onResolved;
    std::function<void()> onLost;

private:
    void check();
    properdesktop::base::file::TemporaryDirectory m_directory;
    properdesktop::base::FileWatch m_watch;
    properdesktop::base::Timer m_timeout;
    bool m_waiting = false;
    bool m_available = false;
};
