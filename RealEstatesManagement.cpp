#include "RealEstatesManagement.h"


RealEstatesManagement::RealEstatesManagement()
{
	SetAddresses();
}
RealEstatesManagement::~RealEstatesManagement()
{
	DeleteVector(realestates);
	DeleteVector(addresses);
}
void RealEstatesManagement::SetAddresses()
{
	std::fstream file;
	const int string_size = 100;
	const char* delimetr = ", ";
	char* buff = new char[string_size];
	file.open("Addresses.txt", std::ios::out | std::ios::in);
	file.seekg(std::ios::beg);
	while (!file.eof())
	{
		file.getline(buff, string_size, '\n');
		char* splited_str = strtok(buff, delimetr);
		char* city = splited_str;
		splited_str = strtok(0, delimetr);
		char* street = splited_str;
		addresses.push_back(new Address(city, street));
	}
	file.clear();
	file.close();
	delete[]buff;
}
void RealEstatesManagement::AddRealEstate()
{
	const int str_size = 30;
	static int id = 1;

	char* city = new char[str_size];
	std::string user_city = Display::CheckUserInputInSet(Display::DrawCities(addresses), str_size);
	strcpy_s(city, str_size, user_city.c_str());

	char* street = new char[str_size];
	std::string user_street = Display::CheckUserInputInSet(Display::DrawStreets(addresses, city), str_size);
	strcpy_s(street, str_size, user_street.c_str());

	std::cout << "Enter the type of real estate (flat, private house):\n";
	char* name = new char[str_size];
	Display::GetStr(str_size, name);

	std::cout << "Enter the real estate price:\n";
	int price = Display::GetNumber(6);

	std::cout << "Enter the amount rooms:\n";
	int	amount_rooms = Display::GetNumber(3);

	std::cout << "Enter a floor, if you live in private house, enter the '0':\n";
	int	floor = Display::GetNumber(3);

	Address* address = new Address(city, street);
	realestates.push_back(new RealEstate(id, address, name, price, amount_rooms, floor));
	id++;
	delete[]city;
	delete[]street;
	delete address;
}