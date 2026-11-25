// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#include "applicationsfolderservice.h"

#include "base/dbus.h"
#include "base/event_loop.h"
#include "base/logging.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    properdesktop::base::EventLoop loop;
    static const properdesktop::base::LogCategory log("properdesktop.applicationsfolder");

    ApplicationsFolderService service;

    properdesktop::base::dbus::Connection *bus = properdesktop::base::dbus::Connection::system(&loop);
    if (!bus || !service.exportTo(bus) || !bus->requestName("org.properdesktop.ApplicationsFolder")) {
        CF_WARNING(log) << "properdesktop-applications-folder: cannot register on the system bus";
        return 1;
    }

    service.onIdle = [&loop] {
        loop.quit();
    };

    return loop.run();
}
