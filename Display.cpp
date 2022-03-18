#include "Display.h"




namespace Display
{
	int DrawMainMenu()
	{
		cls();
		int size = 1;
		std::cout <<
			"\n\t1. Sing up\n" <<
			"\t2. Sing in\n" <<
			"\t3. Exit\n";
		return GetNumber(size, '3', '1');
	}
	int DrawSubMenu()
	{
		cls();
		int size = 1;
		std::cout <<
			"\n\t1. Add new real estate\n" <<
			"\t2. Remove real estate\n" <<
			"\t3. Show all real estate\n" <<
			"\t4. Show user real estate\n" <<
			"\t5. Find real estate\n" <<
			"\t6. Back\n";
		return GetNumber(size, '6', '1');
	}
	void DrawRealEstate(RealEstate* real_estate)
	{
		std::cout << "Rent " << real_estate->GetName() << ": " << real_estate->GetAmountRooms() << " rooms";
		real_estate->GetFloor() ? std::cout << ", floor is " << real_estate->GetFloor() << "\n" : std::cout << "\n";
		std::cout << "Price is " << real_estate->GetPrice() << "$\n";
		std::cout << "Address: city is " << real_estate->GetAddress()->GetCity() << ", "
			<< "street is " << real_estate->GetAddress()->GetStreet() << "\n";
	}
	void DrawPublications(std::vector<User*>& users)
	{
		if (users.size())
		{
			for (auto user : users)
			{
				if (user->GetPublications().size())
					DrawPublications(user);
			}
		}
		else throw std::exception("Users are not exist!");
	}
	void DrawPublications(User* user)
	{
		if (user->GetPublications().size())
		{
			for (size_t i = 0; i < user->GetPublications().size(); i++)
			{
				DrawRealEstate(user->GetPublications()[i]);
				DrawUserInfo(user);
				std::cout << "\n";
			}
		}
		else throw std::exception("User has not publications!");
	}
	void DrawUserInfo(User* user)
	{
		std::cout << "Contact information: " << user->GetNickname() << " (" << user->GetRank() << ")\n";
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
	std::set<std::string> DrawCities(std::vector<Address*>& addresses)
	{
		std::set<std::string> cities;
		for (auto address : addresses)
		{
			cities.insert(address->GetCity());
		}
		for (auto city : cities)
		{
			std::cout << city << "\n";
		}
		return cities;
	}
	std::set<std::string> DrawStreets(std::vector<Address*>& addresses, const char* city)
	{
		std::set<std::string> streets;
		for (auto address : addresses)
		{
			if (!strcmp(address->GetCity(), city))
				streets.insert(address->GetStreet());
		}
		for (auto street : streets)
		{
			std::cout << street << "\n";
		}
		return streets;
	}
	std::string CheckUserInputInSet(std::set<std::string> set, int size_str)
	{	
		char* input = new char[size_str];
		bool flag = false;
		while (!flag)
		{
			GetStr(size_str, input);
			for (auto i : set)
			{
				if (!i.compare(input))
				{
					flag = true;
					break;
				}					
			}
			if(!flag)std::cout << "Incorrect input!\n";
		}
		std::string buff = input;
		delete[] input;
		return buff;
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