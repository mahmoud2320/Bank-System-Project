#pragma once

#include<iostream>
using namespace std;
#include"clsScreen.h"
#include"clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:
	static	void _Print(clsCurrency Curr)
	{
		cout << "Country Name : " <<Curr.CountryName()<< endl;

		cout << "Currency Code : " << Curr.CurrencyCode()<< endl;

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
	static void FindCurrency()
	{
		clsCurrency Curr;

		string Code,Countryname;

		int Ans;

		_ShowScreen("Find Currency Screen");

		cout << "Find By : [1] Code or [2] CountryName" << endl;
		
		cin >> Ans;

		if (Ans==1) 
		{
		
			cout << "Enter Code" << endl;

			getline(cin>>ws,Code);

			Curr= clsCurrency::FindByCode(Code);

			_ShowResult(Curr);
		}
		if (Ans == 2)
		{
			cout << "Enter Country Name" << endl;

			getline(cin>>ws, Countryname);

			Curr = clsCurrency::findByCountry(Countryname);

			_ShowResult(Curr);

		}


		
	}

};

