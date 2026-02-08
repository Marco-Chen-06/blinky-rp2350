#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "hardware/structs/iobank0.h"
#include "hardware/structs/sio.h"
#include "hardware/regs/io_bank0.h"
#include "hardware/structs/padsbank0.h"
#include "hardware/structs/uart.h"
const uint LED_PIN = 25;

int main() {
    uart_inst_t awawd;


    bi_decl(bi_program_description("BLINK TEST BINARY"));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));
    
    // because i missed one line on the datasheet so i got stuck debugging a blinking led forever
    hw_clear_bits(&pads_bank0_hw->io[LED_PIN], PADS_BANK0_GPIO0_OD_BITS);

    io_bank0_hw->io[LED_PIN].ctrl = GPIO_FUNC_SIO;
    sio_hw->gpio_oe_set = (1u << LED_PIN);
    
    while (1) {
        sio_hw->gpio_set = (1u << LED_PIN);
        sleep_ms(250);
        sio_hw->gpio_clr = (1u << LED_PIN);
        sleep_ms(250);
    }
}