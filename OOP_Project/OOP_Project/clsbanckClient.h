#pragma once

#include<iostream>

#include<fstream>

using namespace std;

#include"clsperson.h"

#include"clsString.h"

#include"clsDate.h"

#include"Global1.h"

class clsbanckClient :public clsperson
{
private:
	enum eMode { emptyMode = 1, UpdateMode = 2, AddNewMode = 3 };

	eMode _Mode;

	string _AccountNumber;

	string _PINCode;

	int _AccountBalance;

	bool _Deletemark = false;

	static clsbanckClient _GetEmptyObJ()
	{
		return clsbanckClient(eMode::emptyMode, "", "", "", "", "", "", 0);
	}

	static	clsbanckClient _ConvertLineToObj(string line)
	{
		vector<string> client = clsString::split(line, "#//#");

		return clsbanckClient(eMode::UpdateMode, client[0], client[1], client[2], client[3], client[4], client[5], stoi(client[6]));

	}

	string _ConvertObjToLine(clsbanckClient c)
	{
		string dlim = "#//#";

		string line;

		line = c.FirstName + dlim;
		line += c.LastName + dlim;
		line += c.Email + dlim;
		line += c.Phone + dlim;
		line += c.GetAccountNumber() + dlim;
		line += c.PinCode + dlim;
		line += to_string(c.AccountBalnce);
		return line;
	}

	void _UpdateFile(vector <clsbanckClient> clients)
	{


		string line;

		fstream ff;

		ff.open("Clients.txt", ios::out);

		if (ff.is_open())
		{
			for (clsbanckClient& C : clients)
			{

				if (C._Deletemark == false)
				{
					ff << _ConvertObjToLine(C) << endl;

				}


			}
		}
		ff.close();
	}

	static vector <clsbanckClient> _loadDataFromFile()
	{
		vector <clsbanckClient> clients;

		string line;

		fstream ff;

		ff.open("Clients.txt", ios::in);

		if (ff.is_open())
		{
			while (getline(ff, line))
			{

				clients.push_back(_ConvertLineToObj(line));

			}

		}
		ff.close();

		return clients;
	}

	void _Update()
	{
		vector <clsbanckClient> clients = _loadDataFromFile();

		for (clsbanckClient& C : clients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C = *this;
				break;
			}



		}
		_UpdateFile(clients);
	}

	void _AddNewToFile(string line)
	{
		fstream ff;
		ff.open("Clients.txt", ios::out | ios::app);

		if (ff.is_open())
		{
			ff << line << endl;
		}

		ff.close();
	}

	void _AddNew()
	{
		_AddNewToFile(_ConvertObjToLine(*this));
	}

	string _CovertTrasnferToLine(int Amount, clsbanckClient& C)
	{
		string l;
		l = clsDate::_GEtCueerntDateAndtime() + "#//#";
		l += GetAccountNumber() + "#//#";
		l += C.GetAccountNumber() + "#//#";
		l += to_string(Amount) + "#//#";
		l += to_string(this->AccountBalnce) + "#//#";
		l += to_string(C.AccountBalnce) + "#//#";
		l += CureentUser.UserName;

		return l;
	}

	void _SaveTransFerOp(int Amount, clsbanckClient& C)
	{
		fstream ff;
		ff.open("TransferLog.txt", ios::out | ios::app);

		if (ff.is_open())
		{
			ff << _CovertTrasnferToLine(Amount, C) << endl;
		}

		ff.close();




	}

	public:
	struct stTranserRecord
	{
		string DateAndTime;
		string AccountNumber_1;
		string AccountNumber_2;
		double Amount;
		double AccountBalance_1;
		double AccountBalance_2;
		string User;
	};

	private:

	static stTranserRecord _getTransferRecord(string line)
	{
		vector<string> tokrns = clsString::split(line, "#//#");

		stTranserRecord t;

		t.DateAndTime = tokrns[0];
		t.AccountNumber_1 = tokrns[1];
		t.AccountNumber_2 = tokrns[2];
		t.Amount = stod(tokrns[3]);
		t.AccountBalance_1 = stod(tokrns[4]);
		t.AccountBalance_2 = stod(tokrns[5]);
		t.User = tokrns[6];

		return t;
	}

	 static vector<stTranserRecord> _getTransferRecords()
	{

		vector <stTranserRecord> TranserRecords;

		string line;

		fstream ff;

		ff.open("TransferLog.txt",ios::in);

		if (ff.is_open())
		{

			while (getline(ff, line))
			{
				TranserRecords.push_back(_getTransferRecord(line));
			}

			ff.close();

			return TranserRecords;

		}

	}

