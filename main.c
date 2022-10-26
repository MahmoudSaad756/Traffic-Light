/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Mahmoud
 */



#include <util/delay.h>

#include "services/STD_TYPES.h"
#include "services/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LED/LED_interface.h"

#include "HAL/7Seg/7Seg_interface.h"

int main ()
{
	Seg7_Type S1 = { Common_Cathode , DIO_PortA , DIO_PortB , 0};
	Seg7_Type S2 = { Common_Cathode , DIO_PortA , DIO_PortB , 1};

	LED_Type L1 = {DIO_PortC , 0 ,Active_High};
	LED_Type L2 = {DIO_PortC , 1 ,Active_High};
	LED_Type L3 = {DIO_PortC , 2 ,Active_High};

	LED_voidInit(L1);
	LED_voidInit(L2);
	LED_voidInit(L3);

	enum state{GREEN , RED , YELLOW};

	enum state Cur_state= GREEN;
	LED_voidon(L3); LED_voidoff(L1); LED_voidoff(L2);

	DIO_voidSetPortDirection( DIO_PortA , 255 );
	DIO_voidSetPinDirection(DIO_PortB , 0 ,High);  // for Enable 7 Seg
	DIO_voidSetPinDirection(DIO_PortB , 1 ,High);  // for Enable 7 Seg

	u16 var=0,outputNumber=0;
	u8 Limit=60;
	while (1)
	{
		if(var >5)
		{
			var=0;
			outputNumber++;
		}

		if(outputNumber >= Limit)
		{
			outputNumber=0;
			if(Cur_state == GREEN )
			{
				LED_voidon(L1); LED_voidoff(L2); LED_voidoff(L3);
				Cur_state = RED;
				Limit = 60;
			}
			else if(Cur_state == RED)
			{
				LED_voidon(L2); LED_voidoff(L1); LED_voidoff(L3);
				Cur_state = YELLOW;
				Limit = 10;

			}
			else if(Cur_state == YELLOW)
			{
				LED_voidon(L3); LED_voidoff(L1); LED_voidoff(L2);
				Cur_state = GREEN;
				Limit = 60;

			}
		}

			Seg7_voidDisable(S2);
			Seg7_voidEnable(S1);
			Seg7_voidSendNumber(S1 , outputNumber%10);


			_delay_ms(10);

			Seg7_voidDisable(S1);
			Seg7_voidEnable(S2);
			Seg7_voidSendNumber(S2 ,outputNumber/10);

			_delay_ms(10);

			var++;

	}

	return 0;
}
