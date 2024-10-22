#pragma once
#include<iostream>
using namespace std;

#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsbanckClient.h"
class clsWithdrawScreen:protected clsScreen
{
private:

	static	void _Print(clsbanckClient client)
	{
		cout << "First Name : " << client.FirstName << endl;

		cout << "Last Name : " << client.LastName << endl;

		cout << "Full Name : " << client.FullName() << endl;

		cout << "Email : " << client.Email << endl;

		cout << "Phone : " << client.Phone << endl;

		cout << "AccountNumber : " << client.GetAccountNumber() << endl;

		cout << "PINCode : " << client.PinCode << endl;

		cout << "AccountBalance : " << client.AccountBalnce << endl;
	}


public:

	static void WithDraw()
	{

		_ShowScreen(" Withdraw Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsbanckClient::isExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsbanckClient Client1 = clsbanckClient::FindClient(AccountNumber);

		_Print(Client1);




		cout << "enter your Amount for Withdraw : " << endl;

		int Amount = clsInputValidate::ReadDblNumber();





		cout << "Are you Sure to do this Transaction y/n" << endl;


		string chosse = clsInputValidate::ReadString();


		if (toupper(chosse[0]) == 'Y')
		{
			
			if (Client1.WithDraw(Amount)) 
			{
				cout << "your AccountBalncen is  After With Draw: " << Client1.AccountBalnce << endl;
			}
			else
			{
				cout << "your Amount is : " << Amount << endl;
				cout << "your AccountBalncen is : " << Client1.AccountBalnce << endl;
				cout << "you cant Withdraw: " << endl;

			}

		}


	}






};

