#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/gpio.h"
#include "hardware/structs/sio.h"
#include "hardware/structs/iobank0.h"
#include "hardware/regs/io_bank0.h"
#include "hardware/structs/padsbank0.h"
const uint LED_PIN = 25;

int main() {
    gpio_init(LED_PIN); // gpio_init is worth looking into

    // sio discussed in rp2350 datasheet page 36
    sio_hw->gpio_oe_set = (1u << LED_PIN);
    while (1) {
        sio_hw->gpio_set = (1u << LED_PIN);
        sleep_ms(250);
        sio_hw->gpio_clr = (1u << LED_PIN);
        sleep_ms(250);
    }
}