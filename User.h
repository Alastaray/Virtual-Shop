#pragma once
#include <iostream>



class User
{
public:
	User(unsigned int id, const char* nickname, const char* password, const char* rank, unsigned int phone);
	User(const User& user);
	~User();
	int GetId() { return id; }
	int GetPhone(){ return phone; }
	char* GetNickname() { return nickname; }
	char* GetPassword() { return password; }
	char* GetRank() { return rank; }

	void SetNickname(const char* _nickname);
	void SetPassword(const char* _password);
	void SetRank(const char* _rank);
	void SetPhone(unsigned int _phone);
protected:
	unsigned id;
	char* nickname,
		* password,
		* rank;	
	long long phone;
};
