#pragma once
#include<iostream>
using namespace std;
#include "clsperson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"


class clsUser :public clsperson
{
private:

	

	enum _eMode
	{
		EmptyMode = 1,
		UpdateMode = 2,
		AddNewMode = 3
	};

	_eMode _Mode;
	string _Username;
	string _Password;
	int _Permisson;
	bool DeleteMark = false;

	static clsUser  _GetEmptyuser()
	{
		return clsUser(_eMode::EmptyMode, "", "", "", "", "", "", 0);

	}

	static clsUser _ConvertFromLineTiObj(string line)
	{


		vector <string> tokens = clsString::split(line, "#//#");


		return clsUser(_eMode::UpdateMode, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4],clsString::Decrypt (tokens[5],2), stoi(tokens[6]));

	}

	static	string _ConvertobjToline(clsUser C)
	{
		string tokens;
		tokens = C.FirstName + "#//#";
		tokens += C.LastName + "#//#";
		tokens += C.Email + "#//#";
		tokens += C.Phone + "#//#";
		tokens += C.UserName + "#//#";
		tokens += clsString::Encrypt(C.Password, 2) + "#//#";
		tokens += to_string(C.Permissons);

		return tokens;
	}

	static vector <clsUser> _loadDataFromFile()
	{
		vector <clsUser>users;

		fstream ff;
		string l;
		ff.open("Users2.txt", ios::in);
		if (ff.is_open())
		{
			while (getline(ff, l))
			{


				users.push_back(_ConvertFromLineTiObj(l));


			}
		}

		ff.close();

		return users;
	}

	void _UpdateFile(vector <clsUser> users)
	{

		fstream ff;
		string l;
		ff.open("Users2.txt", ios::out);
		if (ff.is_open())
		{
			for (clsUser& C : users)
			{
				if (C.DeleteMark == false)
					ff << _ConvertobjToline(C) << endl;;
			}
		}

		ff.close();

	}

	void _Update()
	{
		vector <clsUser> user = _loadDataFromFile();

		for (clsUser& U : user)
		{
			if (U.UserName == _Username)
			{
				U = *this;
			}
		}

		_UpdateFile(user);
	}

	void _AddnewOnfile()
	{
		fstream ff;
		string l;
		ff.open("Users2.txt", ios::out | ios::app);
		if (ff.is_open())
		{
			ff << _ConvertobjToline(*this) << endl;
		}
	}

	 string _ConvertregisterLoginAsline()
	{
		string Line;
		Line = clsDate::_GEtCueerntDateAndtime() + "#//#";
		Line += this->UserName + "#//#";
		Line += clsString::Encrypt( this->Password,2) + "#//#";
		Line += to_string(this->Permissons);

		return Line;
	}

	
public:

	enum Permissoins
	{
		pAll=-1,
		pShowClientList=1,
		pUpdateClient=2,
		pAddNewClient=4,
		pDeleteClient =8,
		pTransActios=16,
		pMangeUsers=32,
		pFindClient = 64,
		pReigsterScreen=128,
		pCurrencyExchange = 256
	};

	static clsUser AddNewuser(string UserName)
	{
		return clsUser(AddNewMode, "", "", "", "", UserName, "", 0);
	}

	clsUser(_eMode mode, string FirstName, string lastName, string Email, string Phone, string UserName, string Password, int permissions) :
		clsperson(FirstName, lastName, Email, Phone)
	{
		_Mode = mode;
		_Username = UserName;
		_Password = Password;
		_Permisson = permissions;
	}

	void SetUserName(string U)
	{

		_Username = U;

	}

	string GetUserName()
	{

		return _Username;

	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string P)
	{

		_Password = P;

	}

	string GetPassword()
	{

		return _Password;

	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Per)
	{

		_Permisson = Per;
	}

	int GetPermissions()
	{
		return _Permisson;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissons;

	bool isEmpty()
	{
		return (_Mode == _eMode::EmptyMode);

	}

	static clsUser Find(string UserName)
	{
		vector <clsUser> users = _loadDataFromFile();

		fstream ff;
		string l;
		ff.open("Users2.txt", ios::in);
		if (ff.is_open())
		{
			for (clsUser& U : users)
			{
				if (U.UserName == UserName)
				{
					ff.close();

					return U;
				}
			}
		}

		return _GetEmptyuser();

	}

	static clsUser Find(string UserName, string PassWord)
	{
		vector <clsUser> users = _loadDataFromFile();

		fstream ff;
		string l;
		ff.open("Users2.txt", ios::in);
		if (ff.is_open())
		{
			for (clsUser& U : users)
			{
				if (U.UserName == UserName &&  U.Password == PassWord)
				{
					ff.close();

					return U;
				}
			}
		}
		return _GetEmptyuser();
	}

	static	bool IsExist(string User)
	{
		clsUser U = Find(User);

		return !U.isEmpty();

	}

	static	bool IsExist(string User,string Password)
	{
		clsUser U = Find(User,Password);

		return !U.isEmpty();

	}

	enum eSave { eSuccesed = 1, eEmptyObj = 2, eExistObj = 3 };

	eSave Save()
	{
		if (_Mode == UpdateMode)
		{
			_Update();

			return eSuccesed;
		}

		if (_Mode == AddNewMode)
		{
			_AddnewOnfile();

			_Mode = UpdateMode;

			return eSuccesed;
		}

		if (_Mode == EmptyMode)
		{

			return eEmptyObj;

		}
		if (_Mode == EmptyMode)
		{

			return eEmptyObj;

		}

		if (IsExist(this->UserName))
		{

			return eExistObj;

		}
	}


	bool Delete()
	{
		vector <clsUser> user = _loadDataFromFile();

		fstream ff;
		string l;
		ff.open("Users2.txt", ios::out | ios::app);
		if (ff.is_open())
		{
			for (clsUser& U : user)
			{
				if (U.UserName == _Username)
				{
					U.DeleteMark = true;
				}
			}
		}

		*this = _GetEmptyuser();

		_UpdateFile(user);

		return true;
	}


    static vector <clsUser> GetuserList()
	{
		return _loadDataFromFile();
	}

	bool CheckPermission(Permissoins per)
	{
		if (_Permisson == Permissoins::pAll)
			return true;

		if ((_Permisson & per) == per)
		{
			return true;
		}
		else
			return false;
	}

	 void AddRegisrerLogin() 
	{
		fstream ff;

		ff.open("Registers2.txt", ios::out | ios::app);

		if (ff.is_open()) 
		{
			ff << _ConvertregisterLoginAsline() << endl;

			ff.close();

		}
	}

};

