// Copyright 2024 Yuri Shalnov
#pragma once
#include "Product.h"
#include <list>
#include <iostream>
#include<string>


enum States {
on, off, coin, choise, check, cancel, cook, finish, wait, accept
};

class Automata {
 private:
    std::list<Product>Menu;
    States state;
    int cash;
    bool Check(int);
    void Cook(int);
    void Finish(int);

 public:
    explicit Automata(std::list<Product>);
    ~Automata();
    void ON();
    void GetMenu();
    void OFF();
    States get_State();
    void coin(int);
    void choice(int);
    void cancel();
};

