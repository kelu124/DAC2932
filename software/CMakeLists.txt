cmake_minimum_required(VERSION 3.13)

include(${CMAKE_CURRENT_LIST_DIR}/../pico-sdk/pico_sdk_init.cmake)

project(idac_vdac)

pico_sdk_init()

add_executable(idac_vdac)

pico_generate_pio_header(idac_vdac ${CMAKE_CURRENT_LIST_DIR}/idac/idac.pio)

target_sources(idac_vdac PRIVATE ${CMAKE_CURRENT_LIST_DIR}/main.c ${CMAKE_CURRENT_LIST_DIR}/vdac/vdac.c ${CMAKE_CURRENT_LIST_DIR}/idac/idac.c)

target_link_libraries(idac_vdac PRIVATE pico_stdlib hardware_pio hardware_dma hardware_clocks hardware_gpio pico_multicore)
pico_add_extra_outputs(idac_vdac)

pico_enable_stdio_usb(idac_vdac 1)
pico_enable_stdio_uart(idac_vdac 0)