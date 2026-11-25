project(properdesktop-privacy)
set(TARGET properdesktop-privacy)

set(SOURCES
    captureswitches.cpp
    captureswitches.h
    main.cpp
    privacyservice.cpp
    privacyservice.h
    usbcameras.cpp
    usbcameras.h
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET}
    ProperDesktop::ToolkitBase
    properdesktop-core-common
)

configure_file(org.properdesktop.Privacy.service.in org.properdesktop.Privacy.service @ONLY)
configure_file(properdesktop-privacy.service.in properdesktop-privacy.service @ONLY)

install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_LIBEXECDIR})
install(FILES org.properdesktop.Privacy.conf DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system.d)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/org.properdesktop.Privacy.service
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system-services)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/properdesktop-privacy.service DESTINATION lib/systemd/system)
install(FILES org.properdesktop.privacy.policy DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/polkit-1/actions)
install(FILES 60-properdesktop-privacy.rules DESTINATION lib/udev/rules.d)
