#include "UsersManagement.h"




UsersManagement::UsersManagement()
{
	nickname_size = 21;
	password_size = 16;
	current_user = 0;
}
void UsersManagement::SignUp()
{
	Display::cls();
	static int id = 1;
	int phone;
	char* rank;
	bool is_customer;
	const char broker[] = "broker";
	const char user[] = "user";
	std::pair<const char*, const char*> user_data;
	std::cout << 
		"\n\t0. I am "<< broker <<"\n" <<
		"\t1. I am " << user << "\n";
	is_customer = Display::GetNumber(1);
	while (true)
	{
		user_data = Display::DrawLoginMenu(nickname_size, password_size);
		if (!IsUser(user_data.first))break;
		else std::cout << "This nickname is taken!\n";
	}
	std::cout << "Enter your phone\n";
	phone = Display::GetNumber(10);
	if (is_customer)
	{
		int size = strlen(user)+1;
		rank = new char[size + 1];
		strcpy_s(rank, size, user);
	}
	else
	{
		int size = strlen(broker);
		rank = new char[size + 1];
		strcpy_s(rank, size, broker);
	}

	
	users.push_back(new User(id, user_data.first, user_data.second, rank, phone));
	id++;
	std::cout << "Registration Success!\n";
	delete[]user_data.first;
	delete[]user_data.second;
	delete[]rank;
	_getch();
}
bool UsersManagement::SignIn()
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
			current_user = i;
			return true;
		}
		else
			std::cout << "Nickname or password is wrong!\n";				
	}
	else
		std::cout << "No one hasn't registration yet!\n";	
	_getch();
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
