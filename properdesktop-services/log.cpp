// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#include "log.h"

namespace services {

const properdesktop::base::LogCategory &log()
{
    static const properdesktop::base::LogCategory category("properdesktop.services");
    return category;
}

} // namespace services
