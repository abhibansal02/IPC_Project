// #############################################################################################
//  Assignment: 2 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Abhi Bansal
//  Student ID    : 122132210
//  Student Email : abansal19@myseneca.ca
//  Course Section: NLL
// #############################################################################################

#ifndef ACCOUNT_TICKETING_UI
#define ACCOUNT_TICKETING_UI

#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"

void displayAccountDetailHeader();
void displayAccountDetailRecord(const struct Account*);
void applicationStartup(struct AccountTicketingData*);//(struct Account*, int);
int menuLogin(const struct Account* accounts, int);
void pauseExecution(void);
void menuAgent(struct AccountTicketingData*, const struct Account*);//(struct Account*, int maxElement, const struct Account*);
void displayAllAccountDetailRecords(struct Account*, int);
int findAccountIndexByAcctNum(int, const struct Account*, int, int);
int findAccountIndexByAcctNum2(int, const struct Account*, int, int);

struct AccountTicketingData
{
	struct Account* accounts; // array of accounts
	const int ACCOUNT_MAX_SIZE; // maximum elements for account array
	struct Ticket* tickets; // array of tickets 
	const int TICKET_MAX_SIZE; // maximum elements for ticket array 
};
#endif