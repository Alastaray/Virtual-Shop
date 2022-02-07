#pragma once
#include <vector>
#include "Product.h"
#include "Display.h"

class ProductsManagement
{
public:
	ProductsManagement() = default;
	~ProductsManagement() { DeleteVector(products); }
	void AddProduct();
	void ChangeStatusStock(unsigned id) { Display::DrawProduct(products, true); _getch(); }
	void BuyProduct(User* user);
	int ChangeProductAmount(int index);
	bool AreProductsStock();
protected:
	std::vector<Product*> products;
	bool IsProduct(const char* name);
};

