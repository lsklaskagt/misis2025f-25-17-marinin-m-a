add_executable(rational_test rational_test.cpp)

target_include_directories(rational_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../prj.thirdparty)
target_link_libraries(rational_test rational)
