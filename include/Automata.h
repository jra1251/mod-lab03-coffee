//Copyrihgt 2024 Shalnov Yuri
#pragma once
#include "Product.h"
#include <list>
#include <iostream>
using namespace std;

enum States {
on, off, coin, choise, check, cancel, cook, finish, wait, accept
};

class Automata {
private :
list<Product>Menu;
States state;
int cash;
bool Check(int);
void Cook(int);
void Finish(int);

public :
Automata(list<Product>); 
~Automata();
void ON();
void GetMenu();
void OFF();
States get_State();
void coin(int);
void choice(int);
void cancel();
};

