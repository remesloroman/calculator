find_package(Qt6 REQUIRED COMPONENTS Quick Core)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE LAUNCHER_SRC_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
    )

file(GLOB_RECURSE LAUNCHER_QML_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")

list(TRANSFORM LAUNCHER_QML_FILES
        REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "")

message(STATUS "LAUNCHER_QML_FILES = ${LAUNCHER_QML_FILES}")

qt_add_library(launcher SHARED "${LAUNCHER_SRC_FILES}")
target_include_directories(launcher PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

qt_add_qml_module(launcher
                URI launcher
                QML_FILES
                "qml/Main.qml")

target_link_libraries(launcher PUBLIC control)
target_link_libraries(launcher PUBLIC Qt6::Quick Qt6::Core)

