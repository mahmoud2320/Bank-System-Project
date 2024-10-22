#pragma once
# pragma warning (disable:4996);
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include"clsString.h"
using namespace std;


class clsDate
{
private:
	int _Day = 1;

	int _Month = 12;

	int _Year = 1900;
	
public:
	enum compare_dates { equel2 = 0, before = -1, after = 1 };
	clsDate()
	{
		time_t t=time(0);
		tm*now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year+1900;
	}
	clsDate(string Date)
	{
		vector<string> D = clsString::split(Date,"/");

		_Day = stoi(D[0]);
		_Month = stoi(D[1]);
		_Year = stoi(D[2]);
	}
	clsDate(int Day,int Month,int Year) 
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(int NumberOfdays, int Year)
	{
		clsDate d = get_date(NumberOfdays, Year);
		_Day = d.Day;
		_Month = d.Month;
		_Year = d.Year;

	}

	void setDay(int day) 
	{
	
		_Day = day;
	
	}
	int getDay() 
	{
	
		return _Day;
	}
	__declspec(property(get = getDay, put = setDay)) int Day;


	void setMonth(int Month)
	{

		_Month = Month;

	}
	
	int getMonth()
	{

		return _Month;
	}
	__declspec(property(get = getMonth, put = setMonth)) int Month;

	void setYear(int day)
	{

		_Year =day;

	}

	int getYear()
	{

		return _Year;
	}
	__declspec(property(get = getYear, put = setYear)) int Year;
    
  static int days_in_month(int month, int year)
	{
		/*
		 if (month == 2)
			 return leap_year(year) ? 29 : 28;

		 int arr [7] = {1,3,5,7,8,10,12};
		 for (int i = 0; i < 7; i++)
		 {
			 if (arr[i] == month)
				 return 31;
		 }

		 return 30;
		 */
		 /*
		  return leap_year(year) && (month == 2) ? 29 : (month == 2) ? 28 : days_in_month(month);
		  */
		int number_of_days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		return  leap_year(year) && (month == 2) ? 29 : (month == 2) ? 28 : number_of_days[month - 1];

	}

  int days_in_month() 
  {
	  return  days_in_month(this->Month, this->Year);
  }


	static bool leap_year(int year)
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}



	static clsDate get_date(int days, int year)
	{
		clsDate date;
		short remaining_days = days;
		short month_days = 0;
		date.Month = 1;
		date.Year = year;
		while (true)
		{
			month_days = days_in_month(date.Month, year);

			if (remaining_days > month_days)
			{
				remaining_days -= month_days;
				date.Month++;
			}
			else
			{
				date.Day = remaining_days;

				break;
			}

		}

		return date;
	}

	static  string get_date_to_l(clsDate  date, string dlim)
	{
		string datel;

		datel = to_string(date.Day) + dlim;
		datel += to_string(date.Month) + dlim;
		datel += to_string(date.Year);

		return datel;
	}

	string get_date_to_l()
	{

	return  get_date_to_l(*this, "/");

	}

	static clsDate GetSystemDate() 
	{
		

		time_t t = time(0);
		tm* now = localtime(0);
		short Day, Month, Year;
		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;
	
		return clsDate(Day,Month,Year);
	}

	static bool is_valid_date(clsDate date)
	{
		/*
		sDate end,start;
		end.day = 31;
		end.month = 12;
		end.year = date.year;

		start.day = 1;
		start.month = 1;
		start.year = date.year;

		if (date.day == 29 && date.month == 2 && !leap_year(date.year))
			return false;

		while (is_date1_Less_Than_date2(start, end))
		{
			if (check_equeels_of_date(date, start))
				return true;

			start = update_date_with_one_dau(start);

		}
		return false;
		*/


		if (date.Day > 31 || date.Day < 1)
			return false;
		if (date.Month > 12 || date.Month < 1)
			return false;
		if (date.Day == 29 && date.Month == 2 && !leap_year(date.Year))
			return false;

		return true;
	}

	bool is_valid_date() 
	{
		return  is_valid_date(*this);
	}


	void print() 
	{
		cout << get_date_to_l(*this, "/");
	}

	static clsDate adding_one_month(clsDate & date)
	{
		if (date.Month == 12)
		{
			date.Month = 1;
			date.Year++;
		}
		else
		{
			date.Month++;
		}

		int number_of_days_in_current_month = days_in_month(date.Month, date.Year);
		if (date.Day > number_of_days_in_current_month)
			date.Day = number_of_days_in_current_month;

		return date;
	}

	void adding_one_month() 
	{
		adding_one_month(*this);
	}

	static	bool is_date1_Less_Than_date2(clsDate date1, clsDate date2)
	{

		return	(date1.Year < date2.Year) ? true : (date1.Year == date2.Year) ? ((date1.Month < date2.Month) ? true : (date1.Month == date2.Month) ? (date1.Day < date2.Day) : false) : false;


	}

	static	bool check_equeels_of_date(clsDate date1, clsDate date2)
	{
		return (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? true : false) : false) : false;
	}

	static compare_dates compare_datef(clsDate date1, clsDate date2)
	{
		
		if (is_date1_Less_Than_date2(date1, date2))
			return compare_dates::before;

		else if (check_equeels_of_date(date1, date2))

			return compare_dates::equel2;

		else
			return compare_dates::after;

	}

	
	static string _GEtCueerntDateAndtime()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		string TimeInline = to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);

		return clsDate().get_date_to_l() + "-" + TimeInline;
	}
};