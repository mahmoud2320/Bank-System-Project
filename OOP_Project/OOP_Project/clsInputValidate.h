#pragma once

#include<iostream>

using namespace std;

#include "clsUtil.h"

#include"clsDate.h"

class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number,int from ,int to) 
	{
		if (Number >= from && Number <= to)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double from, double to)
	{
		if (Number >= from && Number <= to)
			return true;
		else
			return false;
	}
	static bool IsDateBetween(clsDate Mydate,clsDate date1, clsDate date2)
	{
		if (!clsDate::is_date1_Less_Than_date2(date1, date2)) 
		{
			clsUtil::Swap(date1, date2);
		}


		if (clsDate::compare_datef(date1, Mydate) == clsDate::before && clsDate::compare_datef(Mydate, date2) == clsDate::before)
			return true;
		else
			return false;

	}

	static int ReadIntNumber(string ErrorMessage="")
	{
		int Number;

	
		while (!(cin >> Number))
		{
			
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage << endl;
				
		}	

		return Number;
	}
	static double ReadDblNumber(string ErrorMessage="Number is InValid")
	{
		double Number;

		
		while (!(cin >> Number))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage << endl;
		}

		return Number;

	}

	static	int ReadNumberBetween(int num2,int num3,string Message=" number isnt in range")
	{
		int number;

		do 
		{
			cin >> number;

			if (IsNumberBetween(number, num2, num3))
				break;

			else
				cout << Message << endl;
		
		} while (true);


			return number;
	}
	static	double ReadNumberBetween(double num2, double num3, string Message)
	{
		double number;

		do
		{
			cin >> number;

			if (IsNumberBetween(number, num2, num3))
				break;

			else
				cout << Message << endl;

		} while (true);


		return number;
	}


	static bool IsValideDate(clsDate date)
	{
		return clsDate::is_valid_date(date);
	}


    static	string ReadString() 
	{
		string s;
		cin >>  s;
	
		return s;
	
	}


};

