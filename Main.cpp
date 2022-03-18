#include "UsersManagement.h"
#include "RealEstatesManagement.h"

void main()
{
	RealEstatesManagement realestate_management;
	UsersManagement users_management;	
	while (true)
	{
		try
		{
			switch (Display::DrawMainMenu())
			{
			case 1:
				users_management.SignUp();
				break;
			case 2:				
				if (users_management.SignIn())
				{
					int submenu = 1;
					while (submenu != 6)
					{
						try
						{
							submenu = Display::DrawSubMenu();
							switch (submenu)
							{
							case 1:
								users_management.AddNewPublication();
								break;
							case 2:
								users_management.RemovePublication();
								break;
							case 3:
								Display::DrawPublications(users_management.GetUsers());
								_getch();
								break;
							case 4:
								Display::DrawPublications(users_management.GetCurrentUser());
								_getch();
								break;
							case 5:
								users_management.FindPublication();
								break;
							}
						}
						catch (const std::exception& er)
						{
							Display::cls();
							std::cout << er.what();
							_getch();
						}
					}					
				}
				break;
			case 3:
				return;
			}
		}
		catch (const std::exception& er)
		{
			Display::cls();
			std::cout << er.what();
			_getch();
		}	
	}	
}