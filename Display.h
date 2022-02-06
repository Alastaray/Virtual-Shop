#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "User.h"
#include "Product.h"


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
	void cls();
	int DrawMainMenu();
	int DrawEmployeeMenu();
	std::pair<const char*, const char*> DrawLoginMenu(unsigned nickname_size, unsigned password_size);
	void DrawUser(std::vector<User*> users, unsigned index);
	void DrawProduct(std::vector<Product*> product, unsigned index);
	void DrawProducts(std::vector<Product*> products, bool all = false);
	int GetNumber(unsigned amount_symbols, char to_number = Nine, char from_number = Zero);
	void GetStr(unsigned amount_symbols, char* destination);
	void GetData(unsigned amount_symbols, char* destination);
}