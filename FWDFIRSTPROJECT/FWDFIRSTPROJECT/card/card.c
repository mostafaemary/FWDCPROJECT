/*
 * card.c
 *
 *  Created on: Sep 11, 2022
 *      Author: MOSTAFA
 */


#include "card.h"
char temp[25];
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	PRINT("enter cardholder name: ");
	gets(temp);

	if (temp == NULL || strlen(temp) < 20 || strlen(temp) > 24)
	{
		PRINT("wrong name try again\n");
		cardData->cardHolderName[0] = '\0';
		return WRONG_NAME;
	}
	else
	{
		strcpy((char*)&cardData->cardHolderName, temp);
		return OK;
	}

}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	PRINT("enter card expiry date as \"MM/YY\": ");
	gets(temp);

	if (temp == NULL || strlen(temp) != 5 || atoi(temp) > 12)
	{
		PRINT("wrong expiration date try again\n");
		cardData->cardExpirationDate[0] = '\0';
		return WRONG_EXP_DATE;
	}
	else
	{
		strcpy((char*)(&cardData->cardExpirationDate), temp);
		return OK;
	}
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	PRINT("enter card PAN: ");
	gets(temp);

	if (temp == NULL || strlen(temp) < 16 || strlen(temp) > 19)
	{
		cardData->primaryAccountNumber[0] = '\0';
		PRINT("wrong primary Account Number try again\n");
		return WRONG_PAN;
	}
	else
	{
		strcpy((char*)&cardData->primaryAccountNumber, temp);
		return OK;
	}
}