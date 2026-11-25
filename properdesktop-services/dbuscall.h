// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#ifndef DBUSCALL_H
#define DBUSCALL_H

#include <functional>
#include <string>

#include "base/dbus.h"
#include "common/detached_call.h"

namespace services {

// Calls without keeping the pending call: `done` runs once the answer came,
// however long the caller lives. Capture only what outlives the call.
template<typename... Args>
void callDetached(const properdesktop::base::dbus::Proxy &proxy, const std::string &method,
                  std::function<void(const properdesktop::base::dbus::Reply &)> done, const Args &...args)
{
    properdesktop::base::dbus::Connection *connection = proxy.connection();
    properdesktop::base::dbus::Message call;
    if (connection) {
        call = connection->newMethodCall(proxy.service(), proxy.path(), proxy.interface(), method);
        call.append(args...);
    }
    properdesktop::core::callDetached(connection, call, std::move(done));
}

} // namespace services

#endif // DBUSCALL_H
