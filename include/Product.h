#pragma once
#include <string>
#include <string>
using namespace std;

class Product {
private:
std::string product;
int Price;
public:
Product(std::string pr, int price);
~Product();
void print();
int get_price();	
};

