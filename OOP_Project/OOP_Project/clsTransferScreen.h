#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsbanckClient.h"

using namespace std;


class clsTransferScreen:protected clsScreen
{
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
	static void TransFerScreen() 
	{
	
		_ShowScreen(" Transfer Screen");

		string AccountNumber = "",AccountNumber2;

		cout << "\nPlease Enter client Account Number to TransFer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsbanckClient::isExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsbanckClient Client1 = clsbanckClient::FindClient(AccountNumber);

		_Print(Client1);

		

		cout << "\nPlease Enter client Account Number to Transfer to: ";
		AccountNumber2 = clsInputValidate::ReadString();

		while (!clsbanckClient::isExist(AccountNumber2))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber2= clsInputValidate::ReadString();
		}

		clsbanckClient Client2 = clsbanckClient::FindClient(AccountNumber2);

		_Print(Client2);


		cout << "\n\nenter your Amount for Transfer : " << endl;

		int Amount = clsInputValidate::ReadDblNumber();

		cout << "Are you Sure to do this Transaction y/n" << endl;


		string chosse = clsInputValidate::ReadString();

		

		if (toupper(chosse[0]) == 'Y')
		{

			if (Client1.Transfer(Client2,Amount))
			{
				cout << " TransFer Done Successfully\n\n" << endl;

				cout << "*************************************************\n\n" << endl;

				_Print(Client1);

				cout << "*************************************************\n\n" << endl;

				_Print(Client2);

				cout << "*************************************************\n\n" << endl;
			}
			else
			{
				cout << "your Amount is : " << Amount << endl;
				cout << "your AccountBalncen is : " << Client1.AccountBalnce << endl;
				cout << "you cant Transfer: " << endl;

			}


		}

	}
};

