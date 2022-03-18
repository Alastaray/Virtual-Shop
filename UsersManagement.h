#pragma once
#include <vector>
#include "User.h"
#include "Display.h"




class UsersManagement
{
public:
	UsersManagement();
	~UsersManagement() { DeleteVector(users); }
	void SignUp();
	int SignIn();
	std::vector<User*>& GetUsers() { return users; }
	User* GetCurrentUser() { return users[current_user]; }
protected:
	std::vector<User*> users;
	int nickname_size,
		password_size,
		current_user;
	bool IsUser(const char* nickname);
	
};


