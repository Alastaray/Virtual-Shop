#pragma once
#include <vector>
#include "RealEstate.h"
#include "Address.h"
#include "Display.h"

class RealEstatesManagement
{
public:
	RealEstatesManagement() = default;
	~RealEstatesManagement() 
	{ 
		DeleteVector(realestates);
		DeleteVector(addresses);
	}
	
protected:
	std::vector<RealEstate*> realestates;
	std::vector<Address*> addresses;

};

