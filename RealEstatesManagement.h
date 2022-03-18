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
	void AddRealEstate();
protected:
	std::vector<RealEstate*> realestates;
	std::vector<Address*> addresses;

};

