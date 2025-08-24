file(GLOB_RECURSE ALIAS_SRC_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(alias INTERFACE "${ALIAS_SRC_FILES}")
target_include_directories(alias INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")
