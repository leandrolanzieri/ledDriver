
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
