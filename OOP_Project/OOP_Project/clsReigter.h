#pragma once

#include"clsScreen.h"

#include<iostream>

using namespace std;


class clsReigter
{
private:
	string _DateANDTime;
	string _Username;
	string _Password;
	int _Permisson;

	static clsReigter _ConvertLineToReStieruser(string S)
	{
		vector<string> Tokens = clsString::split(S, "#//#");

		return clsReigter(Tokens[0],Tokens[1],clsString::Decrypt(Tokens[2],2),stoi(Tokens[3]));
	}

	static vector <clsReigter> _loadRegisterUsers()

	{
		vector <clsReigter> vRU;

		fstream ff;
		string l;
		ff.open("Registers2.txt", ios::in);
		if (ff.is_open())
		{
			while (getline(ff, l))
			{
				vRU.push_back(_ConvertLineToReStieruser(l));

			}
		}

		ff.close();

		return vRU;
	}


	clsReigter(string DateANDTime, string Username, string Password,int Per)
	{
	
		_DateANDTime = DateANDTime;
		_Username = Username;
		_Password = Password;
		_Permisson = Per;
	}


public:
	void SetPermissions(int Per)
	{

		_Permisson = Per;
	}

	int GetPermissions()
	{
		return _Permisson;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissons;

	void SetPassword(string P)
	{

		_Password = P;

	}

	string GetPassword()
	{

		return _Password;

	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetUserName(string U)
	{

		_Username = U;

	}

	string GetUserName()
	{

		return _Username;

	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;


	string GetDateAndtimeName()
	{

		return  _DateANDTime;

	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	static  vector <clsReigter> GetRegisterlist()
	{

		return _loadRegisterUsers();
	}




};

