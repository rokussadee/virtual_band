# /plugin/CMakeLists.txt file
cmake_minimum_required(VERSION 3.27)

project(VirtualBandPlugin VERSION 0.0.1)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/VirtualBand")

juce_add_plugin(${PROJECT_NAME}
    COMPANY_NAME C.Rottus Kft.
    VERSION 0.0.1
    IS_SYNTH FALSE
    IS_MIDI_EFFECT TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    PLUGIN_MANUFACTURER_CODE Crot
    PLUGIN_CODE Vbnd
    FORMATS VST3 AU
    PRODUCT_NAME "Virtual Band"
)

target_sources(${PROJECT_NAME}
    PRIVATE
        source/PluginEditor.cpp
        source/PluginProcessor.cpp
        source/MidiProcessor.cpp
        source/MidiQueue.cpp
        source/MidiListModel.cpp
        source/MidiTable.cpp
        ${INCLUDE_DIR}/PluginEditor.h
        ${INCLUDE_DIR}/PluginProcessor.h
        ${INCLUDE_DIR}/MidiProcessor.h
        ${INCLUDE_DIR}/MidiQueue.h
        ${INCLUDE_DIR}/MidiListModel.h
        ${INCLUDE_DIR}/MidiTable.h
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        JUCE_USE_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

juce_generate_juce_header(${PROJECT_NAME})  # Important to generate JuceHeader.h

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /Wall /WX)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE
            SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

juce_enable_copy_plugin_step(${PROJECT_NAME})