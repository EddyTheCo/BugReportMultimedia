cmake_minimum_required(VERSION 3.11)


project(BugReport  LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
include(GNUInstallDirs)


set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
        STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
        "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Qml )

qt_standard_project_setup()

qt_add_executable(example main.cpp)
qt6_add_qml_module(example
    URI  Example
    VERSION 1.0
    QML_FILES
    qml/window.qml
    RESOURCE_PREFIX
    "/esterVtech.com/imports"
)

add_subdirectory(multilib)

if(ANDROID)

    set_property(TARGET example APPEND PROPERTY QT_ANDROID_MIN_SDK_VERSION 30)
    set_property(TARGET example APPEND PROPERTY QT_ANDROID_TARGET_SDK_VERSION 34)
    set_property(TARGET example APPEND PROPERTY QT_ANDROID_SDK_BUILD_TOOLS_REVISION 34.0.0)

endif(ANDROID)


target_link_libraries(example PRIVATE Qt::Core Qt::Gui Qt::Qml Qt::Quick MultiLib)

set_target_properties(example PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

install(TARGETS example
    BUNDLE  DESTINATION .
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(QTDEPLOY)
    qt_generate_deploy_qml_app_script(
        TARGET example
        OUTPUT_SCRIPT deploy_script
    )
install(SCRIPT ${deploy_script})
endif(QTDEPLOY)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CPACK_PACKAGE_CONTACT "estervtech")
    set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-v${SEMVER}-${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}")
    include(CPack)
endif()
