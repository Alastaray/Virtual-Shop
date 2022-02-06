#pragma once
#include <vector>
#include "Product.h"
#include "Display.h"

class ProductsManagement
{
public:
	ProductsManagement() = default;
	~ProductsManagement() { products.clear(); }
	void AddProduct();
	void ChangeStatusStock(unsigned id) { Display::DrawProducts(products, true); _getch(); }
	void BuyProduct(User* user);
	int ChangeProductAmount(int index);
protected:
	std::vector<Product*> products;

};

