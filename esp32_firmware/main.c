#include <stdio.h>
#include "driver/gpio.h"
#include "driver/uart.h"

#define LED_PIN GPIO_NUM_2

void app_main() {
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    uart_driver_install(UART_NUM_0, 1024, 0, 0, NULL, 0);

    uint8_t data[128];
    while (1) {
        int len = uart_read_bytes(UART_NUM_0, data, sizeof(data), 100 / portTICK_PERIOD_MS);
        if (len > 0) {
            if (data[0] == 'f') {
                gpio_set_level(LED_PIN, 1);  // turn LED on
            } else if (data[0] == 's') {
                gpio_set_level(LED_PIN, 0);  // turn LED off
            }
        }
    }
}

