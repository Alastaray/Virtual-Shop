#pragma once
#include <iostream>
class Product
{
public:
	Product(unsigned int id, const char* name, unsigned price, unsigned amount, double vip_discount);
	Product(const Product& product);
	~Product();
	char* GetName() { return name; }
	int GetId() { return id; }
	int GetAmount() { return amount; }
	int GetPrice() { return price; }
	double GetVipDiscount() { return vip_discount; }
	bool GetStatusStock() { return status_stock; }

	void SetName(const char* _name);
	void SetAmount(unsigned _amount);
	void SetPrice(unsigned _price);
	void SetVipDiscount(double _vip_discount);
	void SetStatusStock(bool is_stock) { status_stock = is_stock; }

	void ChangeAmount(int _amount);
protected:
	char* name;
	int id,
		price,
		amount;
	double vip_discount;
	bool status_stock;
};

