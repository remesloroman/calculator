add_executable(parser_test parser_test.cpp)
target_link_libraries(parser_test PRIVATE parser)

add_test(NAME parser_test_run COMMAND parser_test)