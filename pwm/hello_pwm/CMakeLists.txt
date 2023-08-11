cmake_minimum_required(VERSION 3.12)

#include(pico_sdk_import.cmake)

#project(hello_pwm C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()


add_executable(hello_pwm
        main.c
        adc.c
        pwm.c
        fft_imp.c
        kiss_fft/kiss_fft.c
        )

target_include_directories(hello_pwm PRIVATE
        .
        kiss_fft
    )

# pull in common dependencies and additional pwm hardware support
target_link_libraries(hello_pwm stdio pico_stdlib hardware_gpio hardware_spi hardware_pwm hardware_clocks kiss_fft )



# printf only via USB
pico_enable_stdio_uart(hello_pwm 0)
pico_enable_stdio_usb(hello_pwm 1)


# create map/bin/hex file etc.
pico_add_extra_outputs(hello_pwm)

# add url via pico_set_program_url
example_auto_set_url(hello_pwm)