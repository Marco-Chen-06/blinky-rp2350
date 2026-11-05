cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico2)

# default to debug build
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

include(pico_sdk_import.cmake)

project(blinky-rp2350-project C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# force no optimizations (must be before pico_sdk_init)
set(PICO_DEOPTIMIZED_DEBUG 1)

pico_sdk_init()

add_executable(blinky
    blinky.c
)

target_link_libraries(blinky
    pico_stdlib
    hardware_gpio
)

pico_enable_stdio_usb(blinky 0)
pico_enable_stdio_uart(blinky 1)

pico_add_extra_outputs(blinky)