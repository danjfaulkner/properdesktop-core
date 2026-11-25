// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "base/logging.h"

inline const properdesktop::base::LogCategory& sessionLog()
{
    static const properdesktop::base::LogCategory category("properdesktop.session");
    return category;
}
