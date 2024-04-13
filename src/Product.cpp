#include "Product.h"
#include <string>
#include <iostream>


class Product
{
public:
	Product::Product(char name [5], int price)
{
	Price = price;
	Name = name;
}
void Product::Print()
{
	std::cout << "|%10c|%5d" << Name, Price <<;
}
	~Product();
	Product::~Product()
{
}

private:
	int Price;
	char Name[5];

};





