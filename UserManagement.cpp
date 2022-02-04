#include "UserManagement.h"






UserManagement::~UserManagement()
{
	users.clear();
}
void UserManagement::AddUser()
{
	Display::cls();
	static int id = 1;
	const int nickname_size = 21,
			  password_size = 16;
	int rank,		
	char nickname [nickname_size],
		 password [password_size];
	bool is_customer;
	std::cout << 
		"0. As employee\n" <<
		"1. As customer\n";
	is_customer = Display::GetNumber(1);
	std::cout << "Enter the your nickname!\n";
	Display::GetStr(nickname_size - 1, nickname);
	std::cout << "Enter the your password!\n";
	Display::GetData(password_size - 1, password);
	if (is_customer)
	{
		std::cout <<
			"Are you VIP?\n" <<
			"0. No\n" <<
			"1. Yes\n";
		rank = Display::GetNumber(1,'1');
	}
	else
	{
		std::cout << 
			"Enter the your rank!\n"<<
			"For example:\n"<<
			"2. Employee\n"<<
			"3. Manager\n"<<
			"4. Director\n";
		rank = Display::GetNumber(1, '4', '2');
	}
	
	users.push_back(new User(id, nickname, password, rank));
	id++;
	std::cout << "Registration Success!\n";
	_getch();
}
void UserManagement::ShowUsers()
{
	Display::cls();
	std::cout <<
		"\nId\t" << "Nickname\t" << "Password\t" << "Rank\n";
	for (int i = 0; i < users.size(); i++)
	{
		std::cout <<
			users[i]->GetId() << "\t" <<
			users[i]->GetNickname() << "\t\t" <<
			users[i]->GetPassword() << "\t\t" <<
			users[i]->GetRank() << "\n";
	}
	_getch();
}