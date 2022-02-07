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
			int id,
				purchase,
				amount;
			double purchase_amount = 0,
				discount = UserRanks::RankToDiscont(user->GetRank());
			std::vector<Product*> bought_products;
			while (true)
			{
				Display::DrawProduct(products);
				std::cout << "\nEnter an id for purchase product or 0 for return to menu:\n";
				id = Display::GetNumber(products.size(), (products.size() > 9) ? Display::Nine : products.size() + Display::Zero);
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
		else std::cout << "User doen't exist!\n";
	}
	else std::cout << "Product is out of stock!\n";
}
int ProductsManagement::ChangeProductAmount(int index)
{
	int amount;
	std::cout << "Enter the product's amount:\n";
	amount = Display::GetNumber(3, (products[index]->GetAmount() > 9) ? '9' : products[index]->GetAmount() + '0');
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