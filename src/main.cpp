// Coffee.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
//#include "List.h"
#include<locale.h>
#include "Product.h"
#include <list>
#include "Automata.h"


int main()
{
setlocale(LC_ALL,"ru");
stdstring path = "List_Product.txt";
std::ifstream fin;
fin.open(path);
std::list<Product> Menu;
if (fin.is_open()) {
std::cout << "Чтение из файла..." << std::endl;
std::string  w1="";
int price = 0;
char ch;
while (fin.get(ch)) {
if (ch != '\n'){
if (ch != ' ') {
if (ch>='А'&&ch<='я') {
 w1 += ch;
} if (ch>='0'&&ch<='9') {
if (price == 0) {
price += (int)ch-48;
} else {
price *= 10;
price += (int)ch-48;
}
}
}				
} else {
Menu.push_back(Product(w1, price));
price = 0;
w1 = "";
}
}
std::cout << "меню установлено" << std::endl;
}
else 
{
std::cout << "Не удалось открыть файл" << std::endl;
}
Automata Coffe(Menu);
Coffe.ON();
Coffe.GetMenu();
int vibor,coin;
std::cin >> coin;
Coffe.coin(coin);
std::cin >> vibor;
Coffe.choice(vibor);
Coffe.coin(1);
Coffe.choice(2);
Coffe.coin(149);
Coffe.choice(2);
std::cout << Coffe.get_State() << std::endl;
fin.close();
}


