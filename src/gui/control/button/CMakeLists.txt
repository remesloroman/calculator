find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE BUTTON_QML_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")
    
list(TRANSFORM BUTTON_QML_FILES 
             REPLACE "^${CMAKE_CURRENT_SOURCE_DIR}/" "")

add_library(button SHARED "")
qt_add_qml_module(button
                URI button
                QML_FILES
                "${BUTTON_QML_FILES}")


