#include "UserManagement.h"




UsersManagement::UsersManagement()
{
	nickname_size = 21;
	password_size = 16;
	current_user = 0;
	user_ranks[NoVip] = "";
	user_ranks[Vip] = "Vip";
	user_ranks[Employee] = "Employee";
	user_ranks[Manager] = "Manager";
	user_ranks[Director] = "Director";
}
void UsersManagement::SignUp()
{
	Display::cls();
	static int id = 1;
	int rank;
	bool is_customer;
	std::pair<const char*, const char*> user_data;
	std::cout << 
		"\n\t0. As employee\n" <<
		"\t1. As customer\n";
	is_customer = Display::GetNumber(1);
	while (true)
	{
		user_data = Display::DrawLoginMenu(nickname_size, password_size);
		if (!IsUser(user_data.first))break;
		else std::cout << "This nickname is taken!\n";
	}
	
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
			"\t2. " + user_ranks[Employee] + "\n" << 
			"\t3. " + user_ranks[Manager] + "\n"<<
			"\t4. " + user_ranks[Director] + "\n";
		rank = Display::GetNumber(1, '4', '2');
	}
	
	users.push_back(new User(id, user_data.first, user_data.second, user_ranks[rank].c_str()));
	id++;
	std::cout << "Registration Success!\n";
	delete[]user_data.first;
	delete[]user_data.second;
	_getch();
}
int UsersManagement::SignIn()
{
	Display::cls();
	if (users.size())
	{
		std::pair<const char*, const char*> user_data = Display::DrawLoginMenu(nickname_size, password_size);
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
			current_user = i;
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
void UsersManagement::ShowUsers(bool is_vip, bool have_purchase)
{
	Display::cls();
	std::cout <<
		"\n\tId\t" << "Nickname\t" << "Password\t"<<"Purchase Amount\t" << "Rank\n";
	for (size_t i = 0; i < users.size(); i++)
	{
		if (is_vip)
		{
			if (!strcmp(users[i]->GetRank(), user_ranks[Vip].c_str()))
				Display::DrawUser(users, i);
		}
		else if (have_purchase)
		{
			if (users[i]->GetPurchaseAmount())
				Display::DrawUser(users, i);
		}
		else
			Display::DrawUser(users, i);
	}
	_getch();
}
void UsersManagement::ShowUserSpentMost()
{
	Display::cls();
	if (users.size())
	{
		std::cout << "\n";
		int max = 0,
			index_max = 0;
		for (size_t i = 0; i < users.size(); i++)
		{
			if (users[i]->GetPurchaseAmount() > 0)
			{
				max = users[i]->GetPurchaseAmount();
				index_max = i;
			}
		}
		Display::DrawUser(users, index_max);
	}
	else std::cout<< "No one hasn't bought something yet!\n";
	_getch();
}
User* UsersManagement::GetCurrentUser()
{
	if (users.size())return users[current_user];
	return 0;	
}
bool UsersManagement::IsCustomer(const char* rank)
{
	if (!strcmp(rank, user_ranks[NoVip].c_str()) || !strcmp(rank, user_ranks[Vip].c_str()))
		return true;
	return false;
}
bool UsersManagement::IsUser(const char* nickname)
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if (!strcmp(users[i]->GetNickname(), nickname))
			return true;
	}
	return false;
}
