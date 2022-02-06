#include "UserManagement.h"
#include "Display.h"

void main()
{
	UserManagement management;
	while (true)
	{
		try
		{
			switch (Display::DrawMainMenu())
			{
			case 0:
				management.SingUp();
				break;
			case 1:				
				switch (management.SingIn())
				{
				case 1:
					break;
				case 2:
					int _case = -1;
					while (_case != 7)
					{
						_case = Display::DrawEmployeeMenu();
						switch (_case)
						{
						case 0:
							management.ShowUsers();
							break;
						case 1:
							management.ShowUsers(true);
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						}
					}					
				}
				break;
			case 2:
				return;
			}
		}
		catch (const std::exception& er)
		{
			Display::cls();
			std::cout<<er.what();
			_getch();
		}
		
	}
	
	
}