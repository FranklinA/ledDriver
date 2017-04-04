/*
Test 1 Todos los leds deben estar apagados después de inicializar el driver
Test 2 Un led puede ser encendido individualmente
Test 3 Un led puede ser apagado individualmente
Test 4 Múltiple leds pueden ser encendidos/apagados
Test 5 Apagar todos los leds
Test 6 Encender todos los leds
Test 7 Consulta del estado individual de un led
Test 8 Verificación de valores límites
Test 9 Verificación de valores fuera de límites
*/
#include "unity.h"
#include "ledDriver.h"

static uint16_t virtualLeds;

void setUp(){
LedDriver_Create(&virtualLeds);
}

void tearDown(){
}
void testDriver_LedsOffAfterCreate()//Test 1 Todos los leds deben estar apagados después de inicializar el driver
{
	uint16_t virtualLeds=0xFFFF;//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

void testDriver_TurnOnLedOne()//Test 2 Un led puede ser encendido individualmente
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}
void testDriver_TurnOffLedOne()//Test 3 Un led puede ser apagado individualmente
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void testDriver_TurnOnMultipleLeds()//Test 4 Multiples leds pueden ser encendidos
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

void testDriver_TurnOffMultipleLeds()//Test 4 Multiples leds pueden ser encendidos/apagados
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(9);
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLeds);
}

void testDriver_TurnOffAnyLed()//Test 4 Multiples leds pueden ser encendidos
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

void testDriver_AllOff()//Test 5_Apagar todos los leds
{
    LedDriver_TurnAllOn();
    LedDriver_TurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void testDriver_AllOn()//Test 6_Encender todos los leds
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

void testDriver_IsOn()//Test 7_Consulta Estado individual de un Led
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}

void testDriver_IsOff()//Test 7_Consulta Estado individual de un Led
{
    TEST_ASSERT_TRUE(LedDriver_IsOff(12));
    LedDriver_TurnOn(12);
    TEST_ASSERT_FALSE(LedDriver_IsOff(12));
}

void testDriver_UpperAndLowerBounds()//Test 8 verificación de valores Límites
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

void testDriver_OutOfBoundsLedsAreAlwaysOff()//Test 9 Verificación de valores fuera de Límites
{
    TEST_ASSERT_TRUE(LedDriver_IsOff(0));
    TEST_ASSERT_TRUE(LedDriver_IsOff(17));
    TEST_ASSERT_FALSE(LedDriver_IsOn(0));
    TEST_ASSERT_FALSE(LedDriver_IsOn(17));
}

void testDriver_OutOfBoundsTurnOnDoesNoHarm()//Test 9 Verificación de valores fuera de Límites
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(3141);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}






