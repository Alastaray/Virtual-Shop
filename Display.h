#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <set>
#include "User.h"
#include "RealEstate.h"


template <class type>
void DeleteVector(std::vector<type *>& vec)
{
	for (auto i : vec)
		delete i;
	vec.clear();
	vec.shrink_to_fit();
}

namespace Display
{
	enum Symbols
	{
		A = 'A',
		a = 'a',
		z = 'z',
		Z = 'Z',
		Zero = '0',
		Nine = '9',
	};
	inline void cls() { system("cls"); }
	int DrawMainMenu();
	int DrawSubMenu();
	void DrawRealEstate(RealEstate* real_estate);
	void DrawPublications(std::vector<User*>& users);
	void DrawPublications(User* user);
	void DrawUserInfo(User* user);
	std::pair<const char*, const char*> DrawLoginMenu(unsigned nickname_size, unsigned password_size);
	std::set<std::string> DrawCities(std::vector<Address*>& addresses);
	std::set<std::string> DrawStreets(std::vector<Address*>& addresses, const char* city);
	std::string CheckUserInputInSet(std::set<std::string> set, int size_str);
	int GetNumber(unsigned amount_symbols, char to_number = Nine, char from_number = Zero);
	void GetStr(unsigned amount_symbols, char* destination);
	void GetData(unsigned amount_symbols, char* destination);
}