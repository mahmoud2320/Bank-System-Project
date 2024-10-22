#pragma once
#include <iostream>

using namespace std;
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include "clsScreen.h"
class clsCurrencyCalculatorScreen: protected clsScreen
{
	private:
		static	clsCurrency _GetCurrency()
	{

		string S = clsInputValidate::ReadString();

		

		while (!clsCurrency::isExist(S)) 
		{
			cout << "Currency Is not Found Enter  Code Again : " << endl;
	
			S = clsInputValidate::ReadString();

		}
	
		return clsCurrency::FindByCode(S);
	
	}

	static void _printCurrencyCard(clsCurrency C, string Title)
	{
	
		cout << "Currency Card" << endl;

		cout << "________________________" << Title << "_____________________" << endl;
		cout << "Country Name : " << C.CountryName() << endl;
		cout << "Curr Code : " << C.CurrencyCode() << endl;
		cout << "Cuur Name : " <<C.CurrencyName() << endl;
		cout << "Rate : " << C.Rate() << endl;
		cout << "___________________________________________________" << endl;
	}



	static	void _CuurencyCalculation(clsCurrency Curr1, clsCurrency Curr2, float Amount)
	{
		_printCurrencyCard(Curr1, "From");

		Amount= Curr1.CovertFromCurrenncyToUSD(Amount);

		cout << "From" << Curr1.CurrencyCode() << "TO USD : " << Amount << endl;

		
		if (Curr2.CurrencyCode() == "USD") 
		{
		
			return;
		
		
		}
	
		_printCurrencyCard(Curr2, "To");

		Amount = Curr1.CovertFromCurrenncyToAnthorCurrency(Curr2,Amount);
	
		cout << "From " << Curr1.CurrencyCode() << "TO "<<Curr2.CurrencyCode()<<" : " << Amount<<endl;
	}

public:
	static void CurrencyCalculatorScrren() 
	{

		char Ans='Y';
		clsCurrency Cu1, Cu2;
		float Amount;
		while (toupper(Ans) == 'Y') 
		{
			_ShowScreen("CURRENCY CALCULATOR");

			cout << "enter Curreny to change From" << endl;
			Cu1 = _GetCurrency();
		
			cout << "enter Curreny to change To" << endl;
			Cu2 = _GetCurrency();

			cout << "Enter Amount you Want to Change" << endl;

			

			cin >> Amount;
		
			_CuurencyCalculation(Cu1,Cu2, Amount);
		
			cout << "Do You Want To Do  Another Calculation y/n" << endl;
		
			cin >> Ans;

			system("cls");
		}
	
	
	}


};

