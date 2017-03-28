#include "ledDriver.h"
#include "unity.h"




uint16_t address;









void setUp() {



}









void tearDown() {

    address = 0;

}



void test_DriverCreateDebeApagarTodosLosLeds() {

    address = 0xFFFF;

    ledDriver_create(&address);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX16);

}
