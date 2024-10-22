#pragma once

#include <iostream>

using namespace std;

#include"clsScreen.h"

#include"clsInputValidate.h"

#include"clsDepistScreen.h"

#include "clsWithdrawScreen.h"

#include "clsShowBlancesScreen.h"

#include"clsTransferScreen.h"

#include"clsTransferlogScreen.h"

class clsTransactionsScreen:protected clsScreen
{

	enum _eTarnsctios 
	{
	eDepoist=1,
	eWithDraw = 2,
	eShowBalancesScreen=3,
	eTransFerScreen=4,
	TransFerScreenLog=5,
	GoBacktoMainMenu=6
	};
	static void _ShowDepoistMenu() 
	{
		clsDepistScreen::Depoist();
	    //cout << "Depoist Will be here soon" << endl;
	}
	static void _ShowWithDrawMenu()
	{
		clsWithdrawScreen::WithDraw();
		//cout << " WithDraw Will be here soon" << endl;
	}
	static void _ShowShowBalancesScreen()
	{
		clsShowBlancesScreen::PrintBalancesList();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::TransFerScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferlogScreen::PrintTransferLoglistList();
	}
	static void _GoBacktoMainMenu()
	{
		
	}
	static 	int _GetChoice()
	{
		int choice =clsInputValidate::ReadNumberBetween(1,6);
	
		return choice;
	
	}

	static void _TransActionsChosse(_eTarnsctios op)
	{
		switch (op) 
		{
		case _eTarnsctios::eDepoist: 
		{
			system("cls");
			_ShowDepoistMenu();
			cout << "press any key to go back TransActios Menu" << endl;
			system("pause>0");
		
			ShowTransActiosMenu();
			break;
		}
		case _eTarnsctios::eWithDraw: 
		{
			system("cls");
			_ShowWithDrawMenu();
			cout << "press any key to go back TransActios Menu" << endl;
			system("pause>0");
			ShowTransActiosMenu();
			break;

		}
		case _eTarnsctios::eShowBalancesScreen:
		{

			system("cls");
			_ShowShowBalancesScreen();
			cout << "press any key to go back TransActios Menu" << endl;
			system("pause>0");
			
			ShowTransActiosMenu();
				break;
		
		}
		case _eTarnsctios::eTransFerScreen:
		{

			system("cls");
			_ShowTransferScreen();
			cout << "press any key to go back TransActios Menu" << endl;
			system("pause>0");

			ShowTransActiosMenu();
			break;

		}
		case _eTarnsctios::TransFerScreenLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			cout << "press any key to go back TransActios Menu" << endl;
			system("pause>0");

			ShowTransActiosMenu();
			break;
		}
		case _eTarnsctios::GoBacktoMainMenu:
		{
		
		}
		}

	}
	

public:
    static void ShowTransActiosMenu() 
	{

		if (!clsScreen::CheckAccess(clsUser::Permissoins::pTransActios))
		{

			return;

		}

		system("cls");

		_ShowScreen("Transactios Screen");

		cout << "[1] DEPOIST" << endl;
		cout << "[2] WITHDRAW" << endl;
		cout << "[3] CLIENT BALANCES TABLE " << endl;
		cout << "[4] Transfer   " << endl;
		cout << "[5] TransferLogScreen" << endl;
		cout << "[6] MAIN MENU" << endl;

		cout << "______________________________________________________________" << endl;
		cout << "enter transaction from [1] to [6]" << endl;



		_TransActionsChosse((_eTarnsctios)_GetChoice());


	}



};

