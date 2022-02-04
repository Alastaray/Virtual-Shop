#include "Display.h"

namespace Display
{
	

	void cls() { system("cls"); }
	int DrawMainMenu()
	{
		cls();
		int size = 1;
		std::cout <<
			"0. Sing up\n" <<
			"1. Sing in\n" <<
			"2. Exit\n";
		return GetNumber(size, '2');
	}
	int GetNumber(unsigned int amount_symbols, char to_number = Nine, char from_number = Zero)
	{		
		if ((to_number < Zero || to_number > Nine) || (from_number < Zero || from_number > Nine)) 
			throw std::exception("Unknown number symbol!");
		char* buff = new char[amount_symbols + 1];
		char key;
		int i = 0;
		while (i < amount_symbols)
		{
			std::cin.get(key);
			if (key >= from_number && key <= to_number)buff[i++] = key;
			else if (key == '\n')break;
			else
			{
				std::cout << "Enter a correct number!\n";
				delete[]buff;
				buff = new char[amount_symbols + 1];
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				i = 0;
			}
			std::cin.ignore();
		}
		buff[i] = '\0';
		int num = atoi(buff);
		delete[]buff;
		return num;
	}
	void GetStr(unsigned int amount_symbols, char* destination)
	{
		char* buff = new char[amount_symbols + 1];
		char key;
		int i = 0;
		while (i < amount_symbols)
		{
			std::cin.get(key);
			if ((key >= a && key <= z) || (key >= A && key <= Z && i == 0))
				buff[i++] = key;
			else if (key == '\n')break;
			else
			{
				std::cout << "A string consists of more than just letters!\n";
				delete[]buff;
				buff = new char[amount_symbols + 1];
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				i = 0;
			}
		}
		buff[i] = '\0';
		strcpy_s(destination, i + 1, buff);
		delete[]buff;	
	}
	void GetData(unsigned int amount_symbols, char* destination)
	{
		char* buff = new char[amount_symbols + 1];
		char key;
		int i = 0;
		while (i < amount_symbols)
		{
			std::cin.get(key);
			if ((key >= a && key <= z) || (key >= A && key <= Z && i == 0) || (key >= Zero && key <= Nine))
				buff[i++] = key;
			else if (key == '\n')break;
			else
			{
				std::cout << "A string consists of more than just letters!\n";
				delete[]buff;
				buff = new char[amount_symbols + 1];
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				i = 0;
			}
		}
		buff[i] = '\0';
		strcpy_s(destination, i + 1, buff);
		delete[]buff;
	}
}