#pragma once
#include <iostream>

#include <vector>
#include"clsDate.h"
using namespace std;
class clsUtil
{
public:

	static enum CharType { CapitalLetters = 1, SmallLetters = 2, MixChars = 3 };


	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int GetRandomNumber(int from, int to)
	{

		return rand() % (to - from + 1) + from;

	}
	static char GetRandomCharaCter(CharType Type)
	{
		if (Type == CharType::CapitalLetters)
			return GetRandomNumber(65, 90);
		if (Type == CharType::SmallLetters)
			return GetRandomNumber(97, 122);
		if (Type == CharType::MixChars)
			return  GetRandomCharaCter((CharType)GetRandomNumber(1, 2));
	}


	static string GenerateWord(CharType type, int numberOFLetters)
	{
		string s = "";

		for (int i = 0; i < numberOFLetters; i++)
		{
			s += GetRandomCharaCter(type);
		}
		return s;
	}

	static string GenerateKey(CharType type)
	{
		string s;

		s = GenerateWord(type, 4) + "-";
		s += GenerateWord(type, 4) + "-";
		s += GenerateWord(type, 4) + "-";
		s += GenerateWord(type, 4);


		return s;
	}
	static string GenerateKesys(int Keys, CharType type)
	{

		for (int i = 0; i < Keys; i++)
		{

			cout << GenerateKey(type);

			cout << endl;
		}
	}

	static void Swap(int& x, int& y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	static void Swap(double& x, double& y)
	{
		double temp;
		temp = x;
		x = y;
		y = temp;
	}
	static void Swap(clsDate& x, clsDate& y)
	{
		clsDate temp;
		temp = x;
		x = y;
		y = temp;
	}
	static void Swap(string& x, string& y)
	{
		string temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void SaffuleArray(int Array[5],int NumberOfElements)
	{

		for (int i = 0; i < NumberOfElements; i++)
		{
			Swap(Array[GetRandomNumber(0,4)], Array[GetRandomNumber(0, 4)]);
		}
	}
	static void SaffuleArray(string Array[100], int NumberOfElements)
	{
	

		for (int i = 0; i < NumberOfElements; i++)
		{
			Swap(Array[GetRandomNumber(0, NumberOfElements-1)], Array[GetRandomNumber(0, NumberOfElements-1)]);
		}

	}


	static void FillArrayWithRandomNumbers(int arr[5],int numberOfElements,int from,int to)
	{
	
		for (int i = 0; i < numberOfElements; i++)
		{
			arr[i] = GetRandomNumber(from, to);
		}
	}

	static void FillArrayWithRandomWords(string arr[5], int numberOfElements, int NumberOfChar,CharType type)
	{

		for (int i = 0; i < numberOfElements; i++)
		{
			arr[i] = GenerateWord(type,NumberOfChar);
		}
	}
	static void FillArrayWithRandomKeys(string arr[5], int numberOfElements, CharType type)
	{

		for (int i = 0; i < numberOfElements; i++)
		{
			arr[i] = GenerateKey(type);
		}
	}
	static string Encryption(string Toencript,int EncryptionKey) 
	{
		
       	
		for (int i = 0; i < Toencript.length(); i++)
		{
			Toencript[i] = Toencript[i] + EncryptionKey;
		}
		return Toencript;
	}

	static string Decryption(string ToDecript, int EncryptionKey)
	{
		


		for (int i = 0; i < ToDecript.length(); i++)
		{
			ToDecript[i] = ToDecript[i] - EncryptionKey;
		}
		return ToDecript;
	}
};

