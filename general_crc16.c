/*
 * general_crc16.c
 *
 *  Created on: 21-Jul-2023
 *      Author: Amit
 */


#include "general_crc16.h"

uint16_t crc_update(uint16_t crc, uint8_t data){
	uint16_t ret = ((crc >> 8) ^ (data & 0x00FF)) << 8;
	for(uint8_t i = 0; i < 8; i++){
		if(ret & 0x8000){
			ret = (ret << 1) ^ CRC_POLYNOMIAL;
		}
		else ret <<= 1;
	}
	return (crc << 8) ^ ret;
}

uint16_t cal_crc(uint8_t *str, uint8_t sz){
	uint16_t crc = CRC_INITIAL_VALUE;
	while(sz--){
		crc = crc_update(crc, (uint16_t)*str++);
	}
	return crc;
}
