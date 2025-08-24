find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE TEXT_EDIT_QML_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")
    
list(TRANSFORM TEXT_EDIT_QML_FILES 
             REPLACE "^${CMAKE_CURRENT_SOURCE_DIR}/" "")

qt_add_library(text_edit SHARED "")
qt_add_qml_module(text_edit
                URI gui.control.text_edit
                QML_FILES
                "${TEXT_EDIT_QML_FILES}"
                PLUGIN_TARGET text_edit)


