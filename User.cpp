#include "User.h"



namespace UserRanks
{
	int RankToInt(const char* rank)
	{
		if (!strcmp(rank, GetEmployee()))return Employee;
		if (!strcmp(rank, GetManager()))return Manager;
		if (!strcmp(rank, GetDirector()))return Director;
		if (!strcmp(rank, GetVip()))return Vip;
		return NoVip;
	}
	const char* IntToRank(int rank)
	{
		switch (rank)
		{
		case Vip: return GetVip();
		case Employee:	return GetEmployee();
		case Manager: return GetManager();
		case Director:	return GetDirector();
		}
		return GetNoVip();
	}
	double RankToDiscont(const char* rank)
	{
		if (!strcmp(rank, GetEmployee()))return employee_discount;
		if (!strcmp(rank, GetManager()))return manager_discount;
		if (!strcmp(rank, GetDirector()))return director_discount;
		if (!strcmp(rank, GetVip()))return -1;
		return 0;
	}
}

User::User(unsigned int id, const char* nickname, const char* password, const char* rank)
{
	this->id = id;
	this->purchase_amount = 0;
	SetNickname(nickname);
	SetPassword(password);
	SetRank(rank);
}
User::User(const User& user)
{
	this->id = user.id;
	this->purchase_amount = user.purchase_amount;
	SetNickname(user.nickname);
	SetPassword(user.password);
	SetRank(user.rank);
}
User::~User()
{
	delete[]nickname;
	delete[]password;
}
void User::SetNickname(const char* _nickname)
{
	if (nickname)delete[]nickname;
	int size = strlen(_nickname) + 1;
	nickname = new char[size + 1];
	strcpy_s(nickname, size,_nickname);
}
void User::SetPassword(const char* _password)
{
	if (password)delete[]password;
	int size = strlen(_password) + 1;
	password = new char[size + 1];
	strcpy_s(password, size, _password);
}
void User::SetRank(const char* _rank)
{
	if (rank)delete[]rank;
	int size = strlen(_rank) + 1;
	rank = new char[size + 1];
	strcpy_s(rank, size, _rank);
}
void User::SetPurchaseAmount(double _purchase_amount)
{
	if (_purchase_amount)
		purchase_amount += _purchase_amount;
}