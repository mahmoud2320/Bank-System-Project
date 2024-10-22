#pragma once

#include <iostream>
#include "clsScreen.h"
using namespace std;
#include "clsUsersScreen.h"
#include "clsInputValidate.h"
#include "AddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include"clsUpdateuserScreen.h"
#include"clsFinduserScreen.h"

class clsManageUsers :protected clsScreen
{

private:

	enum _enUsersChoose 
	{
	enUsersList=1,
	enAddUser=2,
	enDeleteUser=3,
	enUpdateUser=4,
	enFindUser=5,
	enMainMenu=6
	};

	static	void _ShowUsers()
	{
		clsUsersScreen::PrintUsersList();
	}

	static void _AddNewUser()
	{
		AddNewUserScreen::AddNewUser();

	}

	static void _DeleteUser()
	{
	
		clsDeleteUserScreen::DeleteUser();
	
	}

	static	void _UpdateUser()
	{

		clsUpdateuserScreen::UpdateUser();

	}

	static	void _FindUser()
	{

		clsFinduserScreen::FindUser();

	}
	
	static void  _UserChoose(_enUsersChoose c)
	{
		switch (c) 
		{
		case _enUsersChoose::enUsersList:
		{
			system("cls");
			_ShowUsers();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			ShowUsersMenu();
			break;
		}
		case _enUsersChoose::enAddUser:
		{
			system("cls");
			_AddNewUser();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			ShowUsersMenu();
			break;
		
		}
		case _enUsersChoose::enDeleteUser:
		{

			system("cls");
			_DeleteUser();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			ShowUsersMenu();
			break;
		}
		case _enUsersChoose::enFindUser:
		{
			system("cls");
			_FindUser();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			ShowUsersMenu();
			break;
		}
		case _enUsersChoose::enUpdateUser:
		{
			system("cls");
			_UpdateUser();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			ShowUsersMenu();
			break;
		}
		case _enUsersChoose::enMainMenu:
		{


		}

		}
	}

	public:

		static void ShowUsersMenu() 
		{
			if (!clsScreen::CheckAccess(clsUser::Permissoins::pMangeUsers))
			{

				return;

			}

			_ShowScreen("Manange Users Screen");
			cout << "[1] Show Users Screen" << endl;
			cout << "[2]  Add New User " << endl;
			cout << "[3]  Delete User " << endl;
			cout << "[4]  Update User " << endl;
			cout << "[5]  Find User " << endl;
			cout << "[6]  Main Menu " << endl;
			cout << "______________________________________________________________" << endl;
			cout << "enter Operation from [1] to [6]" << endl;


			_UserChoose((_enUsersChoose)clsInputValidate::ReadNumberBetween(1, 6));

			

		}


};

