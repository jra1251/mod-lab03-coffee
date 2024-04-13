#include "Product.h"
#include <iostream>

Product::Product(std::string pr, int price) {
product = pr;
Price = price;
}
Product::~Product() {
}

void Product::print() {
std::cout << "|  " << product << "  | "; std::cout << Price << "  |" << std::endl;
}

int Product::get_price() {
return Price;
}

