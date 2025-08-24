file(GLOB_RECURSE MATH_EXPR_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

add_library(math_expr SHARED ${MATH_EXPR_FILES})
target_link_libraries(math_expr PUBLIC alias)

target_include_directories(math_expr
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)
