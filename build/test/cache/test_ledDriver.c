#include "ledDriver.h"
#include "unity.h"


uint16_t address;



void setUp(){



}

void tearDown(){

 address=0;



}



void testDriverCreateDebeApagarTodosLosLeds(){



 address=0xFFFF;

 ledDriver_create(&address);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (((void *)0)), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (((void *)0)), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_HEX16);



}
