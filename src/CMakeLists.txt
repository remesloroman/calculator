add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core/")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gui/")

add_executable(claculator main.cpp)
target_link_libraries(claculator PRIVATE core)
# target_link_libraries(calculator PRIVATE gui)

