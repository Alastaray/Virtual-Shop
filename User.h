#pragma once
#include <iostream>
#include <vector>
#include "RealEstate.h"

class User
{
public:
	User(unsigned int id, const char* nickname, const char* password, const char* rank, int limit_publications);
	User(const User& user);
	~User();
	int GetId() { return id; }
	int GetLimitPublications() { return limit_publications; }
	char* GetNickname() { return nickname; }
	char* GetPassword() { return password; }
	char* GetRank() { return rank; }
	std::vector<RealEstate*>& GetPublications() { return publications; }

	void SetNickname(const char* _nickname);
	void SetPassword(const char* _password);
	void SetRank(const char* _rank);
	void AddPublication(RealEstate* real_estate){ publications.push_back(real_estate); }
	void SetLimitPublications(unsigned _publications_max) { limit_publications = _publications_max; }
protected:
	unsigned id;
	int limit_publications;
	char* nickname,
		* password,
		* rank;	
	std::vector<RealEstate*> publications;
};
