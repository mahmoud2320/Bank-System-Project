#pragma once
#include <iostream>
using namespace std;

#include "clsScreen.h"

#include "clsInputValidate.h"

#include "clsCurrencyList.h"


#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyMainScreen: protected clsScreen
{

	enum eOperation { eCurrencyList =1,eFindCurrency=2, eUpdateRate=3, eCurrencyCalculator=4,MainMenu=5};

	static void CurrencyList() 
	{
		clsCurrencyList::PrintCurrlist();
	}

	static void FindCurrency()
	{
		clsFindCurrencyScreen::FindCurrency();
	}

	static	void UpdateRate()
	{
		clsUpdateRateScreen::UpdateCurrencyRate();
	}

	static void CurrencyCalculator()
	{
		clsCurrencyCalculatorScreen::CurrencyCalculatorScrren();
	}
	

	static void _ChoosseOperation(int op)
	{
		switch (op)
		{
		case eOperation::eCurrencyList:
		{
			system("cls");
			CurrencyList();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			CurrencyMenu();
			break;
		}
		case eOperation::eFindCurrency:
		{
			system("cls");
			FindCurrency();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			CurrencyMenu();
			break;
		}

		case eOperation::eUpdateRate:
		{
			system("cls");
			UpdateRate();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			CurrencyMenu();
			break;
		}

		case eOperation::eCurrencyCalculator:
		{
			system("cls");
			CurrencyCalculator();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			CurrencyMenu();
			break;
		}
		case eOperation::MainMenu:
		{
		

		}
	
		}
	}
public:
	static void CurrencyMenu()
	{
		if (!clsScreen::CheckAccess(clsUser::Permissoins::pCurrencyExchange))
		{

			return;

		}

		int op;
		
		_ShowScreen("CURRENCY SCREEN");
		cout << "[1] CURRENCY LIST" << endl;
		cout << "[2]  FIND CURRENCY" << endl;
		cout << "[3] UPDATE RATE" << endl;
		cout << "[4] CURRENCY CALCULATOR" << endl;
		cout << "[5] MAIN MENU " << endl;
		
		cout << "______________________________________________________________" << endl;
		cout << "enter Operation from [1] to [5]" << endl;

		op = clsInputValidate::ReadNumberBetween(1, 5, "enter number Between [1]  & [5]");

		

		_ChoosseOperation(op);
	}

};

