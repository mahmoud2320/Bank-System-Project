#pragma once
#include<iostream>
using namespace std;
#include "clsUser.h"
#include "Global1.h"

#include<iomanip>
class clsScreen
{

	private:

		static void _PrintDateAndUserName() 
		{
			clsDate Date;

			cout << "User : " << CureentUser.UserName << endl;

			cout << "Date : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
		}

protected:

	


	

	static void _ShowScreen(string  Title,string Title2="")
	{

		_PrintDateAndUserName();

		cout <<"______________________________________________________________" << "\n" << endl;

		cout << "\t\t\t" << Title <<   endl;
		if (Title2 != "")
			cout<< "\t\t\t" << Title2 << endl;
		cout << "\n"  << "______________________________________________________________" << endl;
	}


	static bool CheckAccess(clsUser::Permissoins per)
	{
		if (!CureentUser.CheckPermission(per))
		{
			cout << "______________________________________________________________" << "\n" << endl;

			cout << "\t\t\t" << " ACCESS  DENID" << endl;

			cout << "\n" << "______________________________________________________________" << endl;
			return false;
		}
		else
			true;

	}

};

