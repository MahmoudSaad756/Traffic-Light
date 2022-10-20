

#ifndef SEG7_INTERFACE_H
#define SEG7_INTERFACE_H


#define Common_Cathode  0
#define Common_Anode 1


typedef struct {
	u8 SSD_Type;
	u8 DataPort;
	u8 EnablePort;
	u8 EnablePin;

}Seg7_Type;

void Seg7_voidSendNumber( Seg7_Type Copy_Seg7TypeConfig ,  u8 Copy_u8Number);
void Seg7_voidEnable    ( Seg7_Type Copy_Seg7TypeConfig);
void Seg7_voidDisable   ( Seg7_Type Copy_Seg7TypeConfig);

#endif
