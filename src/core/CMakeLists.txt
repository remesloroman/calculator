add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/math_expr/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/parser/")

add_library(core INTERFACE)
target_link_libraries(core INTERFACE parser math_expr)