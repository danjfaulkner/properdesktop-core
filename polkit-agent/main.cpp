// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#include "polkitagentlistener.h"

#include "base/dbus.h"
#include "ui/application.h"

int main(int argc, char *argv[])
{
    properdesktop::ui::Application app(argc, argv);
    app.setApplicationId("properdesktop-polkit-agent");

    PolKitAgentListener listener(properdesktop::base::dbus::Connection::system());

    if (!listener.registerAgent("/org/properdesktop/PolicyKit1/AuthenticationAgent"))
        return -1;

    return app.run();
}
