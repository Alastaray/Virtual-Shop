#include "RealEstate.h"



RealEstate::RealEstate(unsigned int id, Address* address, const char* name, unsigned price, unsigned amount_rooms, unsigned floor)
{
	this->id = id;
	SetName(name);
	SetAmountRooms(amount_rooms);
	SetPrice(price);
	SetFloor(floor);
	SetAddress(address->GetCity(), address->GetStreet());
}
RealEstate::RealEstate(const RealEstate& realestate)
{
	this->id = realestate.id;
	SetName(realestate.name);
	SetAmountRooms(realestate.amount_rooms);
	SetPrice(realestate.price);
}
RealEstate::~RealEstate()
{
	delete[]name;
	delete address;
}
void RealEstate::SetName(const char* _name)
{
	if (name)delete[]name;
	int size = strlen(_name) + 1;
	name = new char[size + 1];
	strcpy_s(name, size, _name);
}
void RealEstate::SetAmountRooms(unsigned _amount_rooms)
{
	if (_amount_rooms)amount_rooms = _amount_rooms;
}
void RealEstate::SetPrice(unsigned _price)
{
	if (_price)price = _price;
}
void RealEstate::SetFloor(unsigned _floor)
{
	floor = _floor;
}
void RealEstate::SetAddress(const char* city, const char* street)
{
	if (address)delete address;
	address = new Address(city, street);
}