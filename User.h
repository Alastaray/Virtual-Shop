#pragma once
#include <iostream>
#include <vector>
#include "RealEstate.h"

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
	std::vector<RealEstate*>& GetPublications() { return publications; }

	void SetNickname(const char* _nickname);
	void SetPassword(const char* _password);
	void SetRank(const char* _rank);
	void SetPhone(unsigned int _phone);
	void AddPublication(RealEstate* real_estate){ publications.push_back(real_estate); }
protected:
	unsigned id;
	char* nickname,
		* password,
		* rank;	
	long long phone;
	std::vector<RealEstate*> publications;
};
