file(GLOB_RECURSE CALCULATOR_BACKEND_SRC_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(calculator_backend STATIC "${CALCULATOR_BACKEND_SRC_FILES}")
target_include_directories(calculator_backend PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(calculator_backend PUBLIC parser math_expr alias)
