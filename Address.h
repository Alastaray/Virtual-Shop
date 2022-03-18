#pragma once
#include <iostream>

class Address
{
public:
	Address(const char* city, const char* street);
	Address(const Address& address);
	~Address();
	void SetCity(const char* _city);
	void SetStreet(const char* _street);
	const char* GetCity() { return city; }
	const char* GetStreet() { return street; }
	bool operator==(const Address& address);
private:
	char* city,
		* street;
};


