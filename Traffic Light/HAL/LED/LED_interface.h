

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


#define Active_Low  0
#define Active_High 1


typedef struct {
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_Type;

void LED_voidInit( LED_Type Copy_LEDTypeConfig);
void LED_voidoff ( LED_Type Copy_LEDTypeConfig);
void LED_voidon  ( LED_Type Copy_LEDTypeConfig);

#endif
