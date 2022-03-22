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

#define min_pass 8
#define max_pass 8
#define min_age 18
#define max_age 110
#define max_user_name 10
#define min_user_name 0
#define max_name 30
#define min_name 0

void getAccountData(struct Account* a)
{
	printf("Account Data: New Record\n");
	printf("----------------------------------------\n");
	getAccount(a);
	printf("\n");
	return;
}

void getUserLoginData(struct UserLogin* u)
{
	printf("User Login Data Input\n");
	printf("----------------------------------------\n");
	getUserLogin(u);
	//printf("\n");
	return;
}

void getPersonData(struct Person* p)
{
	printf("Person Data Input\n");
	printf("----------------------------------------\n");
	getPerson(p);
	printf("\n");
	return;
}

void setUserLoginToSafeState(struct UserLogin* userLogin)
{
	userLogin->login_name[0] = 0;
	userLogin->user_password[0] = 0;
}

void updateAccount(struct Account* accountData)
{
	int choice, min = 0, max = 3, count = 1;
	char c;
	while (count)
	{
		printf("Update Account: %05d (%s)\n", accountData->account_number, accountData->person.person_name);
		printf("----------------------------------------\n");
		printf("1) Update account type (current value: %c)\n", accountData->account_type);
		printf("2) Person\n");
		printf("3) Login\n");
		printf("0) Done\n");
		printf("Selection: ");
		choice = getIntFromRange(min, max);
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("Enter the account type (A=Agent | C=Customer): ");
			c = getCharOption("AC");
			accountData->account_type = c;
			if (c == 'A')
			{
				printf("\nAgent type accounts require a user login. Please enter this information now: \n\n");
				getUserLoginData(&accountData->login);
			}
			else
			{
				setUserLoginToSafeState(&accountData->login);
			}
			printf("\n");
			break;

		case 2:
			updatePerson(&accountData->person);
			break;

		case 3:
			if (accountData->account_type == 'C')
			{
				printf("ERROR:  Customer account types don't have user logins!\n\n");

			}
			else if (accountData->account_type == 'A')
			{
				updateUserLogin(&accountData->login);
			}
			break;

		case 0:
			count = 0;
			break;
		}
	}
	return;
}

void updateUserLogin(struct UserLogin* login)
{
	int choice, min = 0, max = 1, count = 1;
	do
	{
		printf("User Login: %s - Update Options\n", login->login_name);
		printf("----------------------------------------\n");
		printf("1) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		choice = getIntFromRange(min, max);
		printf("\n");

		switch (choice)
		{
		case 1:
			printf("Enter the password (must be %d chars in length): ", min_pass);
			getCString(login->user_password, min_pass, max_pass);
			printf("\n");
			break;

		case 0:
			count = 0;
			break;
		}
	} while (count);
	return;
}

void updatePerson(struct Person* person)
{
	int choice, min = 0, max = 3, count = 1;
	while (count)
	{
		printf("Person Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Full name (current value: %s)\n", person->person_name);
		printf("2) Household Income (current value: $%.2lf)\n", person->income);
		printf("3) Country (current value: %s)\n", person->res_country);
		printf("0) Done\n");
		printf("Selection: ");
		choice = getIntFromRange(min, max);
		printf("\n");

		switch (choice)
		{
		case 1:
			printf("Enter the person's full name (%d chars max): ", max_name);
			getCString(person->person_name, min_name, max_name);
			printf("\n");
			break;

		case 2:
			printf("Enter the household Income: $");
			person->income = getPositiveDouble();
			printf("\n");
			break;

		case 3:
			printf("Enter the country (%d chars max.): ", max_name);
			getCString(person->res_country, min_name, max_name);
			printf("\n");
			break;

		case 0:
			count = 0;
			break;

		}
	}
	return;
}