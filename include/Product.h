// Copyright 2024 Yuri Shalnov
#pragma once
#include <string>



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

