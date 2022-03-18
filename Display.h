#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "User.h"
#include "Product.h"


template <class type>
void DeleteVector(std::vector<type>& vec)
{
	for (auto i = vec.begin(); i < vec.end(); i++)
		delete* i;
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
	int DrawEmployeeMenu();
	std::pair<const char*, const char*> DrawLoginMenu(unsigned nickname_size, unsigned password_size);
	void DrawUser(User* user);
	void DrawUser(std::vector<User*>& users, bool is_vip = false, bool have_purchase = false);
	void DrawProduct(Product* product);
	void DrawProduct(std::vector<Product*>& products, bool all = false);
	void DrawShoppingBasket(std::vector<Product*>& bought_products, double purchase_amount);
	int GetNumber(unsigned amount_symbols, char to_number = Nine, char from_number = Zero);
	void GetStr(unsigned amount_symbols, char* destination);
	void GetData(unsigned amount_symbols, char* destination);
}