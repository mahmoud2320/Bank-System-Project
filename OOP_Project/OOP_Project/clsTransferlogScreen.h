#pragma once
#include <iostream>

using namespace std;

#include"clsScreen.h"

#include"clsbanckClient.h"



class clsTransferlogScreen:protected clsScreen
{

	static void _PrintTransferine(clsbanckClient::stTranserRecord t)
	{

		cout << "| " << setw(25) << left << t.DateAndTime;
		cout << "| " << setw(10) << left << t.AccountNumber_1;
		cout << "| " << setw(10) << left << t.AccountNumber_2;
		cout << "| " << setw(12) << left << t.Amount;
		cout << "| " << setw(10) << left << t.AccountBalance_1;
		cout << "| " << setw(10) << left << t.AccountBalance_2;
		cout << "| " << setw(10) << left << t.User;
	}

public:
	static void PrintTransferLoglistList()
	{
		clsScreen::_ShowScreen("Transfer Log Screen");

		vector <clsbanckClient::stTranserRecord> TransferRecords = clsbanckClient::GetTranfersList();

		cout << "\n\t\t\t\t\tClient List (" << TransferRecords.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << setw(25) << left << "Date And Time";
		cout << "| " << setw(10) << left << "S.Acct";
		cout << "| " << setw(10) << left << " D.Acct";
		cout << "| " << setw(12) << left << " Amount";
		cout << "| " << setw(10) << left << "S.Bala";
		cout << "| " << setw(10) << left << "B.Bala";
		cout << "| " << setw(10) << left << "User";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (TransferRecords.size() == 0)
		{
			cout << "Transfer list is Empty" << endl;


		}
		else
		{
			for (clsbanckClient::stTranserRecord C : TransferRecords)
			{
				_PrintTransferine(C);

				cout << endl;
			}


		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}







};

