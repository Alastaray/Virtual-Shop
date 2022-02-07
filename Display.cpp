#include "Display.h"




namespace Display
{
	int DrawMainMenu()
	{
		cls();
		int size = 1;
		std::cout <<
			"\n\t0. Sing up\n" <<
			"\t1. Sing in\n" <<
			"\t2. Exit\n";
		return GetNumber(size, '2');
	}
	std::pair<const char*, const char*> DrawLoginMenu(unsigned nickname_size, unsigned password_size)
	{
		if (!nickname_size || !password_size)
			throw std::exception("nickname's size or password's size can't be null");
		char* nickname = new char[nickname_size];
		char* password = new char[password_size];
		std::cout << "Enter the your nickname!\n";
		Display::GetStr(nickname_size, nickname);
		std::cout << "Enter the your password!\n";
		Display::GetData(password_size, password);
		return { nickname, password };
	}
	void DrawUser(User* user)
	{
		if (user)
		{
			std::cout << "\t" <<
				user->GetId() << "\t" <<
				user->GetNickname() << "\t\t" <<
				user->GetPassword() << "\t\t" <<
				user->GetPurchaseAmount() << "\t\t\t" <<
				user->GetRank() << "\n";
		}
		else
		{
			std::cout << "User doesn't exist!";
			_getch();
		}
	}
	void DrawUser(std::vector<User*>& users, bool is_vip, bool have_purchase)
	{
		if (users.size())
		{
			cls();
			int counter = 0;
			std::cout <<
				"\n\tId\t" << "Nickname\t" << "Password\t" << "Purchase Amount\t\t" << "Rank\n";
			for (size_t i = 0; i < users.size(); i++)
			{
				if (is_vip)
				{
					if (!strcmp(users[i]->GetRank(), UserRanks::GetVip()))
					{
						DrawUser(users[i]);
						counter++;
					}
				}
				else if (have_purchase)
				{
					if (users[i]->GetPurchaseAmount())
					{
						DrawUser(users[i]);
						counter++;
					}
				}
				else
				{
					DrawUser(users[i]);
					counter++;
				}
			}
			if (!counter)
			{
				cls();
				std::cout << "This users don't exist!\n";
			}
				_getch();
		}		
	}
	void DrawProduct(Product* product)
	{
		if (product)
		{
			std::cout << "\t" <<
				product->GetId() << "\t\t" <<
				product->GetName() << "\t\t" <<
				product->GetPrice() << "\t\t" <<
				product->GetAmount() << "\t\t" <<
				product->GetVipDiscount() * 100 << "%\t\t" <<
				product->GetStatusStock() << "\n";
		}	
		else
		{
			std::cout << "Product doesn't exist!";
			_getch();
		}
	}
	void DrawProduct(std::vector<Product*>& products, bool all)
	{
		if (products.size())
		{
			Display::cls();
			std::cout <<
				"\n\tId\t\t" << "Name\t\t" << "Price\t\t" << "Amount\t\t" << "Vip Discount\t" << "Status stock\n";
			for (size_t i = 0; i < products.size(); i++)
			{
				if (all)DrawProduct(products[i]);
				else
				{
					if (products[i]->GetStatusStock())
						DrawProduct(products[i]);
				}
			}
		}	
	}
	void DrawShoppingBasket(std::vector<Product*>& bought_products, double purchase_amount)
	{
		if (bought_products.size())
		{
			Display::DrawProduct(bought_products, true);
			std::cout << "\t\t^^^^^^^^^^^^You bought^^^^^^^^^^^^^^\n";
			std::cout << "\nPurchase amount is " << purchase_amount;
			_getch();
		}
	}
	int DrawEmployeeMenu()
	{
		cls();
		int size = 1;
		std::cout <<
			"\n\t0. Show all users\n" <<
			"\t1. Show all customers, which are vip\n" <<
			"\t2. Show all users, which have even bought one thing\n" <<
			"\t3. Show user, which have purchase amount is the highest\n" <<
			"\t4. Add new product\n" <<
			"\t5. Change inventory status\n" <<
			"\t6. Buy something\n" <<
			"\t7. Back\n";
		return GetNumber(size, '7');
	}
	int GetNumber(unsigned amount_symbols, char to_number, char from_number)
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
			else if (key == '\n' && i > 0)break;
			else
			{
				std::cout << "Enter a correct number!\n";
				if (i)
				{
					delete[]buff;
					buff = new char[amount_symbols + 1];
					i = 0;
				}			
				std::cin.ignore(std::cin.rdbuf()->in_avail());
			}
		}
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		buff[i] = '\0';
		int num = atoi(buff);
		delete[]buff;
		return num;
	}
	void GetStr(unsigned amount_symbols, char* destination)
	{
		char* buff = new char[amount_symbols + 1];
		char key;
		int i = 0;
		while (i < amount_symbols)
		{
			std::cin.get(key);
			if ((key >= a && key <= z) || (key >= A && key <= Z && i == 0))
				buff[i++] = key;
			else if (key == '\n' && i > 0)break;
			else
			{
				std::cout << "A string consists of more than just letters!\n";
				delete[]buff;
				buff = new char[amount_symbols + 1];
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				i = 0;
			}
		}
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		buff[i] = '\0';
		strcpy_s(destination, i + 1, buff);
		delete[]buff;
	}
	void GetData(unsigned amount_symbols, char* destination)
	{
		char* buff = new char[amount_symbols + 1];
		char key;
		int i = 0;
		while (i < amount_symbols)
		{
			std::cin.get(key);
			if ((key >= a && key <= z) || (key >= A && key <= Z && i == 0) || (key >= Zero && key <= Nine))
				buff[i++] = key;
			else if (key == '\n' && i > 0)break;
			else
			{
				std::cout << "A string consists of more than just letters!\n";
				delete[]buff;
				buff = new char[amount_symbols + 1];
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				i = 0;
			}
		}
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		buff[i] = '\0';
		strcpy_s(destination, i + 1, buff);
		delete[]buff;
	}
}