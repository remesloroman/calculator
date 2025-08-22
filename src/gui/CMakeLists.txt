add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/control/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/launcher/")

add_library(gui INTERFACE)
target_link_libraries(gui INTERFACE control launcher)


