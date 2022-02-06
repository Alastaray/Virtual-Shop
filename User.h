#pragma once
#include <iostream>




class User
{
public:
	User(unsigned int id, const char* nickname, const char* password, const char* rank);
	User(const User& user);
	~User();
	char* GetNickname() { return nickname; }
	char* GetPassword() { return password; }
	char* GetRank() { return rank; }
	int GetId() { return id; }
	void SetNickname(const char* _nickname);
	void SetPassword(const char* _password);
	void SetRank(const char* _rank);
protected:
	char* nickname,
		* password,
		* rank;

	unsigned int id;
};
