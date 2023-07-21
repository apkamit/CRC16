#include "general_crc16.h"

uint8_t input_str[] = "General_CRC"; //You can send any ascii string


int main(){
    uint16_t corr_crc = cal_crc(input_str, sizeof(input_str) - 1);
}