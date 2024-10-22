#pragma once
#include<iostream>
using namespace std;
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsbanckClient.h"
class clsAddNewClientScreen:protected clsScreen
{

	static void _readInfo(clsbanckClient& c)
	{


		cout << "Enter First name" << endl;
		c.FirstName = clsInputValidate::ReadString();
		cout << "Enter last name" << endl;
		c.LastName = clsInputValidate::ReadString();
		cout << "Enter Email name" << endl;
		c.Email = clsInputValidate::ReadString();
		cout << "Enter phone name" << endl;
		c.Phone = clsInputValidate::ReadString();
		cout << "Enter PinCode name" << endl;
		c.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance name" << endl;
		c.AccountBalnce = clsInputValidate::ReadDblNumber();

	}


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

	static void AddNewClient() 
	{

		if (!clsScreen::CheckAccess(clsUser::Permissoins::pAddNewClient))
		{

			return;

		}

		string Accountnumber = "";
	     
		_ShowScreen("Add New Client  Screen");

		cout << "enter your ID Number" << endl;

		Accountnumber = clsInputValidate::ReadString();



		while (clsbanckClient::isExist(Accountnumber))
		{
			cout << "THis Account is Already Exist" << endl;

			Accountnumber = clsInputValidate::ReadString();
		}

		clsbanckClient client = clsbanckClient::AddnewClient(Accountnumber);

		_readInfo(client);


		clsbanckClient::eSave saveresult;

		saveresult = client.Save();

		switch (saveresult)
		{
		case::clsbanckClient::eSave::eSuccess:
		{

			cout << "user Added SuccessFully" << endl;

			_Print(client);

			break;
		}
		case::clsbanckClient::eSave::eFailEmptyObl:
			cout << "\nError account was not saved because it's Empty";
			break;

		case::clsbanckClient::eSave::eFailObJisExist:
			cout << "\nError account was not saved because it's Already Exist";
			break;
		}

	
	}

};

