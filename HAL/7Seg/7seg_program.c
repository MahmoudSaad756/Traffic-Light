
#include "../../services/BIT_MATH.h"
#include "../../services/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "7Seg_interface.h"
#include "7Seg_private.h"


u8 SSD_Binarys[10]={0b00111111,0b00110000,0b01101101,0b01111001,0b01110010,0b01011011,0b01011111,0b00110011,0b01111111,0b01111011};


void Seg7_voidSendNumber( Seg7_Type Copy_Seg7TypeConfig , u8 Copy_u8Number)
{
	if ( Copy_Seg7TypeConfig.SSD_Type == Common_Cathode )
	{
		DIO_voidSetPortValue(Copy_Seg7TypeConfig.DataPort , SSD_Binarys[Copy_u8Number]);
	}
	else if( Copy_Seg7TypeConfig.SSD_Type == Common_Anode )
	{
		DIO_voidSetPortValue(Copy_Seg7TypeConfig.DataPort , ~(SSD_Binarys[Copy_u8Number]));
	}
	
}

void Seg7_voidEnable    ( Seg7_Type Copy_Seg7TypeConfig)
{
	if ( Copy_Seg7TypeConfig.SSD_Type == Common_Cathode )
	{
		DIO_voidSetPinValue( Copy_Seg7TypeConfig.EnablePort ,Copy_Seg7TypeConfig.EnablePin , Low);
	}
	else if( Copy_Seg7TypeConfig.SSD_Type == Common_Anode )
	{
		DIO_voidSetPinValue( Copy_Seg7TypeConfig.EnablePort ,Copy_Seg7TypeConfig.EnablePin , High);
	}
	
}

void Seg7_voidDisable   ( Seg7_Type Copy_Seg7TypeConfig)
{
	if ( Copy_Seg7TypeConfig.SSD_Type == Common_Cathode )
	{
		DIO_voidSetPinValue( Copy_Seg7TypeConfig.EnablePort ,Copy_Seg7TypeConfig.EnablePin , High);
	}
	else if( Copy_Seg7TypeConfig.SSD_Type == Common_Anode )
	{
		DIO_voidSetPinValue( Copy_Seg7TypeConfig.EnablePort ,Copy_Seg7TypeConfig.EnablePin , Low);
	}
	
}
