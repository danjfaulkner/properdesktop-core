project(properdesktop-appruntime)
set(TARGET properdesktop-appruntime)

pkg_check_modules(Systemd REQUIRED IMPORTED_TARGET libsystemd)

set(SOURCES
    applicationscope.cpp
    applicationscope.h
    appruntime.cpp
    appruntime.h
    chromiumswitches.cpp
    chromiumswitches.h
    main.cpp
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET}
    properdesktop-core-common
    ProperDesktop::ToolkitBase
    PkgConfig::Systemd
)

install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_BINDIR})
