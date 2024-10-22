#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsUsersScreen: protected clsScreen
{


	static  void _printUserLine(clsUser User) 
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissons;
	
	}
public:
    static	void PrintUsersList() 
	{



		vector <clsUser> Users = clsUser::GetuserList();
		string Title = "USERS LIST";
		string SubTitle = "Users ("+to_string(Users.size())+ ")";


		clsScreen::_ShowScreen(Title, SubTitle);
	
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;



		if(Users.size()==0)
			cout<<"there is no Users"<<endl;
		else 
		{
			for (clsUser& User : Users)
			{
				_printUserLine(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

	}



};

