
#include <stdint.h>

void ledDriver_create(uint16_t*);
void ledDriver_led_on(uint16_t*, uint8_t);
void ledDriver_all_leds_on(uint16_t*);
void ledDriver_all_leds_off(uint16_t*);
uint8_t ledDriver_get_led_state(uint16_t, uint8_t);