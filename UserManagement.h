#pragma once
#include <vector>
#include "User.h"
#include "Display.h"

class UserManagement
{
public:
	UserManagement()
	{
		nickname_size = 21;
		password_size = 16;
		ranks[NoVip] = "";
		ranks[Vip] = "Vip";
		ranks[Employee] = "Employee";
		ranks[Manager] = "Manager";
		ranks[Director] = "Director";
	}
	~UserManagement(){ users.clear(); }
	void SingUp();
	int SingIn();
	void ShowUsers(bool vip = false);
protected:
	std::vector<User*> users;
	std::string ranks[5];
	int nickname_size,
		password_size;
	enum Ranks
	{
		NoVip,
		Vip,
		Employee,
		Manager,
		Director
	};
	bool IsCustomer(const char* rank);
	
};

