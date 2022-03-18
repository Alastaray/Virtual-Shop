#include "Product.h"



Product::Product(unsigned int id, const char* name, unsigned price, unsigned amount, double vip_discount)
{
	this->id = id;
	this->status_stock = true;
	SetName(name);
	SetAmount(amount);
	SetPrice(price);
	SetVipDiscount(vip_discount);
}
Product::Product(const Product& product)
{
	this->id = product.id;
	this->status_stock = product.status_stock;
	SetName(product.name);
	SetAmount(product.amount);
	SetPrice(product.price);
	SetVipDiscount(product.vip_discount);
}
Product::~Product()
{
	delete[]name;
}
void Product::SetName(const char* _name)
{
	if (name)delete[]name;
	int size = strlen(_name) + 1;
	name = new char[size + 1];
	strcpy_s(name, size, _name);
}
void Product::SetAmount(unsigned _amount)
{
	if (_amount)amount = _amount;
}
void Product::SetPrice(unsigned _price)
{
	if (_price)price = _price;
}
void Product::SetVipDiscount(double _vip_discount)
{
	if (_vip_discount >= 1 || _vip_discount <= 0)vip_discount = 0;
	else vip_discount = _vip_discount;
}
void Product::ChangeAmount(int _amount)
{
	amount += _amount;
	if (amount <= 0)
	{
		status_stock = false;
		amount = 0;
	}
}