#pragma once
#include <iostream>
class RealEstate
{
public:
	RealEstate(unsigned int id, const char* name, unsigned price, unsigned amount_rooms, unsigned floor);
	RealEstate(unsigned int id, const char* name, unsigned price, unsigned amount_rooms);
	RealEstate(const RealEstate& realestate);
	~RealEstate();
	char* GetName() { return name; }
	int GetId() { return id; }
	int GetAmountRooms() { return amount_rooms; }
	int GetPrice() { return price; }
	int GetFloor() { return floor; }

	void SetName(const char* _name);
	void SetAmountRooms(unsigned _amount_rooms);
	void SetPrice(unsigned _price);
	void SetFloor(unsigned _floor);
protected:
	char* name;
	int id,
		price,
		amount_rooms,
		floor;

};

