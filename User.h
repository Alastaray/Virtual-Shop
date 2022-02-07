#pragma once
#include <iostream>

namespace UserRanks
{
	enum UserRankNumbers
	{
		NoVip,
		Vip,
		Employee,
		Manager,
		Director
	};

	inline const char* GetNoVip() { return ""; }
	inline const char* GetVip() { return "Vip"; }
	inline const char* GetEmployee() { return "Employee"; }
	inline const char* GetManager() { return "Manager"; }
	inline const char* GetDirector() { return "Director"; }

	const double employee_discount = 0.1;
	const double manager_discount = 0.2;
	const double director_discount = 0.3;

	int RankToInt(const char* rank);
	const char* IntToRank(int rank);
	double RankToDiscont(const char* rank);
}


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
	double GetPurchaseAmount() { return purchase_amount; }
	void SetNickname(const char* _nickname);
	void SetPassword(const char* _password);
	void SetRank(const char* _rank);
	void SetPurchaseAmount(double _purchase_amount);
protected:
	char* nickname,
		* password,
		* rank;
	unsigned id;
	double purchase_amount;
};
