#pragma once
/*
 * card.h
 *
 *  Created on: Sep 11, 2022
 *      Author: MOSTAFA
 */
#ifndef CARD_CARD_H_
#define CARD_CARD_H_
#include"stdio.h"
#include"stdint.h"
#include"string.h"
#include "time.h"
#include "conio.h"
#include"stdlib.h"
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS_GLOBALS
#define PRINT(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}
typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;
typedef enum EN_cardError_t
{
	OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
#endif /* CARD_CARD_H_ */