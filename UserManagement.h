#pragma once
#include <vector>
#include "User.h"
#include "Display.h"

class UserManagement
{
public:
	UserManagement() = default;
	~UserManagement();
	void AddUser();
	void ShowUsers();
protected:
	std::vector<User*> users;
};

