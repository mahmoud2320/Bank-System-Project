#pragma once
#include <iostream>

using namespace std;

#include"clsScreen.h"

#include "clsInputValidate.h"

#include"clsbanckClient.h"
class clsDeleteClient:protected clsScreen
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
	static void DeleteClient() 
	{
		if (!clsScreen::CheckAccess(clsUser::Permissoins::pDeleteClient))
		{

			return;

		}

		_ShowScreen("Delete client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsbanckClient::isExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsbanckClient Client1 = clsbanckClient::FindClient(AccountNumber);
		_Print(Client1);

		cout << "\nAre you sure you want to delete this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{


			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";

				_Print(Client1);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}

	
	
	}


};

