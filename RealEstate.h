#pragma once
#include <iostream>
#include "Address.h"
class RealEstate
{
public:
	RealEstate(unsigned int id, Address* address, const char* name, unsigned price, unsigned amount_rooms, unsigned floor);	
	RealEstate(const RealEstate& realestate);
	~RealEstate();
	char* GetName() { return name; }
	int GetId() { return id; }
	int GetAmountRooms() { return amount_rooms; }
	int GetPrice() { return price; }
	int GetFloor() { return floor; }
	Address* GetAddress() { return address; }

	void SetName(const char* _name);
	void SetAmountRooms(unsigned _amount_rooms);
	void SetPrice(unsigned _price);
	void SetFloor(unsigned _floor);
	void SetAddress(const char* city, const char* street);
protected:
	char* name;
	int id,
		price,
		amount_rooms,
		floor;
	Address* address;

};

