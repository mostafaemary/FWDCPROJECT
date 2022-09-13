/*
 * main.c
 *
 *  Created on: Sep 11, 2022
 *      Author: MOSTAFA EMARY
 */
#include"app.h"
void appStart(void)
{
	char choice[4] = { '\0' };
	ST_cardData_t customer_card = { 0 };
	ST_terminalData_t term_data = { 0 };
	ST_transaction trans_data = { 0 };
	setMaxAmount((ST_terminalData_t*)&term_data);
	PRINT("1- MAKE TRANSACTION\n");
	PRINT("2- CHECK IF VALIDATE\n");
	PRINT("3- CHECK IF EXPIERED\n");
	PRINT("4- EXIT\n");
	PRINT("ENTER YOUR CHOICE: ");
	gets(choice);
	if (choice);
	while (atoi(choice) != 4)
	{
		if (atoi(choice) == 1)
		{
			if (getCardHolderName(&customer_card) != WRONG_NAME && getCardPAN(&customer_card) != WRONG_PAN && getCardExpiryDate(&customer_card) != WRONG_EXP_DATE)
			{
				PRINT("%s\n", (char*)&(customer_card.cardHolderName));
				PRINT("%s\n", (char*)&(customer_card.primaryAccountNumber));
				PRINT("%s\n", (char*)&(customer_card.cardExpirationDate));
				getTransactionDate(&term_data);
				if (isCardExpired(customer_card, term_data) == TERMINAL_OK)
				{
					if (getTransactionAmount(&term_data) == TERMINAL_OK)
					{
							trans_data.cardHolderData = customer_card;
							trans_data.terminalData = term_data;
							saveTransaction(&trans_data);
					}
				}
			}
		}
		if (atoi(choice) == 2)
		{
			if (getCardPAN(&customer_card) != WRONG_PAN)
				isValidAccount(&trans_data.cardHolderData);
		}
		if (atoi(choice) == 3)
		{
			if (getCardExpiryDate(&customer_card) != WRONG_EXP_DATE)
				isCardExpired(customer_card, term_data);
		}
		PRINT("\nENTER ANOTHER CHOICE: ");
		gets(choice);
	}
	if (atoi(choice) == 4)
	{
		PRINT("\n\n========THANKS FOR TRANSACTIONS, THAT'S THE EXIT ========\n\n");
	}
}