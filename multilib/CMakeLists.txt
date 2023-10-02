
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Qml  Multimedia)

qt_standard_project_setup()

qt6_add_qml_module(MultiLib
    URI  multilib
    VERSION 1.0
    SOURCES
    src/CPPCamera.cpp include/CPPCamera.hpp
    QML_FILES
    qml/QMLCamera.qml
    RESOURCE_PREFIX
    "/esterVtech.com/imports"
)
target_compile_definitions(MultiLib PRIVATE WINDOWS_MULTI)
target_include_directories(MultiLib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(MultiLib PUBLIC Qt::Core Qt::Gui Qt::Quick Qt6::Multimedia)

