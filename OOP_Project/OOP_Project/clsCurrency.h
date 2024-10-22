#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include <fstream>
using namespace std;



class clsCurrency
{
private:
	enum eMode { eEmpty = 0, eUpdate = 1 };
	eMode _Mode;
	string _CountryName;
	string _CurrencyName;
	string _CurrencyCode;
	
	float _Rate;

	static string  _ConvertObjtoLine(clsCurrency C)
	{
		string s;

		s = C.CountryName() + "#//#";

		s += C.CurrencyCode() + "#//#";

		s += C.CurrencyName() + "#//#";

		s += to_string(C.Rate());

		return s;
	}

	static	clsCurrency _ConvertLineToObj(string line)
	{
		vector <string> t = clsString::split(line, "#//#");

		return clsCurrency(eMode::eUpdate, t[0], t[1], t[2], stof(t[3]));
	}

	static vector <clsCurrency> _loadDataFromFile()
	{
		vector <clsCurrency>Currncys;

		fstream ff;
		string l;
		ff.open("Currencnies.txt", ios::in);
		if (ff.is_open())
		{
			while (getline(ff, l))
			{


				Currncys.push_back(_ConvertLineToObj(l));


			}
		}

		ff.close();

		return Currncys;
	}

	void _UpdateFile(vector <clsCurrency> Currncy)
	{

		fstream ff;
		string l;
		ff.open("Currencnies.txt", ios::out);
		if (ff.is_open())
		{
			for (clsCurrency& C : Currncy)
			{
				ff << _ConvertObjtoLine(C) << endl;;
			}
		}

		ff.close();

	}

	void _Update()
	{
		vector <clsCurrency> user = _loadDataFromFile();

		for (clsCurrency& C : user)
		{
			if (C.CurrencyCode() == _CurrencyCode)
			{
				C = *this;
			}
		}

		_UpdateFile(user);
	}

	static clsCurrency _GetEmptyOBJ()
	{


		return clsCurrency(eEmpty, "", "", "", 0);


	}

public:

	bool isEmpty()
	{
		return (_Mode == eEmpty);
	}

	clsCurrency(eMode m, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = m;
		_CountryName = Country;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
		_CurrencyName = CurrencyName;
	}
	clsCurrency()
	{




	}

	string CountryName()
	{

		return _CountryName;

	}

	string CurrencyCode()
	{

		return _CurrencyCode;

	}

	string CurrencyName()
	{

		return _CurrencyName;

	}

	void UpdateRate(float Rate)
	{

		_Rate = Rate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		vector <clsCurrency> Currency = _loadDataFromFile();

		for (clsCurrency& C : Currency)
		{
			if (clsString::upper_all_lettres(C.CurrencyCode()) == clsString::upper_all_lettres(CurrencyCode))
			{

				return C;

			}
		}



		return _GetEmptyOBJ();

	}

	static clsCurrency findByCountry(string CountryName)
	{
		vector <clsCurrency> Currency = _loadDataFromFile();

		for (clsCurrency& C : Currency)
		{
			if (clsString::upper_all_lettres(C.CountryName()) == clsString::upper_all_lettres(CountryName))
			{

				return C;

			}
		}



		return _GetEmptyOBJ();

	}

	static vector <clsCurrency> GetCurrencyList()
	{
		return _loadDataFromFile();
	}

	static bool isExist(string Ccode)
	{
		clsCurrency C = FindByCode(Ccode);

		return !C.isEmpty();
	}

	static float CovertFromUSDToCurrenncy(clsCurrency Curr,float Amount)
	{
		;
	}

	 float CovertFromCurrenncyToUSD(float Amount)
	{
		

			return (float)( Amount / Rate());
	
	}


	 float CovertFromCurrenncyToAnthorCurrency( clsCurrency Curr2,float Amount) 
	{

		 if (Curr2.CurrencyCode() == "USD")
			 return  Amount;
		 else
		 {
			 return (float)(Amount * Curr2.Rate());

		 }
	
	}


};

