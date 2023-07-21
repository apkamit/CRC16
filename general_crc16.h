/*
 * general_crc16.h
 *
 *  Created on: 21-Jul-2023
 *      Author: Amit
 */

#ifndef INC_GENERAL_CRC16_H_
#define INC_GENERAL_CRC16_H_

#include <stdint.h>

/*Choose whichever CRC16, you want to use just uncomment one of the define*/
//#define			USE_AUG_CCITT
//#define			USE_BUYPASS
//#define			USE_CCITT_FALSE
//#define			USE_CDMA2000
//#define			USE_DDS_110
//#define			USE_DECT_X
//#define			USE_T10_DIF
//#define			USE_TELEDISK
#define			USE_XMODEM

#if defined(USE_AUG_CCITT)
	#define CRC_INITIAL_VALUE		(0x1D0F)
	#define CRC_POLYNOMIAL			(0x1021)
#elif defined(USE_BUYPASS)
	#define CRC_INITIAL_VALUE		(0x0000)
	#define CRC_POLYNOMIAL			(0x8005)
#elif defined(USE_CCITT_FALSE)
	#define CRC_INITIAL_VALUE		(0xFFFF)
	#define CRC_POLYNOMIAL			(0x1021)
#elif defined(USE_CDMA2000)
	#define CRC_INITIAL_VALUE		(0xFFFF)
	#define CRC_POLYNOMIAL			(0xC867)
#elif defined(USE_DDS_110)
	#define CRC_INITIAL_VALUE		(0x800D)
	#define CRC_POLYNOMIAL			(0x8005)
#elif defined(USE_DECT_X)
	#define CRC_INITIAL_VALUE		(0x0000)
	#define CRC_POLYNOMIAL			(0x0589)
#elif defined(USE_T10_DIF)
	#define CRC_INITIAL_VALUE		(0x0000)
	#define CRC_POLYNOMIAL			(0x8BB7)
#elif defined(USE_TELEDISK)
	#define CRC_INITIAL_VALUE		(0x0000)
	#define CRC_POLYNOMIAL			(0xA097)
#elif defined(USE_XMODEM)
	#define CRC_INITIAL_VALUE		(0x0000)
	#define CRC_POLYNOMIAL			(0x1021)
#endif
uint16_t cal_crc(uint8_t *str, uint8_t sz);
uint16_t crc_update(uint16_t crc, uint8_t data);

#endif /* INC_GENERAL_CRC16_H_ */
