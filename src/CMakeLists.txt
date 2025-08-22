add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gui/")

add_executable(calculator main.cpp)
target_link_libraries(calculator PRIVATE core gui)

