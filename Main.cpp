#include "UserManagement.h"
#include "Display.h"

void main()
{
	UserManagement management;
	while (true)
	{
		switch (Display::DrawMainMenu())
		{
		case 0:
			management.AddUser();
			break;
		case 1:
			management.ShowUsers();
			break;
		case 2:
			return;
			break;
		}
	}
	
	
}