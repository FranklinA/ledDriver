#include "unity.h"
#include "ledDriver.h"

uint16_t address;

void setUp(){

}
void tearDown(){
//address=0;

}
/*El Test para que los LEDs esten inicializados correctamente*/
void testDriver_LedsOffAfterCreate(){

	uint16_t virtualLeds=0xFFFF;//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear

	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}
/*El Test para que el LED 1 este encendido 0x0001 (Req8)
 * es decir virtualLed a 1. Recordando el Req 2 y
 * Test2->Un led puede ser encendido individualmente y
 * Test3->Un led puede ser apagado individualmente*/
void testDriver_TurnOnledUno(){

	uint16_t virtualLeds=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
    LedDriver_TurnOn(1);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);

}
/*El Test para que el LED 1 este encendido 0x0001 (Req8)
 * es decir virtualLed a 1. Recordando el Req 2 y
 * Test2->Un led puede ser encendido individualmente y
 * Test3->Un led puede ser apagado individualmente*/
void testDriver_TurnOffledUno(){

	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
    LedDriver_TurnOn(1);//Req 7->"1" Encendido/ "0" Apagado
    LedDriver_TurnOff(1);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);

}
/*El Test para que el LED 1 este encendido 0x0001 (Req8)
 * es decir virtualLed a 1. Recordando el Req 2 y
 * Test2->Un led puede ser encendido individualmente y
 * Test3->Un led puede ser apagado individualmente
 * Test4->Multiples leds pueden ser encendidos/apagados*/
void testDriver_TurnOnMultiplesLeds(){

	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
    LedDriver_TurnOn(9);//Req 7->"1" Encendido/ "0" Apagado
    LedDriver_TurnOn(8);
    //LedDriver_TurnOff(1);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(0x180,virtualLeds);

}
void testDriver_TurnOffAnyLed(){

	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
    LedDriver_TurnOn(9);//Req 7->"1" Encendido/ "0" Apagado
    LedDriver_TurnOn(8);
    LedDriver_TurnOff(8);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(0x100,virtualLeds);

}
void testDriver_AllOnLed(){
	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
		LedDriver_Create(&virtualLeds);//funcion que quiero testear
	 //   LedDriver_TurnOn(9);//Req 7->"1" Encendido/ "0" Apagado
	//    LedDriver_TurnOn(8);
	//    LedDriver_TurnOff(8);//Req 7->"1" Encendido/ "0" Apagado
	//	TEST_ASSERT_EQUAL_HEX16(0x100,virtualLeds);

	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}
void testDriver_LedsStatus(){
	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
		LedDriver_Create(&virtualLeds);//funcion que quiero testear
	 //   LedDriver_TurnOn(9);//Req 7->"1" Encendido/ "0" Apagado
	    //LedDriver_TurnOn(8);
	//    LedDriver_TurnOff(8);//Req 7->"1" Encendido/ "0" Apagado
	//	TEST_ASSERT_EQUAL_HEX16(0x100,virtualLeds);

	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);

}
void testDriver_LedsLimits(){
	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
		LedDriver_Create(&virtualLeds);//funcion que quiero testear
	 //   LedDriver_TurnOn(9);//Req 7->"1" Encendido/ "0" Apagado
	    //LedDriver_TurnOn(8);
	//    LedDriver_TurnOff(8);//Req 7->"1" Encendido/ "0" Apagado
	//	TEST_ASSERT_EQUAL_HEX16(0x100,virtualLeds);

	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);

}
void testDriver_LedsDataVeri(){
	uint16_t virtualLeds;//=0xFFFF;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
		LedDriver_Create(&virtualLeds);//funcion que quiero testear
	 //   LedDriver_TurnOn(9);//Req 7->"1" Encendido/ "0" Apagado
	    //LedDriver_TurnOn(8);
	//    LedDriver_TurnOff(8);//Req 7->"1" Encendido/ "0" Apagado
	//	TEST_ASSERT_EQUAL_HEX16(0x100,virtualLeds);

	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);

}
