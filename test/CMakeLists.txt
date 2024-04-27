# /test/CMakeLists.txt file
cmake_minimum_required(VERSION 3.27)

project(VirtualBandTest)

enable_testing()

add_executable(${PROJECT_NAME}
    source/AudioProcessorTest.cpp
)

add_dependencies(${PROJECT_NAME} VirtualBandPlugin)

message(STATUS "JUCE_SOURCE_DIR is set to ${JUCE_SOURCE_DIR}")
message(STATUS "GOOGLETEST_SOURCE_DIR is set to ${GOOGLETEST_SOURCE_DIR}")

target_compile_definitions(${PROJECT_NAME} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED=1
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${GOOGLETEST_SOURCE_DIR}/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../plugin/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../libs/juce/modules
        ${CMAKE_BINARY_DIR}/plugin/VirtualBandPlugin_artefacts/JuceLibraryCode  # Adjusted path
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        VirtualBandPlugin
        GTest::gtest_main
)

# Enables all warnings and treats warnings as errors.
# This needs to be set up only for your projects, not 3rd party
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /Wall /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})