#include "UsersManagement.h"
#include "RealEstatesManagement.h"

void main()
{
	UsersManagement users_management;
	RealEstatesManagement realestate_management;
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
							{
								RealEstate* real_estate = realestate_management.AddRealEstate();
								users_management.GetCurrentUser()->AddPublication(real_estate);
							}								
								break;
							case 2:
								break;
							case 3:
								Display::DrawPublications(users_management.GetUsers());
								break;
							case 4:
								Display::DrawPublications(users_management.GetCurrentUser());
							case 5:
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