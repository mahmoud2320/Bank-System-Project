#pragma once
#include <iostream>
using namespace std;

#include"clsScreen.h"
#include "clsCurrency.h"
class clsCurrencyList:protected clsScreen
{
	void static _PrintCurrencyRecordLine(clsCurrency Curr)
	{
		
		cout << "| " << setw(30) << left << Curr.CountryName();
		cout << "| " << setw(20) << left << Curr.CurrencyCode();
		cout << "| " << setw(40) << left << Curr.CurrencyName();
		cout << "| " << setw(20) << left << Curr.Rate();
	}
public:
	static void PrintCurrlist()
	{
		vector<clsCurrency> Currencys = clsCurrency::GetCurrencyList();
		string title = "Currency list";
		string Subtitle = "(" + to_string(Currencys.size()) + ")" + "Currency(s)";

		_ShowScreen(title, Subtitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(30) << "Contry Name";
		cout << "| " << left << setw(20) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(20) << "Rate";
		
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (Currencys.size() == 0)
		{
			cout << "Currency list is Empty" << endl;


		}
		else
		{
			for (clsCurrency& C : Currencys)
			{
				_PrintCurrencyRecordLine(C);

				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

