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

void displayAccountDetailHeader();
void displayAccountDetailRecord(const struct Account*);
void applicationStartup(struct Account* , int);
int menuLogin(const struct Account* , int);
void pauseExecution(void);
void menuAgent(struct Account*, int maxElement, const struct Account* );
void displayAllAccountDetailRecords(struct Account*, int );
int findAccountIndexByAcctNum(int, const struct Account* , int, int);
int findAccountIndexByAcctNum2(int, const struct Account*, int, int);
#endif