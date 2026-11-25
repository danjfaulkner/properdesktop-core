find_package(ProperDesktopToolkit REQUIRED)

add_executable(properdesktop-polkit-agent
    main.cpp
    polkitagentlistener.cpp
    polkitagentlistener.h
    authsession.cpp
    authsession.h
    dialog.cpp
    dialog.h
)
set_target_properties(properdesktop-polkit-agent PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

target_link_libraries(properdesktop-polkit-agent PRIVATE ProperDesktop::Toolkit)

install(TARGETS properdesktop-polkit-agent
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT Runtime
)
