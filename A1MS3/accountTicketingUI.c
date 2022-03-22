#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "account.h"
#include "accountTicketingUI.h"

void displayAccountDetailHeader()
{
printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
return;
}

void displayAccountDetailRecord(const struct Account *a)
{
int i;
char pw[9]={0};
for(i=0;i<9;i++)
if(i%2)
pw[i]='*';
else
pw[i]=a->login.user_password[i];
printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", a->account_number, a->account_type=='A'?"AGENT":"CUSTOMER", a->person.person_name, a->person.birth_year, a->person.income, a->person.res_country, a->login.login_name, pw);
return;
}