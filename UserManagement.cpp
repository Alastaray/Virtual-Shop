#include "UserManagement.h"






void UserManagement::SingUp()
{
	Display::cls();
	static int id = 1;
	int rank;
	bool is_customer;
	std::cout << 
		"\n\t0. As employee\n" <<
		"\t1. As customer\n";
	is_customer = Display::GetNumber(1);
	std::pair<const char*, const char*> user_data = Display::DrawEnterMenu(nickname_size, password_size);
	if (is_customer)
	{
		std::cout <<
			"\tAre you VIP?\n" <<
			"\t0. No\n" <<
			"\t1. Yes\n";
		rank = Display::GetNumber(1,'1');
	}
	else
	{
		std::cout <<
			"\tEnter the your rank!\n" <<
			"\tFor example:\n" <<
			"\t2. " + ranks[Employee] + "\n" << 
			"\t3. " + ranks[Manager] + "\n"<<
			"\t4. " + ranks[Director] + "\n";
		rank = Display::GetNumber(1, '4', '2');
	}
	
	users.push_back(new User(id, user_data.first, user_data.second, ranks[rank].c_str()));
	id++;
	std::cout << "Registration Success!\n";
	delete[]user_data.first;
	delete[]user_data.second;
	_getch();
}
int UserManagement::SingIn()
{
	Display::cls();
	if (users.size())
	{
		std::pair<const char*, const char*> user_data = Display::DrawEnterMenu(nickname_size, password_size);
		bool registered = false;
		size_t i = 0;
		for (; i < users.size(); i++)
		{
			if (!std::strcmp(user_data.first, users[i]->GetNickname()) &&
				!std::strcmp(user_data.second, users[i]->GetPassword()))
			{
				registered = true;
				break;
			}
		}
		delete[]user_data.first;
		delete[]user_data.second;
		if (registered)
		{
			std::cout << "Hello, " << users[i]->GetNickname()<<" ("<< users[i]->GetRank() <<")";
			_getch();
			if (IsCustomer(users[i]->GetRank()))return 1;
			else return 2;		
		}
		else
		{
			std::cout << "Nickname or password is wrong!\n";
			_getch();
			return false;
		}					
	}
	else
		std::cout << "No one hasn't registration yet!\n";
	_getch();
	return false;
}
void UserManagement::ShowUsers(bool vip)
{
	Display::cls();
	std::cout <<
		"\n\tId\t" << "Nickname\t" << "Password\t"<<"Rank\n";
	int rank;
	for (size_t i = 0; i < users.size(); i++)
	{
		std::cout << "\t" <<
			users[i]->GetId() << "\t" <<
			users[i]->GetNickname() << "\t\t" <<
			users[i]->GetPassword() << "\t\t"<<
			users[i]->GetRank() << "\n";
	}
	_getch();
}
bool UserManagement::IsCustomer(const char* rank)
{
	if (!strcmp(rank, ranks[NoVip].c_str()) || !strcmp(rank, ranks[Vip].c_str()))
		return true;
	return false;
}