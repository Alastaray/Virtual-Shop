#include "ProductsManagement.h"


void ProductsManagement::AddProduct()
{
	Display::cls();
	static int id = 1;
	const int name_size = 20;
	char* name = new char[name_size];
	std::cout << "Enter the product's name:\n";
	Display::GetStr(name_size, name);
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
	if (user)
	{
		int id,
			amount;
		double purchase_amount = 0,
			   purchase;
		std::vector<Product*> bought_products;			
		while (true)
		{
			Display::DrawProducts(products);
			std::cout << "\nEnter an id for purchase product or 0 for return to menu:\n";
			id = Display::GetNumber(products.size(), (products.size() > 9) ? '9' : products.size() + '0');
			if (!id)break;
			id--;
			if (!products[id]->GetStatusStock())continue;
			amount = ChangeProductAmount(id);
			std::cout << "Product was successfully bought!\n";
			purchase = amount * products[id]->GetPrice();
			purchase_amount += purchase - (purchase * products[id]->GetDiscount());
			bought_products.push_back(products[id]);
			_getch();
		}
		Display::cls();
		if (bought_products.size())
		{
			Display::DrawProducts(bought_products, true);
			std::cout << "\t\t^^^^^^^^^^^^You bought^^^^^^^^^^^^^^\n";
			std::cout << "\nPurchase amount is " << purchase_amount;
			user->SetPurchaseAmount(purchase_amount);
			_getch();
		}	
	}
	else std::cout << "User doen't exist!\n";
	
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