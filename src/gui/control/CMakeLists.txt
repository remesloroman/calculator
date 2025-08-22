add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/button/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/text_edit/")

add_library(control INTERFACE)
target_link_libraries(control INTERFACE text_edit button)