/*
	==================================================
	Assignment #1
	Milestone  #3
	==================================================
	Name   : Abhi Bansal
	ID     : 122132210
	Email  : abansal19@myseneca.ca
	Section: NLL
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "commonHelpers.h"
#include <time.h>
#include <string.h>
#include "account.h"
#include "accountTicketingUI.h"

//account.c
#define min_birth_year 1911
#define max_birth_year 2003
#define min_pass 8
#define max_pass 8
#define min_age 18
#define max_age 110
#define max_user_name 10
#define min_user_name 0
#define max_name 30
#define min_name 0


int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing 
	}
}

int getInteger()
{
	char nl = 'x';
	int value;
	while (nl != '\n')
	{
		scanf("%d%c", &value, &nl);
		if (nl != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	}
	return value;
}

int getPositiveInteger()
{
	int value = getInteger();
	while (value <= 0)
	{
		printf("ERROR: Value must be a positive integer greater than zero: ");
		value = getInteger();
	}
	return value;
}

double getDouble()
{
	char nl = 'x';
	double value;
	while (nl != '\n')
	{
		scanf("%lf%c", &value, &nl);
		if (nl != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	}
	return value;
}

double getPositiveDouble()
{
	double value = getDouble();
	while (value <= 0)
	{
		printf("ERROR: Value must be a positive double floating-point number: ");
		value = getDouble();
	}
	return value;
}

int getIntFromRange(int min, int max)
{
	int value = getInteger();
	while (value<min || value>max)
	{
		printf("ERROR: Value must be between %d and %d inclusive: ", min, max);
		value = getInteger();
	}
	return value;
}

char getCharOption(char* val_char)
{
	char c;
	int done = 0;
	char myLine[100];
	while (!done)
	{
		int len;
		scanf("%[^\n]%*c", myLine);
		len = length(myLine);
		c = myLine[0];
		if (len != 1 || strchr(val_char, c) == NULL)
		{
			printf("ERROR: Character must be one of [%s]: ", val_char);
		}
		else
		{
			done = 1;
		}
	}
	return c;
}

int length(char* s)
{
	int i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return i;
}


void copy(char* to, char* fm)
{
	int i = 0;
	while (fm[i] != 0)
	{
		to[i] = fm[i];
		i++;
	}
	to[i] = 0;
	return;
}

/*void getCString(char* s, int minLen, int maxLen)
{
	char myLine[100];
	int len;
	scanf("%[^\n]%*c", myLine);
	len = length(myLine);
	while (len<minLen || len>maxLen)
	{
		if (len > maxLen)
			printf("ERROR: String length must be no more than %d chars: ", maxLen);
		else if (minLen == maxLen)
			printf("ERROR: String length must be exactly %d chars: ", minLen);
		else
			printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
		scanf("%[^\n]%*c", myLine);

		len = length(myLine);
	}
	copy(s, myLine);
	return;
}*/

//account.c

char getCString(char* str, int minLen, int maxLen)
{

	while (1)
	{
		char my_Line[100];
		int arr = 0;
		int x = 0;
		scanf("%[^\n]%*c", my_Line);
		while (1)
		{
			if (my_Line[arr] == '\0')
			{
				break;
			}
			arr++;
		}
		if (arr <= maxLen && arr >= minLen)
		{
			while (1)
			{
				if (my_Line[x] == '\0')break;
				str[x] = my_Line[x];
				x++;
			}
			str[x] = '\0';
			return *str;
		}
		if (maxLen != minLen)
		{
			if (arr > maxLen)
			{
				printf("ERROR: String length must be no more than %d chars: ", maxLen);
			}
			else if (arr < minLen)
			{
				printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
			}
			else
			{
				while (1)
				{
					if (my_Line[x] == '\0')break;
					str[x] = my_Line[x];
					x++;
				}
				str[x] = '\0';
				return *str;
			}
		}
		else
		{
			if (arr != maxLen)
			{
				printf("ERROR: String length must be exactly %d chars: ", maxLen);
			}
			else
			{
				while (1)
				{
					if (my_Line[x] == '\0')break;
					str[x] = my_Line[x];
					x++;
				}
				str[x] = '\0';
				return *str;
			}
		}

	}

}



void getAccount(struct Account* account)
{
	printf("Enter the account number: ");
	account->account_number = getPositiveInteger();
	printf("Enter the account type (A=Agent | C=Customer): ");
	account->account_type = getCharOption("AC");
}

void getUserLogin(struct UserLogin* login)
{
	printf("Enter user login (%d chars max): ", max_user_name);
	getCString(login->login_name, min_user_name, max_user_name);
	printf("Enter the password (must be %d chars in length): ", min_pass);
	getCString(login->user_password, min_pass, max_pass);
}

void getPerson(struct Person* person)
{
	printf("Enter the person's full name (%d chars max): ", max_name);
	getCString(person->person_name, min_name, max_name);
	printf("Enter birth year (current age must be between %d and %d): ", min_age, max_age);
	person->birth_year = getIntFromRange(min_birth_year, max_birth_year);
	printf("Enter the household Income: $");
	person->income = getPositiveDouble();
	printf("Enter the country (%d chars max.): ", max_name);
	getCString(person->res_country, min_name, max_name);
}