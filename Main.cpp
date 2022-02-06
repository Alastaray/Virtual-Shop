#include "UserManagement.h"
#include "ProductsManagement.h"
#include "Display.h"

void main()
{
	std::cout.setf(std::ios::boolalpha);
	UsersManagement users_management;
	ProductsManagement products_management;
	while (true)
	{
		try
		{
			switch (Display::DrawMainMenu())
			{
			case 0:
				users_management.SignUp();
				break;
			case 1:				
				switch (users_management.SignIn())
				{
				case 1:
					products_management.BuyProduct(users_management.GetCurrentUser());
					break;
				case 2:
					int _case = -1;
					while (_case != 7)
					{
						_case = Display::DrawEmployeeMenu();
						switch (_case)
						{
						case 0:
							users_management.ShowUsers();
							break;
						case 1:
							users_management.ShowUsers(true);
							break;
						case 2:
							users_management.ShowUsers(0, true);
							break;
						case 3:
							users_management.ShowUserSpentMost();
							break;
						case 4:
							products_management.AddProduct();
							break;
						case 5:
							products_management.ChangeStatusStock(3);
							break;
						case 6:
							products_management.BuyProduct(users_management.GetCurrentUser());
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