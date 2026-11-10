cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE testfiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(test_axpy ${testfiles})

target_include_directories(test_axpy PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${CLBLAST_INCLUDE_DIR}
    ${OPENCL_INCLUDE_DIR}
)

target_link_libraries(test_axpy PRIVATE
    rindowclblast.vclib
    ${OPENCL_LIBRARY}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_axpy)

add_test(
    NAME test_axpy
    COMMAND test_axpy
    CONFIGURATIONS Release
)
