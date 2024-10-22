#pragma once
#include <iostream>

#include <vector>
#include<string>
using namespace std;

 

class clsString
{
private:
	string _Value;

	enum en_what_to_count { capitalLetters = 1, Smallletters = 2 };

	enum vowel { a = 'a', e = 'e', i = 'i', o = 'o', u = 'u' };

	
public:

	
	static char invert_letter_case(char m)
	{
		if (m == toupper(m))
			return tolower(m);
		else if (m == tolower(m))
			return toupper(m);
	}


	clsString() 
	{
	
		_Value = "";
	
	}

	clsString(string Word)
	{

		_Value = Word;

	}

	void setValue(string Word)
	{
		_Value = Word;
	}
	string getValue() 
	{
		return _Value;
	}


	__declspec(property(get = getValue, put = setValue)) string Value;
	
	static int count_each_word(string s1)
	{
		int count = 0;
		string dlim = " ";
		int pos = 0;
		string word = "";
		while ((pos = s1.find(dlim)) != std::string::npos)
		{
			word = s1.substr(0, pos);
			if (word != " ") {
				count++;
			}
			s1.erase(0, pos + dlim.length());
		}
		if (s1 != " ")
		{
			count++;
		}
		return count;
	}

	int count_each_word() 
	{
		return count_each_word(_Value);

	}

	

	static bool is_vowel(char n)
	{
		n = tolower(n);
		return (n == vowel::a || n == vowel::e || n == vowel::i || n == vowel::o || n == vowel::u);
	}

	static void printfirstleeter(string word)
	{


		char c;
		word = word.insert(0, " ");

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == ' ')
			{
				c = (word[i + 1]);

				cout << c <<" ";
			}

			else
				continue;
		}

		/*
		for (int i = 0; i <word.length(); i++)
		{
			if (word[i] != ' ' && isfirstletter)
				cout << word[i] << endl;


			isfirstletter = (word[i] ==' ' ? true : false);
		}

		*/

	}

	void printfirstleeter() 
	{
	  printfirstleeter(_Value);
	}
	static 	string  makecapitalletters(string word)
	{
		char c;
		word = word.insert(0, " ");

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == ' ')
			{
				c = toupper(word[i + 1]);
				word[i + 1] = c;
			}

			else
				continue;
		}
		return word;
		/*
		for (int i = 0; i <word.length(); i++)
		{
			if (word[i] != ' ' && isfirstletter)
				word[i]=toupper(word[i]);


			isfirstletter = (word[i] ==' ' ? true : false);
		}
		*/
	}

	void  makecapitalletters() 
	{
		_Value= makecapitalletters(_Value);
	
	}

	static 	string LowerOfFirstword(string word)
	{
		/*
		bool isfirstletter = true;
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ' && isfirstletter)
				word[i] = tolower(word[i]);

			isfirstletter = (word[i] == ' ' ? true:false);

		}
		*/

		char c;
		word = word.insert(0, " ");

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == ' ')
			{
				c = tolower(word[i + 1]);
				word[i + 1] = c;
			}

			else
				continue;
		}
		return word;


	}


	void LowerOfFirstword () 
	{
	
		_Value= LowerOfFirstword(_Value);
	}


	static 	string lower_all_lettres(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void lower_all_lettres() 
	{
	
		_Value = lower_all_lettres(_Value);
	}
	static string upper_all_lettres(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void upper_all_lettres() 
	{
		_Value= upper_all_lettres(_Value);
	}
	static 	string invert_string_letter_cases(string word)
	{
		for (int i = 0; i < word.length(); i++)
		{

			word[i] = invert_letter_case(word[i]);

		}
		return word;
	}

	void invert_string_letter_cases() 
	{
	
	_Value= invert_string_letter_cases(_Value);

	}
	static int count_capital_Letters(string word)
	{
		int count = 0;
		for (int i = 0; i < word.length(); i++)
		{
			if (isupper(word[i]))
				count++;
		}
		return count;
	}
	static int count_small_Letters(string word)
	{
		int count = 0;
		for (int i = 0; i < word.length(); i++)
		{
			if (islower(word[i]))
				count++;
		}
		return count;
	}

	

	int count_capital_Letters() 
	{
		return count_capital_Letters(_Value);
	}


	
	int count_small_Letters() 
	{
	
		return count_small_Letters(_Value);
	
	}
	
	static 	int count_letters(string s1, en_what_to_count Type)
	{
		int count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (isupper(s1[i]) && Type == en_what_to_count::capitalLetters)
				count++;
			else if (islower(s1[i]) && Type == en_what_to_count::Smallletters)
				count++;
		}
		return count;
	}

	int count_letters(int i) 
	{
	
		return  count_letters(_Value,(en_what_to_count)i);

	}

	static  int count_vowel(string s1)
	{
		int count = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (is_vowel(s1[i]))
				count++;

		}
		return count;
	}
	int count_vowel() 
	{
		return count_vowel(_Value);
	}

	static void print_each_word(string s1)
	{
		string dlim = " ";
		int pos = 0;
		string word = "";
		cout << "string words are" << endl;
		while ((pos = s1.find(dlim)) != std::string::npos)
		{
			word = s1.substr(0, pos);
			if (word != " ")
				cout << word << endl;
			s1.erase(0, pos + dlim.length());
		}
		if (s1 != " ")
			cout << s1;
	}
	void print_each_word() 
	{
	
		print_each_word(_Value);

	}

	static vector <string> split(string s1, string dlim)
	{
		int pos = 0;
		vector <string> vtokens;
		string token = "";
		while ((pos = s1.find(dlim)) != std::string::npos)
		{
			token = s1.substr(0, pos);
			if (token != " ")
				vtokens.push_back(token);
			s1.erase(0, pos + dlim.length());
		}
		if (s1 != dlim)
			vtokens.push_back(s1);

		return vtokens;
	}

	 vector <string> split(string dlim) 
	{
		return split(_Value, dlim);
	   
	}
	static string revreseWord(string s1, string dlim)
	{
		string s2 = "";
		vector <string> words = split(s1, dlim);
		vector <string>::iterator iter = words.end();
		while (iter != words.begin())
		{
			--iter;

			s2 += *iter + dlim;
		}
		return s2.substr(0, s2.length() - dlim.length());
	}
	
	void revreseWord(string dlim) 
	{
		_Value = revreseWord(_Value, dlim);
	}
	static 	string delete_punct(string s1)
	{
		string s2 = s1;
		for (int i = 0; i < s1.length(); i++)
		{
			if (ispunct(s2[i]))
				s2[i] = ' ';

		}
		return s2;
	}

	void delete_punct() 
	{
		_Value = delete_punct(_Value);
	}
    static string join(vector <string>& join, string dlim)
	{
		string s1;

		for (string& sword : join)
		{
			s1 += sword;
			s1 += dlim;
		}
		return s1.substr(0, s1.length() - dlim.length());
	}

	static string  join(string arr[4], string dlim, int size)
	{
		string s1;
		for (int i = 0; i < size; i++)
		{
			s1 += arr[i];
			s1 += dlim;
		}

		return s1.substr(0, s1.length() - dlim.length());
	}

	static string Encrypt(string Pass, int EncruptionKey)
	{
	
		for (int i = 0; i <Pass.length(); i++)
		{
			Pass[i] = Pass[i] + EncruptionKey;

		}

		return Pass;
	}
	static string Decrypt(string Pass, int EncruptionKey)
	{

		for (int i = 0; i < Pass.length(); i++)
		{
			Pass[i] = Pass[i] - EncruptionKey;

		}

		return Pass;
	}

};

