
#include "ledDriver.h"

void ledDriver_create(uint16_t* address) {
    *address = 0;
}

void ledDriver_led_on(uint16_t* address, uint8_t led) {
    *address |= (1 << (led - 1)); // Los leds estan numerados de 1 a 16
}

void ledDriver_led_off(uint16_t* address, uint8_t led) {
    *address &= ~(1 << (led - 1));
}

void ledDriver_all_leds_on(uint16_t* address) {
    *address = 0xFFFF;
}

void ledDriver_all_leds_off(uint16_t* address) {
    *address = 0;   
}

uint8_t ledDriver_get_led_state(uint16_t address, uint8_t led) {
    uint8_t state = address & (1 << (led - 1));
    return state;
}
