cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(libs/pico-sdk/pico_sdk_init.cmake)

# Add Unity test framework
add_library(unity STATIC libs/Unity/src/unity.c)
include_directories(libs/Unity/src)
# include(libs/Unity/unityConfig.cmake)

project(embedded_tdd)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(src/leddriver)
add_subdirectory(src/interrupt)