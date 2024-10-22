#pragma once

#include<iostream>
using namespace std;
#include "clsInputValidate.h"
#include "clsShowClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsfindClient.h"
#include"clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include"clsRegisterScreen.h"
#include"clsCurrencyMainScreen.h"
class clsMainScreen :protected clsScreen
{
	 enum eOperation
	{
		ShowClientslist = 1,
		UpdateClients = 2,
		AddnewClients = 3,
		DeleteClients = 4,
		Transactions = 5,
		MangeUser = 6,
		FindClient = 7,
		Reigesterlist = 8,
		CurrencyEchange = 9,
		Exit = 10
	};
	static void _ShowClientScreen()
	{
		clsShowClientScreen::PrintClientlist();

	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClient::ShowUpdateClientScreen();	
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static	void _ShowDeleteClientScreen()
	{
		clsDeleteClient::DeleteClient();
	}
	static void _ShowFindClientScreen()
	{

		clsfindClient::FindClient();
		
	}
	static void _ShowTansactiosScreen()
	{

		clsTransactionsScreen::ShowTransActiosMenu();
		
	}
	static 	void _ShowManageUsersScreen()
	{
		
		clsManageUsers::ShowUsersMenu();
		
	}

	static 	void _RegisterScreen() 
	{
	
		clsRegisterScreen::RegisterScreen();
	
	}

	static 	void _LogOut()
	{

		CureentUser = clsUser::Find("","");


	}
	static 	void _CurrencyMainScreen()
	{

		clsCurrencyMainScreen::CurrencyMenu();


	}
	

	static void _ChoosseOperation(int op)
	{
		switch (op)
		{
		case eOperation::ShowClientslist:
		{
			_ShowClientScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			break;
		}
		case eOperation::UpdateClients:
		{
			_ShowUpdateClientScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			break;
		}

		case eOperation::AddnewClients:
		{
			_ShowAddNewClientScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			break;
		}

		case eOperation::DeleteClients:
		{
			_ShowDeleteClientScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			break;
		}
		case eOperation::Transactions:
		{
			_ShowTansactiosScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			
			break;
		}
		case eOperation::MangeUser:
		{
			_ShowManageUsersScreen();

			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			break;
		}
		case eOperation::Exit:
		{
			_LogOut();
			break;
		}
		case eOperation::FindClient:
		{
			_ShowFindClientScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();
			break;
		}
		case eOperation::Reigesterlist:
		{
			_RegisterScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();

			break;
		}
		case eOperation::CurrencyEchange:
		{
			_CurrencyMainScreen();
			cout << "press any key to go back Main Menu" << endl;
			system("pause>0");
			system("cls");
			showMainMenu();

			break;
		}
		}
	}
public:
	static void showMainMenu()
	{
		int op;
		
		_ShowScreen("Main Menu");
	
		cout <<  "[1] Show Client List" << endl;
		cout <<  "[2] Update List" << endl;
		cout <<  "[3] Add New List" << endl;
		cout <<  "[4] Delete client" << endl;
		cout <<  "[5] Transactios " << endl;
		cout <<  "[6] Mange Users " << endl;
		cout <<  "[7] Find Client " << endl;
		cout <<  "[8] REGISTER LIST " << endl;
		cout << "[9] Currency Exchange " << endl;
		cout <<  "[10] LOG OUT" << endl;
		
		cout << "______________________________________________________________" << endl;
		cout <<"enter Operation from [1] to [10]" << endl;

		op = clsInputValidate::ReadNumberBetween(1,10,"enter number Between [1]  & [10]");

		system("cls");
		_ChoosseOperation(op);
	}


};

