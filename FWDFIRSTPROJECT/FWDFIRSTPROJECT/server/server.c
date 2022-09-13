/*
 * server.c
 *
 *  Created on: Sep 11, 2022
 *      Author: MOSTAFA
 */
#include "server.h"
int i = 255;
ST_accountsDB_t Accounts_D_B[255] = { {3000,"523146478295730256"},{4000,"57646478295730256"},{3040,"634146478295730256"} };
ST_transaction Transaction_D_B[255] = { 0 };//filling with 0s
EN_transState_t recieveTransactionData(ST_transaction* transData)
{
	if (isValidAccount(&transData->cardHolderData) == SERVER_OK) 
	{
		if (isBelowMaxAmount(&transData->terminalData) == TERMINAL_OK)
		{

			if (isAmountAvailable(&transData->terminalData) == SERVER_OK)
			{
				Accounts_D_B[255 - i].balance -= transData->terminalData.transAmount;
				PRINT("==== Transaction APPROVED ====\n");
				PRINT("Transaction AMOUNT is: %f\n", transData->terminalData.transAmount);
				PRINT("NEW BALANCE IS: %f\n", Accounts_D_B[255 - i].balance);
				return APPROVED;
			}
			else
			{
				PRINT("===SORRY Amount Isn't Availablein your balance===\n");
				return DECLINED_INSUFFECIENT_FUND;
			}
		}
		else
		{
			PRINT("===SORRY you havn't this balance===\n");
			return DECLINED_INSUFFECIENT_FUND;
		}
	}
	else
	{
		PRINT("==== THIS CARD IS STOLEN YOU SHOULDN'T USE IT ====\n");
		return DECLINED_STOLEN_CARD;
	}
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	while (i)
	{
		if (strcmp((char*)&cardData->primaryAccountNumber, (char*)Accounts_D_B[255 - i].primaryAccountNumber) == 0)
		{
			PRINT("==== the PAN IS VALIDATE ==== \n");
			return SERVER_OK;
		}
		i--;
	}
	if (i <= 0)
		return ACCOUNT_NOT_FOUND;
	else
		return SERVER_OK;
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	if (termData->transAmount > Accounts_D_B[255-i].balance)
		return LOW_BALANCE;
	else
		return SERVER_OK;
}
EN_serverError_t saveTransaction(ST_transaction* transData)
{
	static int num = 0;
	if (recieveTransactionData(transData) == APPROVED)
	{
		num++;
		Transaction_D_B[num].cardHolderData = transData->cardHolderData;
		PRINT("\n===SAVING TRANSACTION SUCCESSEED===\n");
		PRINT("number of RIGHT transactions is: %d\n", num);
		
		return SERVER_OK;
	}
	else
	{
		PRINT("\n===SAVING TRANSACTION FAILED===\n");
		PRINT("number of RIGHT transactions is: %d\n", num);
		return SAVING_FAILED;
	}
}



//EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction* transData)
//{
//
//}
