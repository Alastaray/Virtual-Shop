#include "UsersManagement.h"




UsersManagement::UsersManagement()
{
	realestate_management = new RealEstatesManagement();
	nickname_size = 21;
	password_size = 16;
	current_user = 0;
}
UsersManagement::~UsersManagement() 
{
	DeleteVector(users); 
	delete realestate_management;
}
void UsersManagement::SignUp()
{
	Display::cls();
	static int id = 1;
	int limit_publications;
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
	if (is_customer)
	{
		size_t size = strlen(user)+1;
		rank = new char[size + 1];
		strcpy_s(rank, size, user);
		limit_publications = 3;
	}
	else
	{
		size_t size = strlen(broker)+1;
		rank = new char[size + 1];
		strcpy_s(rank, size, broker);
		limit_publications = 10;
	}

	users.push_back(new User(id, user_data.first, user_data.second, rank, limit_publications));
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
void UsersManagement::RemovePublication()
{
	User* current_user = GetCurrentUser();
	decltype(auto) publications = current_user->GetPublications();
	Display::DrawPublications(current_user);
	std::cout << "\nEnter the real estate name\n";
	int size_str = 30;
	char* name = new char[size_str];
	bool flag = false;
	while (!flag)
	{
		Display::GetStr(size_str, name);
		for (auto i = publications.begin(); i < publications.end(); i++)
		{
			if (!strcmp(name, (*i)->GetName()))
			{
				delete* i;
				publications.erase(i);
				break;
			}
		}
		if (!flag)std::cout << "Incorrect name!\n";
	}
	std::cout << "Successfully deleting!\n";
	_getch();
}
void UsersManagement::AddNewPublication()
{
	if (GetCurrentUser()->GetPublications().size() < GetCurrentUser()->GetLimitPublications())
	{
		RealEstate* real_estate = realestate_management->CreateRealEstate();
		GetCurrentUser()->AddPublication(real_estate);
		std::cout << "Real estate successfully added!\n";
	}
	else
		std::cout << "You can't exceed the limit of publication!\n";
	_getch();
}
void UsersManagement::FindPublication()
{
	const int str_size = 30;
	Address* address = realestate_management->GetLocation(str_size);
	for (auto user : users)
	{
		decltype(auto) publications = user->GetPublications();
		for (int i = 0; i < publications.size(); i++)
		{
			if (*address == *publications[i]->GetAddress())
			{
				Display::DrawRealEstate(publications[i]);
				Display::DrawUserInfo(user);
				std::cout << "\n";
			}
		}
	}
	delete address;
	_getch();
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