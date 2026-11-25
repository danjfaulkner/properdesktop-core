// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#include "application.h"

#include "base/i18n.h"
#include "ui/application.h"

int main(int argc, char *argv[])
{
    properdesktop::ui::Application app(argc, argv);
    app.setApplicationId("properdesktop-services");
    properdesktop::i18n::setDomain("properdesktop-core");
    Application services;
    return app.run();
}