public:



	bool Delete()
	{
		vector<clsbanckClient> clients = _loadDataFromFile();

		for (clsbanckClient& C : clients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._Deletemark = true;

				break;
			}

		}

		_UpdateFile(clients);

		*this = _GetEmptyObJ();

		return true;
	}

	enum eSave { eSuccess = 1, eFailEmptyObl = 2, eFailObJisExist = 3 };

	bool _ISEmpty()
	{
		return (_Mode == eMode::emptyMode);
	}

	clsbanckClient()
	{



	}

	clsbanckClient(eMode mode, string FirstName, string Lastname, string Email, string phone, string AccountNumber, string PINCode, int AccountBalance)
		:clsperson(FirstName, Lastname, Email, phone)
	{
		_Mode = mode;

		_AccountNumber = AccountNumber;

		_PINCode = PINCode;

		_AccountBalance = AccountBalance;
	}

	void SetPinCode(string pincode)
	{
		_PINCode = pincode;
	}

	string GetPinCode()
	{
		return _PINCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	string GetAccountNumber()
	{
		return _AccountNumber;
	}


	void SetAccountBalance(int AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}


	int GetAccountBalance()
	{
		return _AccountBalance;
	}


	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) int AccountBalnce;


	static clsbanckClient FindClient(string AccountNumber)
	{
		string line;

		fstream ff;

		ff.open("Clients.txt", ios::in);


		while (getline(ff, line))
		{
			clsbanckClient c = _ConvertLineToObj(line);
			if (c.GetAccountNumber() == AccountNumber)
			{
				ff.close();

				return c;
			}
		}
		ff.close();

		return _GetEmptyObJ();
	}

	/*
	void print()
	{
		cout << "First Name : " << FirstName << endl;

		cout << "Last Name : " << LastName << endl;

		cout << "Full Name : " << FullName() << endl;

		cout << "Email : " << Email << endl;

		cout << "Phone : " << Phone << endl;

		cout << "AccountNumber : " << _AccountNumber << endl;

		cout << "PINCode : " << _PINCode << endl;

		cout << "AccountBalance : " << _AccountBalance << endl;
	}
	*/

	static bool isExist(string Account_Number)
	{
		clsbanckClient c1 = clsbanckClient::FindClient(Account_Number);

		return !c1._ISEmpty();
	}

	eSave Save()
	{
		if (_Mode == eMode::UpdateMode)
		{
			_Update();

			return eSave::eSuccess;
		}
		else if (_Mode == eMode::AddNewMode)
		{
			if (!clsbanckClient::isExist(_AccountNumber))
			{
				_AddNew();

				_Mode = eMode::UpdateMode;

				return eSave::eSuccess;

			}
			else
				return eSave::eFailObJisExist;
		}
		else
			return eSave::eFailEmptyObl;
	}


	static clsbanckClient AddnewClient(string AccontNumber)
	{
		return clsbanckClient(eMode::AddNewMode, "", "", "", "", AccontNumber, "", 0);
	}


	static vector <clsbanckClient> GetClientsData()
	{

		return _loadDataFromFile();
	}


	static double sumBlances()
	{
		vector <clsbanckClient> clients = _loadDataFromFile();
		double sum = 0;



		for (clsbanckClient& C : clients)
		{
			sum += C.AccountBalnce;

		}

		return sum;
	}

	void Depoist(double number)
	{
		_AccountBalance += number;

		Save();
	}

	bool WithDraw(double number)
	{
		if (number > _AccountBalance)
		{

			return false;

		}
		else
		{

			_AccountBalance -= number;

			Save();
		}
		return true;
	}

	bool Transfer(clsbanckClient& Client2, int Amount)
	{
		/*
		 vector <clsbanckClient> ClientsList = GetClientsData();


		 for (clsbanckClient& C : ClientsList)
		 {
			 if (C.GetAccountNumber() == AccountNumberTo)
			 {
				 if (WithDraw(Amount))
				 {
					 C.Depoist(Amount);
					 return true;
				 }
				 return false;
			 }
		 }
		 return false;
		 */

		if (Amount > AccountBalnce)
		{
			return false;

		}
		else
		{

			WithDraw(Amount);
			Client2.Depoist(Amount);
			_SaveTransFerOp(Amount, Client2);
			return true;
		}

	}


	static vector<stTranserRecord> GetTranfersList() 
	{
	
		return _getTransferRecords();
	}


};

