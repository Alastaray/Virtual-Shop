#pragma once
#include <vector>
#include "User.h"
#include "Display.h"
#include "RealEstatesManagement.h"




class UsersManagement
{
public:
	UsersManagement();
	~UsersManagement();
	void SignUp();
	bool SignIn();
	std::vector<User*>& GetUsers() { return users; }
	User* GetCurrentUser() { return users[current_user]; }
	void RemovePublication();
	void AddNewPublication();
	void FindPublication();
	bool IsUser(const char* nickname);
protected:
	RealEstatesManagement* realestate_management;
	std::vector<User*> users;
	int nickname_size,
		password_size,
		current_user;
	
};


