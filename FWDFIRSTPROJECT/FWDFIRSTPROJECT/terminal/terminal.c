/*
 * terminal.c
 *
 *  Created on: Sep 11, 2022
 *      Author: MOSTAFA
 */
#include "terminal.h"
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
char dyn[4];
char* itola(int x)
{
	int i, index = 0;
	//char* dyn;
	//dyn = (char*)malloc(4 * sizeof(char));
	char stat[5]="0";

	while (x)
	{
		stat[++index] = '0' + x % 10;
		x /= 10;
	}
	for (i = 0; i < index; i++)
	{
		dyn[i] = stat[index - i];
	}
	dyn[i] = '\0';
	return (char*)dyn;
}
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	time_t current_time = time(NULL);
	struct tm* tm = localtime(&current_time);
	if (tm->tm_mday < 10)
	{
		termData->transactionDate[0] = '0';
		strcat((char*)&termData->transactionDate, (char*)itola(tm->tm_mday));
	}
	else
	{
		strcpy((char*)&termData->transactionDate, (char*)itola(tm->tm_mday));
	}
	strcat((char*)&termData->transactionDate, "/");
	strcat((char*)&termData->transactionDate, (char*)itola(tm->tm_mon + 1));
	if (tm->tm_mon < 9)
	{
		termData->transactionDate[3] = '0';
		strcat((char*)&termData->transactionDate, (char*)itola(tm->tm_mon + 1));
		strcat((char*)&termData->transactionDate, "/");
		termData->transactionDate[6] = '2';
		strcpy((char*)&termData->transactionDate[7], (char*)itola(tm->tm_year));
		termData->transactionDate[10] = '\0';
		termData->transactionDate[7] = '0';
	}
	else
	{
		strcat((char*)&termData->transactionDate, (char*)itola(tm->tm_mon + 1));
		strcat((char*)&termData->transactionDate, "/");
		termData->transactionDate[6] = '2';
		strcpy((char*)&termData->transactionDate[8], (char*)itola(tm->tm_year));
		termData->transactionDate[10] = '\0';
		termData->transactionDate[7] = '0';
	}
	PRINT("%s\n", (char*)&termData->transactionDate);
	return TERMINAL_OK;
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	if ((atoi((char*)&termData.transactionDate[8])) <= (atoi((char*)&cardData.cardExpirationDate[3])))
	{
		if (atoi((char*)&termData.transactionDate[3]) <= atoi((char*)cardData.cardExpirationDate))
		{
			PRINT("card isn't expired\n");
			return TERMINAL_OK;
		}
		else
		{
			PRINT("card expired\n");
			return EXPIRED_CARD;
		}
	}
	else
	{
		PRINT("card is expired\n");
		return EXPIRED_CARD;
	}
}
//EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
//{
//
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	
	PRINT("enter transaction amount: ");
	if (scanf("%f", &termData->transAmount) != 1)
	{
		PRINT("error");
	}
	 
	if (termData->transAmount <= 0)
	{
		PRINT("\n===INVALID TRANSACTION AMOUNT===\n");
		return INVALID_AMOUNT;
	}
	else
	{
		PRINT("\n===ACCEPTED TRANSACTION AMOUNT===\n");
		return TERMINAL_OK;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	//set maxTransAmount
	termData->maxTransAmount = 10000;
	if (termData->maxTransAmount <= 0)
		return INVALID_MAX_AMOUNT;
	else
		return TERMINAL_OK;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		PRINT("\n===sorry the terminal hadn't that amount===\n")
			return EXCEED_MAX_AMOUNT;
	}
	else
	{
		PRINT("Amount dosen't exceed the max amount\n")
		return TERMINAL_OK;
	}
}