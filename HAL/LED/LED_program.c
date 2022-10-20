
#include "../../services/BIT_MATH.h"
#include "../../services/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"

void LED_voidInit(LED_Type Copy_LEDTypeConfig)
{
	DIO_voidSetPinDirection( Copy_LEDTypeConfig.Port , Copy_LEDTypeConfig.Pin , Output );

}
void LED_voidon(LED_Type Copy_LEDTypeConfig) {

	if ( Copy_LEDTypeConfig.Active_State == Active_High)
			DIO_voidSetPinValue(Copy_LEDTypeConfig.Port , Copy_LEDTypeConfig.Pin , High );
		else
			DIO_voidSetPinValue(Copy_LEDTypeConfig.Port , Copy_LEDTypeConfig.Pin , Low);

}
void LED_voidoff(LED_Type Copy_LEDTypeConfig)
{
	if ( Copy_LEDTypeConfig.Active_State == Active_High)
		DIO_voidSetPinValue(Copy_LEDTypeConfig.Port , Copy_LEDTypeConfig.Pin , Low );
	else
		DIO_voidSetPinValue(Copy_LEDTypeConfig.Port , Copy_LEDTypeConfig.Pin , High );
}

