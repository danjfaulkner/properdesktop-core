project(properdesktop-locales)
set(TARGET properdesktop-locales)

set(SOURCES
    localesservice.cpp
    localesservice.h
    main.cpp
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET}
    ProperDesktop::ToolkitBase
    properdesktop-core-common
)

configure_file(org.properdesktop.Locales.service.in org.properdesktop.Locales.service @ONLY)
configure_file(properdesktop-locales.service.in properdesktop-locales.service @ONLY)

install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_LIBEXECDIR})
install(FILES org.properdesktop.Locales.conf DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system.d)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/org.properdesktop.Locales.service
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system-services)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/properdesktop-locales.service DESTINATION lib/systemd/system)
install(FILES org.properdesktop.locales.policy DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/polkit-1/actions)
