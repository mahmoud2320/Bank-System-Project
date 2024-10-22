#pragma once

#include"clsScreen.h"

#include<iostream>
using namespace std;
#include"clsReigter.h"

class clsRegisterScreen:protected clsScreen
{
private:

	static void _PrintRegisterRow(clsReigter R)
	{
	

		cout << "| " << setw(30) << left << R.GetDateAndtimeName();
		cout << "| " << setw(20) << left << R.UserName;
		cout << "| " << setw(12) << left << R.Password;
		cout << "| " << setw(20) << left << R.Permissons;
	
	}
public :

	static void RegisterScreen() 
	{

		if (!clsScreen::CheckAccess(clsUser::Permissoins::pReigsterScreen))
		{

			return;

		}
		vector <clsReigter> clients = clsReigter::GetRegisterlist();
		string title = "Registers list";
		string Subtitle = "(" + to_string(clients.size()) + ")" + "User(s)";

		_ShowScreen(title, Subtitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(30) << "Date And time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(20) << "Permissons";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (clients.size() == 0)
		{
			cout << "Reigster list is Empty" << endl;


		}
		else
		{
			for (clsReigter& C : clients)
			{
				_PrintRegisterRow(C);

				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	
	
	
	
	
	}



};

