#include "RealEstatesManagement.h"


RealEstatesManagement::RealEstatesManagement()
{
	SetAddresses();
}
RealEstatesManagement::~RealEstatesManagement()
{
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
Address* RealEstatesManagement::GetLocation(int str_size)
{
	std::string city = Display::CheckUserInputInSet(Display::DrawCities(addresses), str_size);

	std::string street = Display::CheckUserInputInSet(Display::DrawStreets(addresses, city.c_str()), str_size);
	return new Address(city.c_str(), street.c_str());
}
RealEstate* RealEstatesManagement::CreateRealEstate()
{
	const int str_size = 30;
	static int id = 1;
	const char rent[] = "Rent";
	const char sale[] = "Sale";
	Address* address = GetLocation(str_size);

	std::cout << "0. "<< rent <<"\n";
	std::cout << "1. " << sale << "\n";
	bool is_rent = Display::GetNumber(1);
	std::cout << "Enter the type of real estate (flat, private house):\n";
	char* name = new char[str_size];
	Display::GetStr(str_size, name);

	std::cout << "Enter the price:\n";
	int price = Display::GetNumber(6);

	std::cout << "Enter the amount rooms:\n";
	int	amount_rooms = Display::GetNumber(3);

	std::cout << "Enter a floor, if you live in private house, enter the '0':\n";
	int	floor = Display::GetNumber(3);

	RealEstate* real_estate = new RealEstate(id, address, name, price, amount_rooms, floor, is_rent);
	id++;
	delete address;
	return real_estate;
}