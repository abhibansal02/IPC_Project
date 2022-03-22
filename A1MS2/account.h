// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Abhi Bansal
//  Student ID    : 122132210
//  Student Email : abansal19@myseneca.ca
//  Course Section: NLL
// #############################################################################################

#include <stdio.h>

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
};

void getAccount(struct Account* account);
void getUserLogin(struct UserLogin* login);
void getPerson(struct Person* person);