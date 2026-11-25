project(properdesktop-applications-folder)
set(TARGET properdesktop-applications-folder)

set(SOURCES
    applicationsfolderservice.cpp
    applicationsfolderservice.h
    main.cpp
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET}
    ProperDesktop::ToolkitBase
    properdesktop-core-common
)

configure_file(org.properdesktop.ApplicationsFolder.service.in org.properdesktop.ApplicationsFolder.service @ONLY)
configure_file(properdesktop-applications-folder.service.in properdesktop-applications-folder.service @ONLY)

install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_LIBEXECDIR})
install(FILES org.properdesktop.ApplicationsFolder.conf DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system.d)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/org.properdesktop.ApplicationsFolder.service
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system-services)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/properdesktop-applications-folder.service DESTINATION lib/systemd/system)
install(FILES org.properdesktop.applications-folder.policy DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/polkit-1/actions)
