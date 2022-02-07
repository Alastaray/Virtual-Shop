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
	User* GetUserSpentMost();
	std::vector<User*>& GetUsers() { return users; }
	User* GetCurrentUser();
protected:
	std::vector<User*> users;
	int nickname_size,
		password_size,
		current_user;
	bool IsCustomer(const char* rank);
	bool IsUser(const char* nickname);
	
};


