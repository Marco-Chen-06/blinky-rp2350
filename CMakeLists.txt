cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(blink_uart_project C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# make a executable for blink.c
add_executable(blink
    blink.c
)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 1)

target_link_libraries(blink
    pico_stdlib    
    hardware_uart    
    hardware_gpio    
    hardware_timer    
)

# also generate uf2 and elf and bin and map files
pico_add_extra_outputs(blink)

#add debug info
target_compile_definitions(blink PRIVATE PICO_DEBUG=1)
target_compile_options(blink PRIVATE -g3)

# cmake debugging text
message(STATUS "Building blink project for ${PICO_PLATFORM} (${PICO_BOARD})")