#include <stdint.h>
#define TRUE 1
#define FALSE 0

void LedDriver_Create(uint16_t *);//void LedDriver_Create(uint16_t *);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_AllOn(void);
void LedDriver_TurnAllOn(void);
