# Root directory CMakeLists.txt file
cmake_minimum_required(VERSION 3.27)

project(virtual_band)

set(CMAKE_CXX_STANDARD 23)
if (APPLE)
    # On Mac, we need to wait for a new JUCE version that fixes the compilation issue
    set(CMAKE_CXX_STANDARD 20)
endif()

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
include(cmake/cpm.cmake)

CPMAddPackage(
        NAME JUCE
        GITHUB_REPOSITORY juce-framework/juce
        GIT_TAG 7.0.12
        VERSION 7.0.12
        SOURCE_DIR ${LIB_DIR}/juce
)

CPMAddPackage(
        NAME GOOGLETEST
        GITHUB_REPOSITORY google/googletest
        VERSION 1.14.0
        SOURCE_DIR ${LIB_DIR}/googletest
        OPTIONS
            "INSTALL_GTEST_OFF"
            "gtest_force_shared_crt ON"
)

enable_testing()

if (MSVC)
    add_compile_options(/Wall /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_subdirectory(plugin)
add_subdirectory(test)
