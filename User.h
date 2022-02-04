#pragma once
#include <iostream>




class User
{
public:
	User(unsigned int id, const char* nickname, const char* password, unsigned int rank);
	User(const User& user);
	~User();
	char* GetNickname() { return nickname; }
	char* GetPassword() { return password; }
	int GetRank() { return rank; }
	int GetId() { return id; }
	void SetNickname(const char* _nickname);
	void SetPassword(const char* _password);
	void SetRank(unsigned int _rank);
protected:
	char *nickname,
		 *password;
	unsigned int id,
				rank;
};
