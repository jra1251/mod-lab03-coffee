#include "Automata.h"
bool Automata::Check(int selection)
{
	int count = 0;
	list<Product>::iterator i;
	i = Menu.begin();
	advance(i, selection - 1);
	if (cash >= (*i).get_price()) {
		return true;
	} else {
		cout << "Недостаточно денег" << endl;
		state = accept;
		return false;
	}
}
void Automata::Cook(int selection)
{
	if (state == check) {
		state = cook;
		list<Product>::iterator i;
		i = Menu.begin();
		advance(i, selection - 1);
		cash -= (*i).get_price();
		std::cout << "Ваш напиток готовится"
			<< std::endl;
		Finish(selection);
	}
	else {
		std::cout << "Операция невозможна" << std::endl;
	}
}

void Automata::Finish(int selection)
{
	if (state == cook) {
		std::cout << "Сдача: " << cash << std::endl;
		std::cout << "Вот ваш напиток" << std::endl;
		cash = 0;
		state = wait;
	}
	else {
		std::cout << "Операция невозможна" << std::endl;
	}
}
Automata::Automata(list<Product>menu)
{
	Menu = menu;
	state = off;
}

Automata::~Automata()
{
}

void Automata::ON()
{
	if (state == off)
	{
		state = wait;
		cout << "Кофемашина включена" << endl;
	}
	else {
		cout << "Кофемашина уже включена" << endl;
	}
	
}

void Automata::GetMenu()
{
	if (state == wait) {
		cout << " |   Название  | цена |" << endl;
		list<Product>::iterator i;
		int count = 0;
		for (i = Menu.begin(); i != Menu.end(); i++) {
			cout << count + 1;
			(*i).print();
			count++;
		}
	}
}

void Automata::OFF()
{
	if (state == wait) {
		state = off;
		cout << "Кофемашина отключена" << endl;
	} else {
		cout << "Операция не возможна" << endl;
	}
}

States Automata::get_State()
{
	return state;
}

void Automata::coin(int money)
{
	if (state == wait || state == accept) {
		state = accept;
		cash += money;
		std::cout << "Деньги:" << cash << std::endl;
	}
	else {
		std::cout << "Операция невозможна" << std::endl;
	}
}

void Automata::choice(int vibor)
{
	if (state == accept) {
		if (vibor<1 || vibor>Menu.size()) {
			cout << "Выбор некорректен" << endl;
		} else {
			state = check;
			if (Check(vibor)) {
				Cook(vibor);
			}
		}
	}else {
		cout << "Операция не возможна" << endl;
	}
}

void Automata::cancel()
{
	if (state == accept || state == check) {
		state = wait;
		cash = 0;
		std::cout << "Омена " << std::endl;
	}
	else {
		std::cout << "Wrong transition!" << std::endl;
	}
}

