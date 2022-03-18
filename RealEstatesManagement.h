#pragma once
#include <fstream>
#include "RealEstate.h"
#include "Display.h"
#pragma warning(disable: 4996)


class RealEstatesManagement
{
public:
	RealEstatesManagement();
	~RealEstatesManagement();
	void SetAddresses();
	RealEstate* CreateRealEstate();
	Address* GetLocation(int str_size);
protected:
	std::vector<Address*> addresses;
};

