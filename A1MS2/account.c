// #############################################################################################
//  Assignment: 1 
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
#include "commonHelpers.h"

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
	person->birth_year=getIntFromRange(min_birth_year, max_birth_year);
	printf("Enter the household Income: $");
	person->income=getPositiveDouble();
	printf("Enter the country (%d chars max.): ", max_name);
	getCString(person->res_country, min_name, max_name);
}