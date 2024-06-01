// Copyright 2024 Yuri Shalnov
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Automata {
public:
    Automata();
    enum State {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    void on();
    void off();
    void coin(int money);
    void printMenu();
    void choice(int item);
    void cancel();
    void cook();
    void finish();
    Automata::State getState();
    int getCash();

private:
    State state;
    vector<string> menu;
    vector<int> prices;
    int cash;
    int choice_;
    int current_price;
};

#endif #pragma once

