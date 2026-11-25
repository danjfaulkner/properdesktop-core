cmake_minimum_required(VERSION 3.22)
project(appruntime_tests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(ProperDesktopToolkit REQUIRED)
find_package(GTest REQUIRED)
include(GoogleTest)
find_package(PkgConfig REQUIRED)
enable_testing()

add_subdirectory(../../common ${CMAKE_CURRENT_BINARY_DIR}/common)

add_executable(application-scope-test application_scope_test.cpp ../applicationscope.cpp)
target_include_directories(application-scope-test PRIVATE ..)
target_link_libraries(application-scope-test PRIVATE properdesktop-core-common ProperDesktop::ToolkitBase GTest::gtest_main)
add_test(NAME application-scope COMMAND application-scope-test)

add_executable(chromium-switches-test chromium_switches_test.cpp ../chromiumswitches.cpp)
target_include_directories(chromium-switches-test PRIVATE ..)
target_link_libraries(chromium-switches-test PRIVATE ProperDesktop::ToolkitBase GTest::gtest_main)
add_test(NAME chromium-switches COMMAND chromium-switches-test)

# The runtime itself, on a private bus.
pkg_check_modules(Systemd REQUIRED IMPORTED_TARGET libsystemd)
add_executable(properdesktop-appruntime ../main.cpp ../appruntime.cpp ../applicationscope.cpp ../chromiumswitches.cpp)
target_include_directories(properdesktop-appruntime PRIVATE ..)
target_link_libraries(properdesktop-appruntime PRIVATE properdesktop-core-common ProperDesktop::ToolkitBase PkgConfig::Systemd)

add_executable(runtime-dbus-test runtime_dbus_test.cpp)
target_link_libraries(runtime-dbus-test PRIVATE ProperDesktop::ToolkitBase GTest::gtest_main)
target_compile_definitions(runtime-dbus-test PRIVATE APPRUNTIME_BINARY="$<TARGET_FILE:properdesktop-appruntime>")
add_dependencies(runtime-dbus-test properdesktop-appruntime)
find_program(DBUS_RUN_SESSION_EXECUTABLE dbus-run-session REQUIRED)
add_test(NAME runtime-dbus COMMAND ${DBUS_RUN_SESSION_EXECUTABLE} -- $<TARGET_FILE:runtime-dbus-test>)
