
#include "unity.h"
#include "ledDriver.h"

uint16_t address;

/**
** Esta funcion se ejecuta antes de cada test.
*/
void setUp() {

}

/**
** Esta funcion se ejecuta luego de cada test.
*/
void tearDown() {
    address = 0;
}

void test_DriverCreateDebeApagarTodosLosLeds() {
    address = 0xFFFF;
    ledDriver_create(&address);
    TEST_ASSERT_EQUAL_HEX16(0, address);
}

void test_DriverLedOnDebeEncenderLedSeleccionado() {
    ledDriver_led_on(&address, 5);
    TEST_ASSERT_EQUAL_HEX16(0x0010, address);
}

void test_DiverLedOffDebeApagarLedSeleccionado() {
    address = 0xFFFF;
    ledDriver_led_off(&address, 5);
    TEST_ASSERT_EQUAL_HEX16(0xFFEF, address);
}

void test_DriverDebeApagarYEncenderVariosLeds() {
    address = 0;
    ledDriver_led_on(&address, 5);
    TEST_ASSERT_EQUAL_HEX16(0x0010, address);
    ledDriver_led_on(&address, 16);
    TEST_ASSERT_EQUAL_HEX16(0x8010, address);
    ledDriver_led_on(&address, 1);
    TEST_ASSERT_EQUAL_HEX16(0x8011, address);

    ledDriver_led_off(&address, 5);
    TEST_ASSERT_EQUAL_HEX16(0x8001, address);
    ledDriver_led_off(&address, 1);
    TEST_ASSERT_EQUAL_HEX16(0x8000, address);
    ledDriver_led_off(&address, 16);
    TEST_ASSERT_EQUAL_HEX16(0, address);
}

void test_DriverAllLedsOnDebeEncenderTodosLosLeds() {
    address = 0;
    ledDriver_all_leds_on(&address);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, address);
}

void test_DriverAllLedsOffDebeApagarTodosLosLeds() {
    address = 0xFFFF;
    ledDriver_all_leds_off(&address);
    TEST_ASSERT_EQUAL_HEX16(0, address);
}

void test_DriverGetLedStateDebeDarEstadoLed() {
    address = 1;
    uint8_t led = ledDriver_get_led_state(address, 1);
    TEST_ASSERT_EQUAL_HEX16(1, led);

    led = ledDriver_get_led_state(address, 16);
    TEST_ASSERT_EQUAL_HEX16(0, led);
}

void test_DriverDebeIgnorarLedsNoDefinidos() {
    address = 0;
    ledDriver_led_on(&address, 17);
    TEST_ASSERT_EQUAL_HEX16(0, address);
    ledDriver_led_on(&address, 0);
    TEST_ASSERT_EQUAL_HEX16(0, address);
}

void test_DiverDebeFuncionarConValoresLimite() {
    address = 0;
    ledDriver_led_on(&address, 1);
    TEST_ASSERT_EQUAL_HEX16(1, address);
    ledDriver_led_off(&address, 1);
    TEST_ASSERT_EQUAL_HEX16(0, address);
    ledDriver_led_on(&address, 16);
    TEST_ASSERT_EQUAL_HEX16(0x8000, address);
    ledDriver_led_off(&address, 16);
    TEST_ASSERT_EQUAL_HEX16(0, address);
}
