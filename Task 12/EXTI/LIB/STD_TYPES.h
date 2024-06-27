/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_TYPES.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : LIB
 *
 *
 */

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#define NULL 0x00

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;

#define IDLE 0
#define BUSY 1

#define OK 0
#define NOK 1
#define NULL_POINTER 2
#define BUSY_STATE 3
#define TIMEOUT_STATE 4

#endif /* _STD_TYPES_H_ */
