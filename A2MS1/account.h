// #############################################################################################
//  Assignment: 2 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Abhi Bansal
//  Student ID    : 122132210
//  Student Email : abansal19@myseneca.ca
//  Course Section: NLL
// #############################################################################################
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <stdio.h>
#include "accountTicketingUI.h"
#include "commonHelpers.h"

struct Person
{
	char person_name[31];
	int birth_year;
	double income;
	char res_country[31];
};

struct UserLogin
{
	char login_name[11];
	char user_password[9];
};

struct Account
{
	int account_number;
	char account_type;
	struct Person person;
	struct UserLogin login;
};

void getAccount(struct Account* account);
void getUserLogin(struct UserLogin* login);
void getPerson(struct Person* person);

void getAccountData(struct Account*);
void getUserLoginData(struct UserLogin*);
void getPersonData(struct Person*);

void setUserLoginToSafeState(struct UserLogin*);
void updateAccount(struct Account*);

void updateUserLogin(struct UserLogin*);
void updatePerson(struct Person*);
#endif