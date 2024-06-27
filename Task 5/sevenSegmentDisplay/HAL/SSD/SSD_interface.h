/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : SSD
 *
 */

#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define COMMON_ANODE 0x00
#define COMMON_CATHOD 0x01

typedef struct
{
    u8 Type;
    u8 DataPort;
    u8 EnablePort;
    u8 EnablePin;
} SSD_Type;

void SSD_voidInitDataPort(SSD_Type Copy_structConfig);
void SSD_voidEnable(SSD_Type Copy_structConfig);
void SSD_voidInitDisable(SSD_Type Copy_structConfig);
void SSD_voidSendNumber(SSD_Type Copy_structConfig, u8 Copy_u8Number);

#endif /* _SSD_INTERFACE_H_ */