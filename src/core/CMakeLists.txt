add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/calculator_backend/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/math_expr/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/parser/")

add_library(core INTERFACE)
target_link_libraries(core INTERFACE calculator_backend parser math_expr)