// #############################################################################################
//  Assignment: 2 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Abhi Bansal
//  Student ID    : 122132210
//  Student Email : abansal19@myseneca.ca
//  Course Section: NLL
// #############################################################################################

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

void displayAccountDetailHeader()
{
	printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
	printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
	return;
}

void displayAccountDetailRecord(const struct Account *a)
{
	int i;
	char pw[9] = { 0 };
	for (i = 0; i < 9; i++)
		if (i % 2)
			pw[i] = '*';
		else
			pw[i] = a->login.user_password[i];
	printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", a->account_number, a->account_type == 'A' ? "AGENT" : "CUSTOMER", a->person.person_name, a->person.birth_year, a->person.income, a->person.res_country, a->login.login_name, pw);
	return;
}

void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}


void applicationStartup(struct Account *accounts, int maxElement)
{
	int index_num;
	do
	{
		index_num=menuLogin(accounts, maxElement);
		if (index_num != -1)
		{
			if (accounts[index_num].account_type == 'A')
			{
				menuAgent(accounts, maxElement, &accounts[index_num]);
			}
			else if (accounts[index_num].account_type == 'C')
			{
			printf("ERROR: login failed!");
			pauseExecution();
			}
		}
	}while(index_num!=-1);
}

int menuLogin(const struct Account *accounts, int maxElement)
{
	int index_num = 1, min = 0, max = 1, choice;
	char c;
	printf("==============================================\n"
		"Account Ticketing System - Login\n"
		"==============================================\n"
		"1) Login to the system\n"
		"0) Exit application\n"
		"----------------------------------------------\n");
	printf("\n");
	printf("Selection: ");
	choice = getIntFromRange(min, max);
	printf("\n");
	if (choice == 0)
	{
		printf("Are you sure you want to exit? ([Y]es|[N]o): ");
		c = getCharOption("yYnN");
		if (c == 'y' || c == 'Y')
		{
			printf("\n==============================================\n"
				"Account Ticketing System - Terminated\n"
				"==============================================\n");
			return -1;
		}
		else if (c == 'n' || c == 'N')
		{
			printf("\n");
			return -2;
		}
	}
	else if (choice == 1)
	{
		index_num = findAccountIndexByAcctNum2(0, accounts, maxElement, 1);
		
		if (index_num != -1)
		{
			if (accounts[index_num].account_type == 'A')
			{
			printf("\n");
			}
			if (accounts[index_num].account_type == 'C')
			{
				printf("ERROR:  Login failed!\n\n");
				pauseExecution();
				return -2;
			}
			return index_num;
		}
		else
		{
			printf("ERROR:  Login failed!\n\n");
			pauseExecution();
			return -2;
		}
	}
	return -1;
}

void menuAgent(struct Account *account_Data, int maxElement, const struct Account* account_info)
{
	int min = 0, max = 4, account_num, index = 1, repeat = 1, valChar = 0;
	int limit_val = 0, prompt, i, index_num, choice;
	while (index)
	{
		printf("AGENT: %s (%d)\n", account_info->person.person_name, account_info->account_number);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf("1) Add a new account\n");
		printf("2) Modify an existing account\n");
		printf("3) Remove an account\n");
		printf("4) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");
		choice = getIntFromRange(min, max);
		printf("\n");
		if (choice == 0)
		{
			index = 0;
			repeat = 0;
			printf("### LOGGED OUT ###\n\n");
			break;
		}
		if (choice == 1)
		{
			for (i = 0; i < maxElement; i++)
			{
				if (limit_val == maxElement)
				{
					printf("ERROR: Account listing is FULL, call ITS Support!\n");
				}
				else if (account_Data[i].account_number > 0)
				{
					limit_val++;
				}
			}
			
			getAccountData(&account_Data[limit_val]);
			//getPersonData(&account_Data[limit_val].person);
			if ((account_Data[limit_val].account_type) == 'C')
			{
				getPersonData(&account_Data[limit_val].person);
				printf("*** New account added! ***\n");
			}
			else if ((account_Data[limit_val].account_type) == 'A')
			{
				getPersonData(&account_Data[limit_val].person);
				getUserLoginData(&account_Data[limit_val].login);
				printf("\n*** New account added! ***\n");
			}
			//printf("\n*** New account added! ***\n");
			printf("\n");
			pauseExecution();


		}
		if (choice == 2)
		{
			printf("Enter the account#: ");

			account_num = getPositiveInteger();
			printf("\n");
			for (i = 0; i < maxElement; i++)
			{
				if (account_num == account_Data[i].account_number)
				{
					index_num = i;
					repeat = 0;
				}
			}
			if (repeat)
			{
				prompt = 1;
				index_num = findAccountIndexByAcctNum(account_num, account_Data, maxElement, prompt);
				repeat = 0;
			}updateAccount(&account_Data[index_num]);
		}
		if (choice == 3)
		{
			repeat = 1;
			printf("Enter the account#: ");
			account_num = getPositiveInteger();
			if (account_num == account_info->account_number)
			{
				printf("\n");
				printf("ERROR: You can't remove your own account!\n\n");
				pauseExecution();
			}
			else
			{
				for (i = 0; i < maxElement; i++)
				{
					if (account_num == account_Data[i].account_number)
					{
						index_num = i;
						repeat = 0;
					}
				}
				if (repeat)
				{
					prompt = 1;
					index_num = findAccountIndexByAcctNum(account_num, account_Data, maxElement, prompt);
					repeat = 0;
				}
				displayAccountDetailHeader();
				displayAccountDetailRecord(&account_Data[index_num]);
				printf("\n");
				printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
				valChar = getCharOption("yYnN");
				printf("\n");
				if (valChar == 'Y' || valChar == 'y')
				{
					account_Data[index_num].account_number = 0;
					printf("*** Account Removed! ***\n\n");
					pauseExecution();
				}
				else
				{
					pauseExecution();
				}
			}
		}

		if (choice == 4)
		{
			displayAllAccountDetailRecords(account_Data, maxElement);
			pauseExecution();
		}
	}
	return;
}

void displayAllAccountDetailRecords(struct Account *account_Data, int maxElement)
{
	int i;
	displayAccountDetailHeader();
	for (i = 0; i < maxElement; i++)
	{
		if (account_Data[i].account_number != 0)
		{
			displayAccountDetailRecord(&account_Data[i]);
		}
	}
	printf("\n");
}

int findAccountIndexByAcctNum(int acct_num, const struct Account *account_Data, int maxElement, int prompt_user)
{
	int i, repeat = 1, num_acct, index_num = 0;
	printf("Enter the account#: ");

	num_acct = getPositiveInteger();
	if (prompt_user == 1)
	{
		for (i = 0; i < maxElement && repeat; i++)
		{
			if (num_acct == account_Data[i].account_number)
			{
				index_num = i;
				repeat = 0;
			}
			else
			{
				index_num = -1;
			}
		}
	}
	return index_num;
}

int findAccountIndexByAcctNum2(int acct_num, const struct Account* account_Data, int maxElement, int prompt_user)
{
	int i, repeat = 1, num_acct, index_num = 0;
	printf("Enter your account#: ");

	num_acct = getPositiveInteger();
	//printf("\n");
	if (prompt_user == 1)
	{
		for (i = 0; i < maxElement && repeat; i++)
		{
			if (num_acct == account_Data[i].account_number)
			{
				index_num = i;
				//printf("\n");
				repeat = 0;
			}
			else
			{
				index_num = -1;
			}
		}
	}
	return index_num;
}