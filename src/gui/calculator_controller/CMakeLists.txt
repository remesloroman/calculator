find_package(Qt6 REQUIRED COMPONENTS Quick Core)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE CALCULATOR_CONTROLLER_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

qt_add_library(calculator_controller SHARED ${CALCULATOR_CONTROLLER_FILES})

target_include_directories(calculator_controller PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

target_link_libraries(calculator_controller PUBLIC calculator_backend)
target_link_libraries(calculator_controller PUBLIC Qt6::Core Qt6::Quick)