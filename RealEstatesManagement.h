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
	RealEstate* AddRealEstate();
protected:
	std::vector<RealEstate*> real_estates;
	std::vector<Address*> addresses;
};

