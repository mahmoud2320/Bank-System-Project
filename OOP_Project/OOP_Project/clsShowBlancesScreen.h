#pragma once

#include<iostream>
using namespace std;

#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsbanckClient.h"
class clsShowBlancesScreen:protected clsScreen
{
private:
	static void _PrintClientLine(clsbanckClient c) 
	{

		cout << "| " << setw(15) << left << c.GetAccountNumber();
		cout << "| " << setw(20) << left << c.FullName();
		cout << "| " << setw(12) << left << c.AccountBalnce;
	
	}

public:
	static void PrintBalancesList()
	{
		clsScreen::_ShowScreen("Blances Screen");

		vector <clsbanckClient> cl = clsbanckClient::GetClientsData();

		cout << "\n\t\t\t\t\tClient List (" << cl.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (cl.size() == 0)
		{
			cout << "Clients list is Empty" << endl;


		}
		else
		{
			for (clsbanckClient& C : cl)
			{
				_PrintClientLine(C);

				cout << endl;
			}


		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		cout << "Total Balnces : " << clsbanckClient::sumBlances() << endl;

	}


};

