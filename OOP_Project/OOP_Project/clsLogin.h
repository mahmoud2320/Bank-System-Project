#pragma once
#include <iostream>
#include <fstream>

#include "clsMainScreen.h"

class clsLogin :protected clsScreen
{
private:

	

	 static bool _Login() 
	{
		 int _NumberOfFails=0;
		string UserName,PassWord;
		bool loginFail = true;

		_ShowScreen("LOGIN SCREEN ");

		do 
		{

			cout << "enter  UserName" << endl;
			cin >> UserName;
			cout << "enter PassWord" << endl;
			cin >> PassWord;


			CureentUser = clsUser::Find(UserName, PassWord);

			loginFail= CureentUser.isEmpty();

			if (loginFail)
			{
				
				_NumberOfFails++;

				cout << "You Have " << (3 - _NumberOfFails) << " OF Trials " << endl;

				if (_NumberOfFails == 3) 
				{
					cout << "You Are Blocked you enter User Wrong 3 Times" << endl;

					return false;
				}
				else
				cout << "Wrong Data Enter Your Data Again " << endl;

			}

		} while (loginFail);
	
		CureentUser.AddRegisrerLogin();

		system("cls");

		clsMainScreen::showMainMenu();

		return true;
	}

public:

     static	bool Program() 
	{
		 bool f;

		f=_Login();
	
		

		return f;

	}


};

