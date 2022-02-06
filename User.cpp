#include "User.h"




User::User(unsigned int id, const char* nickname, const char* password, const char* rank)
{
	this->id = id;
	SetNickname(nickname);
	SetPassword(password);
	SetRank(rank);
}
User::User(const User& user)
{
	this->id = user.id;
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