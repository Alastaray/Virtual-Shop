#pragma once
#include <vector>
#include "User.h"
#include "Display.h"




class UsersManagement
{
public:
	UsersManagement();
	~UsersManagement(){ users.clear(); }
	void SignUp();
	int SignIn();
	void ShowUsers(bool is_vip = false, bool have_purchase = false);
	void ShowUserSpentMost();
	User* GetCurrentUser();
protected:
	std::vector<User*> users;
	std::string user_ranks[5];
	int nickname_size,
		password_size,
		current_user;
	enum UserRankNumbers
	{
		NoVip,
		Vip,
		Employee,
		Manager,
		Director
	};
	bool IsCustomer(const char* rank);
	bool IsUser(const char* nickname);
	
};


