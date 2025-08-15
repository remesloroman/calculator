file(GLOB_RECURSE PARSER_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

add_library(parser STATIC ${PARSER_FILES})

target_include_directories(parser
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)
