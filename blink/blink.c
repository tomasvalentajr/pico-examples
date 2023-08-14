/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    printf("LED_ON Function running");
    const uint LED1A_PIN = 26;
    const uint LED2A_PIN = 28;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);
    printf("Def LED ON");

    gpio_init(LED1A_PIN);
    gpio_init(LED2A_PIN);
    gpio_set_dir(LED1A_PIN, GPIO_OUT);
    gpio_set_dir(LED2A_PIN, GPIO_OUT);
    
    gpio_put(LED1A_PIN, 1);
    gpio_put(LED2A_PIN, 1);  
    printf("All LEDs ON");  

}
