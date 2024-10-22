#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteUserScreen: protected clsScreen
{
	static void _print(clsUser& C)
	{
		cout << "First Name : " << C.FirstName << endl;

		cout << "Last Name : " << C.LastName << endl;

		cout << "Full Name : " << C.FullName() << endl;

		cout << "Email : " << C.Email << endl;

		cout << "Phone : " << C.Phone << endl;

		cout << " UserName : " << C.UserName << endl;

		cout << " Password : " << C.Password << endl;

		cout << "Permisson : " << C.Permissons << endl;
	}

public:
	static void DeleteUser()
	{

		clsScreen::_ShowScreen(" Delete User Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter UserName: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsUser::IsExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsUser Client1 = clsUser::Find(AccountNumber);
		_print(Client1);

		cout << "\nAre you sure you want to delete this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{


			if (Client1.Delete())
			{
				cout << "User Deleted Successfully "<<endl;

				_print(Client1);
			}
			else
			{
				cout << " User Was not Deleted " << endl;
			}
		}
	}

};

