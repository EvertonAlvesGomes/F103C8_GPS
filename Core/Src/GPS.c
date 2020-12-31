/*
 * GPS.c
 *
 *  Created on: 30 de dez de 2020
 *      Author: Everton A. Gomes
 */


#include "GPS.h"


_Bool GPS_start_of_message()
{
	_Bool flag_start = 0;
	do {
		HAL_UART_Receive(&huart1, gpsTerminator, 1, HAL_MAX_DELAY);
	} while(gpsTerminator[0] != "$");
	flag_start = 1;
	return flag_start;
}

_Bool GPS_is_GLL_message(unsigned char *data)
{
	_Bool isGLL = 0;
	if(!strncmp(data, "$GPGLL", 6)) {
		isGLL = 1;
	}
	return isGLL;
}


_Bool GPS_is_RMC_message(unsigned char *data)
{
	_Bool isRMC = 0;
	if(!strncmp(data, "$GPRMC", 6)) {
		isRMC = 1;
	}
	return isRMC;
}


_Bool GPS_is_GSA_message(unsigned char *data)
{
	_Bool isGSA = 0;
	if(!strncmp(data, "$GPGSA", 6)) {
		isGSA = 1;
	}
	return isGSA;
}
