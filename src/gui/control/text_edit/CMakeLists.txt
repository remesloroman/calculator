find_package(Qt6 REQUIRED COMPONENTS Quick Core)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE TEXT_EDIT_SRC_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

file(GLOB_RECURSE TEXT_EDIT_QML_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")

list(TRANSFORM TEXT_EDIT_QML_FILES
                REPLACE "^${CMAKE_CURRENT_SOURCE_DIR}/" "")

qt_add_library(text_edit SHARED "${TEXT_EDIT_SRC_FILES}")
target_include_directories(text_edit PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

qt_add_qml_module(text_edit
                URI text_edit
                QML_FILES
                "${TEXT_EDIT_QML_FILES}")

target_link_libraries(text_edit PUBLIC Qt6::Quick Qt6::Core)