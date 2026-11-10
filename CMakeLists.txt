cmake_minimum_required(VERSION 3.14)
#include (CMakePrintSystemInformation)
#set(CMAKE_CONFIGURATION_TYPES Debug Release)

project(rindow-clblast-vclib VERSION 0.1.0 LANGUAGES CXX C)
#set(PROJECT_VERSION_MAJOR 0)
#set(PROJECT_VERSION_MINOR 1)
#set(PROJECT_VERSION_PATCH 0)

# CLBlast and OpenCL header directories
set(CLBLAST_DIR "C:/CLBlast/CLBlast-1.7.0-windows-x64" CACHE PATH "Path to CLBlast root directory")
set(CLBLAST_INCLUDE_DIR "" CACHE PATH "Path to CLBlast include directory")

if(NOT CLBLAST_INCLUDE_DIR)
    if(EXISTS "${CLBLAST_DIR}/include")
        set(CLBLAST_INCLUDE_DIR "${CLBLAST_DIR}/include")
    else()
        set(CLBLAST_INCLUDE_DIR "${CLBLAST_DIR}")
    endif()
endif()

set(OPENCL_DIR "C:/OpenCL/OpenCL-SDK-v2026.05.29-Win-x64" CACHE PATH "Path to OpenCL SDK root directory")
set(OPENCL_INCLUDE_DIR "" CACHE PATH "Path to OpenCL include directory")

if(NOT OPENCL_INCLUDE_DIR)
    if(EXISTS "${OPENCL_DIR}/include")
        set(OPENCL_INCLUDE_DIR "${OPENCL_DIR}/include")
    else()
        set(OPENCL_INCLUDE_DIR "${OPENCL_DIR}")
    endif()
endif()

find_library(OPENCL_LIBRARY NAMES OpenCL HINTS "${OPENCL_DIR}/lib" "${OPENCL_DIR}/lib/x86_64")
if(NOT OPENCL_LIBRARY AND EXISTS "${OPENCL_DIR}/lib/OpenCL.lib")
    set(OPENCL_LIBRARY "${OPENCL_DIR}/lib/OpenCL.lib" CACHE FILEPATH "Path to OpenCL library")
endif()

message(STATUS "CLBLAST_DIR: ${CLBLAST_DIR}")
message(STATUS "CLBLAST_INCLUDE_DIR: ${CLBLAST_INCLUDE_DIR}")
message(STATUS "OPENCL_DIR: ${OPENCL_DIR}")
message(STATUS "OPENCL_INCLUDE_DIR: ${OPENCL_INCLUDE_DIR}")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Packing)

add_subdirectory(./src)

## If you want to build the Release version, type the following command
#set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
    enable_testing()
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(./tests)
endif()

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CPACK_PACKAGING_INSTALL_PREFIX: ${CPACK_PACKAGING_INSTALL_PREFIX}")
message(STATUS "CPACK_COMPONENTS_ALL: ${CPACK_COMPONENTS_ALL}")
message(STATUS "CPACK_PACKAGE_VERSION: ${CPACK_PACKAGE_VERSION}")
