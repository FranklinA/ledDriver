#include "ledDriver.h"
#include "unity.h"


uint16_t address;



void setUp(){



}

void tearDown(){





}



void testDriver_LedsOffAfterCreate(){



 uint16_t virtualLeds=0xFFFF;

 LedDriver_Create(&virtualLeds);



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_HEX16);

}









void testDriver_TurnOnledUno(){



 uint16_t virtualLeds=0xFFFF;

 LedDriver_Create(&virtualLeds);

    LedDriver_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX16);



}









void testDriver_TurnOffledUno(){



 uint16_t virtualLeds;

 LedDriver_Create(&virtualLeds);

    LedDriver_TurnOn(1);

    LedDriver_TurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX16);



}











void testDriver_TurnOnMultiplesLeds(){



 uint16_t virtualLeds;

 LedDriver_Create(&virtualLeds);

    LedDriver_TurnOn(9);

    LedDriver_TurnOn(8);



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x180)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);



}

void testDriver_TurnOffAnyLed(){



 uint16_t virtualLeds;

 LedDriver_Create(&virtualLeds);

    LedDriver_TurnOn(9);

    LedDriver_TurnOn(8);

    LedDriver_TurnOff(8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x100)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);



}

void testDriver_AllOnLed(){

 uint16_t virtualLeds;

  LedDriver_Create(&virtualLeds);











 LedDriver_TurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX16);

}

void testDriver_LedsStatus(){

 uint16_t virtualLeds;

  LedDriver_Create(&virtualLeds);











 LedDriver_TurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX16);



}

void testDriver_LedsLimits(){

 uint16_t virtualLeds;

  LedDriver_Create(&virtualLeds);











 LedDriver_TurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX16);



}

void testDriver_LedsDataVeri(){

 uint16_t virtualLeds;

  LedDriver_Create(&virtualLeds);











 LedDriver_TurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_HEX16);



}
