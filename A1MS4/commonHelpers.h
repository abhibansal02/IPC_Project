/*
	==================================================
	Assignment #2
	Milestone  #2
	==================================================
	Name   : Abhi Bansal
	ID     : 122132210
	Email  : abansal19@myseneca.ca
	Section: NLL
*/

#ifndef COMMON_HELPERS_H
#define COMMON_HELPERS_H
#include <stdio.h>
int currentYear(void);
void clearStandardInputBuffer(void);
int getInteger();
int getPositiveInteger();
double getDouble();
double getPositiveDouble();
int getIntFromRange(int min, int max);
char getCharOption(char* val_char);
int length(char* s);
char getCString(char* str, int minLen, int maxLen);

#endif