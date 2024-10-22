#pragma once
#include<iostream>
using namespace std;
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsbanckClient.h"
class clsfindClient:public clsScreen
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
	static void FindClient() 
	{

		if (!clsScreen::CheckAccess(clsUser::Permissoins::pFindClient))
		{

			return;

		}
	
		_ShowScreen("Find Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsbanckClient::isExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsbanckClient Client1 = clsbanckClient::FindClient(AccountNumber);

		if (!Client1._ISEmpty())
		{
			cout << " Client Found SuccessFully" << endl;

			_Print(Client1);

		}
		else
			cout << "Client Was not Found" << endl;
	
	
	}

};

