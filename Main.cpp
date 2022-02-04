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
			management.SingUp();
			break;
		case 1:
			switch (management.SingIn())
			{
			case 1:
				break;
			case 2:
				break;
			}
			break;
		case 2:
			return;
			break;
		}
	}
	
	
}