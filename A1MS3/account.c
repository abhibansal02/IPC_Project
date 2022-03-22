#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "account.h"
#include "accountTicketingUI.h"

void getAccountData(struct Account *a)
{
printf("Account Data: New Record\n");
printf("----------------------------------------\n");
getAccount(a);
printf("\n");
return;
}

void getUserLoginData(struct UserLogin *u)
{
printf("User Login Data Input\n");
printf("----------------------------------------\n");
getUserLogin(u);
printf("\n");
return;
}

void getPersonData(struct Person *p)
{
printf("Person Data Input\n");
printf("----------------------------------------\n");
getPerson(p);
printf("\n");
return;
}