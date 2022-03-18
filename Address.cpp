#include "Address.h"

Address::Address(const char* city, const char* street)
{
	SetCity(city);
	SetStreet(street);
}
Address::Address(Address& address)
{
	SetCity(address.city);
	SetStreet(address.street);
}
Address::~Address()
{
	delete[]city;
	delete[]street;
}
void Address::SetCity(const char* _city)
{
	if (city)delete[]city;
	int size = strlen(_city) + 1;
	city = new char[size + 1];
	strcpy_s(city, size, _city);
}
void Address::SetStreet(const char* _street)
{
	if (street)delete[]street;
	int size = strlen(_street) + 1;
	street = new char[size + 1];
	strcpy_s(street, size, _street);
}