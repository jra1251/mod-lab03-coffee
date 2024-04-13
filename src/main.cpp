// Coffee.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
//#include "List.h"
#include<locale.h>
#include "Product.h"
#include <list>
#include "Automata.h"
using namespace std;

int main()
{
setlocale(LC_ALL,"ru");
string path = "List_Product.txt";
ifstream fin;
fin.open(path);
list<Product> Menu;
if (fin.is_open()) {
std::cout << "Чтение из файла..." << std::endl;
string  w1="";
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
cout << "меню установлено" << endl;
}
else 
{
std::cout << "Не удалось открыть файл" << std::endl;
}
Automata Coffe(Menu);
Coffe.ON();
Coffe.GetMenu();
int vibor,coin;
cin >> coin;
Coffe.coin(coin);
	
	cin >> vibor;
	Coffe.choice(vibor);

	Coffe.coin(1);
	Coffe.choice(2);
	Coffe.coin(149);
	Coffe.choice(2);
	cout << Coffe.get_State() << endl;

	fin.close();
}


