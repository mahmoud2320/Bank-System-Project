#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsbanckClient.h"
#include <iomanip>
#include "clsUser.h"
using namespace std;

class clsShowClientScreen:protected clsScreen 
{
private:
	void static _PrintClientRecordLine(clsbanckClient Client)

	{
		


		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalnce;
	}
public: 
    static void PrintClientlist()
	{

		if (!clsScreen::CheckAccess(clsUser::Permissoins::pShowClientList))
		{

			return;

		}

		vector<clsbanckClient> clients = clsbanckClient::GetClientsData();
		string title = "Clients list";
		string Subtitle = "(" + to_string(clients.size()) + ")" + "Client(s)";

		_ShowScreen(title,Subtitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (clients.size() == 0)
		{
			cout << "Clients list is Empty" << endl;


		}
		else
		{
			for (clsbanckClient& C : clients)
			{
				_PrintClientRecordLine(C);

				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

