#pragma once

#include <iostream>

using namespace std;

#include"clsScreen.h"
#include"clsCurrency.h"
#include "clsInputValidate.h"
class clsUpdateRateScreen:protected clsScreen
{

private:
	static	void _Print(clsCurrency Curr)
	{
		cout << "Country Name : " << Curr.CountryName() << endl;

		cout << "Currency Code : " << Curr.CurrencyCode() << endl;

		cout << "Currency Name: " << Curr.CurrencyName() << endl;

		cout << "Rate : " << Curr.Rate() << endl;
	}

	static void _ShowResult(clsCurrency Curr)
	{
		if (!Curr.isEmpty())
		{
			cout << "Currency is Found :-)" << endl;
			_Print(Curr);



		}
		else
		{
			cout << "Currency is Not Found :-(" << endl;


		}





	}



public:
	static void UpdateCurrencyRate()
	{
		clsCurrency Curr;

		string Code="";

		float Rate;

		char S;

		_ShowScreen("Update Currency Rate Screen");

			cout << "Enter Code : " << endl;

			Code = clsInputValidate::ReadString();

			while (!Curr.isExist(Code))
			{
				cout << " Curr is Not Found enter Data Again" << endl;
				Code = clsInputValidate::ReadString();
			
			}
			Curr = clsCurrency::FindByCode(Code);
			_ShowResult(Curr);
	
			

			cout << "Do you sure to update Currency rate y/n" << endl;

			cin >> S;

			if (toupper(S) == 'Y') 
			{
				cout << "Enter Rate : " << endl;
				Rate = clsInputValidate::ReadDblNumber();
				Curr.UpdateRate(Rate);
				_ShowResult(Curr);
			}

	}

};

