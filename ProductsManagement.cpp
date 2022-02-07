#include "ProductsManagement.h"


void ProductsManagement::AddProduct()
{
	Display::cls();
	static int id = 1;
	const int name_size = 20;
	char* name = new char[name_size];
	while (true)
	{
		std::cout << "Enter the product's name:\n";
		Display::GetStr(name_size, name);
		if (!IsProduct(name))break;
		else std::cout << "This product has already added!\n";
	}	
	std::cout << "Enter the product's price:\n";
	int price = Display::GetNumber(6);
	std::cout << "Enter the product's amount:\n";
	int	amount = Display::GetNumber(3);
	std::cout << "Enter the product's discount for the vip users (in %):\n";
	double discount = Display::GetNumber(2)*1.0/100;
	products.push_back(new Product(id, name, price, amount, discount));
	id++;
	std::cout << "Product was successfully added!\n";
	_getch();
}
void ProductsManagement::BuyProduct(User* user)
{
	if (AreProductsStock())
	{
		if (user)
		{
			int id = 1,
				purchase,
				amount;
			double purchase_amount = 0,
				discount = UserRanks::RankToDiscont(user->GetRank());
			std::vector<Product*> bought_products;
			while (true)
			{
				Display::DrawProduct(products);
				std::cout << "\nEnter an id for purchase product or 0 for return to menu:\n";
				id = RequestProductId();
				if (!id)break;
				id--;

				if (!products[id]->GetStatusStock())continue;
				amount = ChangeProductAmount(id);

				
				if (discount == -1)discount = products[id]->GetVipDiscount();

				purchase = amount * products[id]->GetPrice();
				purchase_amount += purchase - (purchase * discount);

				bought_products.push_back(new Product(*products[id]));
				bought_products.back()->SetAmount(amount);
				std::cout << "Product was successfully bought!\n";
				_getch();
			}
			Display::DrawShoppingBasket(bought_products, purchase_amount);
			user->SetPurchaseAmount(purchase_amount);
			DeleteVector(bought_products);
		}
		else
		{
			Display::cls();
			std::cout << "User doesn't exist!\n";
			_getch();
		}
	}
	else
	{
		Display::cls();
		std::cout << "Products are out of stock!\n";
		_getch();
	}
}
void ProductsManagement::ChangeProductStatus()
{
	int id = 1,
		amount;
	bool status,
		error = false;
	while (true)
	{
		Display::DrawProduct(products, true);
		std::cout << "\nEnter an id for change product's status or 0 for return to menu:\n";
		id = RequestProductId();
		if (!id)break;
		id--;

		std::cout <<
			"0. Product is out of stock\n"<<
			"1. Product is in of stock\n";
		status = Display::GetNumber(1, '1');
		if (status)
		{
			if (!products[id]->GetStatusStock())
			{
				std::cout << "Enter the product's amount:\n";
				amount = Display::GetNumber(3);
				products[id]->ChangeAmount(amount);
				products[id]->SetStatusStock(status);
			}
			else error = true;				
		}
		else
		{
			if (products[id]->GetStatusStock())
				products[id]->ChangeAmount(-products[id]->GetAmount());
			else error = true;
		}
		if(error)
		{
			error = false;
			std::cout << "You can't change status if it has already set!\n";
			_getch();
			continue;
		}
		std::cout << "Product's status was successfully changed!\n";
		_getch();
	}
	
}
int ProductsManagement::ChangeProductAmount(int index)
{
	int amount;
	std::cout << "Enter the product's amount:\n";
	amount = Display::GetNumber(3, (products[index]->GetAmount() > 9) ? Display::Nine : products[index]->GetAmount() + Display::Zero);
	if (amount >= products[index]->GetAmount())
	{
		amount = products[index]->GetAmount();
		products[index]->ChangeAmount(-amount);
	}
	else products[index]->ChangeAmount(-amount);
	return amount;
}
bool ProductsManagement::AreProductsStock()
{
	if (products.size())
	{
		for (size_t i = 0; i < products.size(); i++)
		{
			if (!products[i]->GetStatusStock())return false;
		}
		return true;
	}
	else
		return false;
}
bool ProductsManagement::IsProduct(const char* name)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (!strcmp(products[i]->GetName(), name))
			return true;
	}
	return false;
}
int ProductsManagement::RequestProductId()
{
	char number = (products.size() > 9) ? Display::Nine : products.size() + Display::Zero;
	return Display::GetNumber(products.size(), number);
}