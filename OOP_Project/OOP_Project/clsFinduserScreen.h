#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsFinduserScreen:protected clsScreen
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

	static  void FindUser()
	{
		clsScreen::_ShowScreen("Find User Screen");

		string Accountnumber = "";


		cout << "enter your UserName Number" << endl;

		Accountnumber = clsInputValidate::ReadString();



		while (!clsUser::IsExist(Accountnumber))
		{
			cout << "THis Account is Not Exist" << endl;

			Accountnumber = clsInputValidate::ReadString();
		}

		clsUser client = clsUser::Find(Accountnumber);


		if (!client.isEmpty()) 
		{
			cout << " User Found" << endl; 
			_print(client);
		}
		else
		{
			cout << " User Not Found" << endl;

		}


	}



};

