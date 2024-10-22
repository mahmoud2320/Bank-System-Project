#pragma once

#include <iostream>

using namespace std;
#include "clsScreen.h"

#include "clsInputValidate.h"

#include"clsbanckClient.h"
class clsUpdateClient:protected clsScreen
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
public:
    static void ShowUpdateClientScreen()
    {

        if (!clsScreen::CheckAccess(clsUser::Permissoins::pUpdateClient))
        {

            return;

        }

        _ShowScreen("Update Client Screen");

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

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            _readInfo(Client1);

            clsbanckClient::eSave SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsbanckClient::eSave::eSuccess:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _Print(Client1);
                break;
            }
            case clsbanckClient::eSave::eFailEmptyObl:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

