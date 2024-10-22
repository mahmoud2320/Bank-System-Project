#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;
class AddNewUserScreen:protected clsScreen
{
private:
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

	static int _GetPermissions() 
	{
		int Per = 0;
		char Ans;

		cout << "Do You Want To Give User Full Access" << endl;

		cin >> Ans;

		if (toupper(Ans) == 'Y')
			return -1;

		cout << "Do you Want To Give Access to" << endl;

		cout << "Show client List y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pShowClientList;
		cout << "Update Client y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pUpdateClient;
		cout << "TransActios y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pTransActios;

		cout << "Delete Client y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pDeleteClient;

		cout << "Add New Client y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pAddNewClient;
		cout << "Manage Users y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pMangeUsers;
		cout << "Find Client y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pFindClient;
		cout << " Login Reigster Screen y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pReigsterScreen;

		cout << " Currency Exchange y/n : " << endl;
		cin >> Ans;
		if (toupper(Ans) == 'Y')
			Per += clsUser::pCurrencyExchange;

		return Per;

	}

	static void _GetUserInfo(clsUser &C) 
	{
		cout << "Enter First name" << endl;
		C.FirstName = clsInputValidate::ReadString();
		cout << "Enter last Name " << endl;
		C.LastName = clsInputValidate::ReadString();
		cout << "Enter Email " << endl;
		C.Email = clsInputValidate::ReadString();
		cout << "Enter phone " << endl;
		C.Phone = clsInputValidate::ReadString();
		cout << "Enter passWord " << endl;
		C.Password = clsInputValidate::ReadString();
		cout << "Enter Permissions" << endl;
		C.Permissons= _GetPermissions();
	}

public:

   static	void AddNewUser()
	{

	   clsScreen::_ShowScreen(" Add New User Screen");

		string Accountnumber = "";


		cout << "enter your UserName" << endl;

		Accountnumber = clsInputValidate::ReadString();



		while (clsUser::IsExist(Accountnumber))
		{
			cout << "THis Account is Already Exist" << endl;

			Accountnumber = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::AddNewuser(Accountnumber);

		_GetUserInfo(User);


		clsUser::eSave saveresult;

		saveresult = User.Save();

		switch (saveresult)
		{
		case::clsUser::eSave::eSuccesed:
		{

			cout << "user Added SuccessFully" << endl;

			_print(User);

			break;
		}
		case::clsUser::eSave::eEmptyObj:
			cout << "\nError account was not saved because it's Empty";
			break;

		case::clsUser::eSave::eExistObj:
			cout << "\nError account was not saved because it's Already Exist";
			break;
		}


	}

};

