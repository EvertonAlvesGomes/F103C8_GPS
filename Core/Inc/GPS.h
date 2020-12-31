/*
 * GPS.h
 *
 *  Created on: 30 de dez de 2020
 *      Author: Everton A. Gomes
 */

#ifndef INC_GPS_H_
#define INC_GPS_H_

#include "stm32f1xx_hal.h"
#include <string.h>

//Constants


//Variables
typedef struct {
	float lat;	//latitude
	float longt;	//longitude
	char lat_orient;	//latitude orientation (N or S)
	char longt_orient;	//longitude orientation (E or W)
	float speed;	//speed over ground
	float date;		//today's date
	float time;		//current time (hh:mm:ss)
} GpsInfo;

extern UART_HandleTypeDef huart1;
unsigned char gpsTerminator[1];	//marks start ('$')or end of message ('\n')
unsigned char gpsMessageType[5];	//Array for identify message type
unsigned char gpsMessageValue[100];	//Array for store message data
unsigned char gpsMessageHeader[6];	//array for header message ("$GP<type>")


//Function headers
_Bool GPS_start_of_message();
_Bool GPS_is_GLL_message(unsigned char *data);
_Bool GPS_is_RMC_message(unsigned char *data);
_Bool GPS_is_GSA_message(unsigned char *data);

#endif /* INC_GPS_H_ */
