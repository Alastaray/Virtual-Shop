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
	}
	~UserManagement(){ users.clear(); }
	void SingUp();
	int SingIn();
	void ShowUsers();
protected:
	std::vector<User*> users;
	int nickname_size,
		password_size;
};

