/*
	==================================================
	Assignment #1
	Milestone  #1
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
			printf("ERROR: Value must be an integer: ");
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
		printf("ERROR: Value must be a integer between %d and %d: ", min, max);
		value = getInteger();
	}
	return value;
}

char getCharOption(char *val_char)
{
	char c;
	int done=0;
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
	int i=0;
	while (s[i] != 0)
	{
		i++;
	}
	return i;
}

void copy(char* to, char* fm)
{
	int i=0;
	while (fm[i] != 0)
	{
		to[i]=fm[i];
		i++;
	}
	to[i]=0;
	return;
}

void getCString(char* s, int minLen, int maxLen)
{
char myLine[100];
int len;
scanf("%[^\n]%*c", myLine);
len=length(myLine);
while (len<minLen || len>maxLen)
{
	if(len>maxLen)
		printf("ERROR: String length must be no more than %d chars: ", maxLen);
		else if(minLen==maxLen)
		printf("ERROR: String length must be exactly %d chars: ", minLen);
		else
		printf("ERROR: String length must be between %d and %d chars: ", minLen, maxLen);
		scanf("%[^\n]%*c", myLine);
		len=length(myLine);
}
copy(s, myLine);
return;
}