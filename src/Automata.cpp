// Copyright 2024 Yuri Shalnov
#include "Automata.h"

Automata::Automata() {
    state = OFF;
    cash = 0;
    menu = { "Water", "Tea", "Coffee", "Juice" };
    prices = { 10, 15, 20, 25 };
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "Automata is on\n";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        cout << "Automata is off\n";
    } else if (state == ACCEPT) {
        cancel();
        state = OFF;
        cout << "Automata is off\n";
    } else {
        cout << "Can't turn off the automata in this state\n";
    }
}

void Automata::coin(int money) {
    if (state == ACCEPT || state == WAIT) {
        cash += money;
        state = ACCEPT;
        cout << "Cash added: " << money << "\n";
    }
    else {
        cout << "Can't add cash in this state\n";
    }
}

void Automata::printMenu() {
    if (state == WAIT) {
        cout << "Menu:\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << " - " << prices[i] << "\n";
        }
    }
    else {
        cout << "Can't print menu in this state\n";
    }
}

void Automata::choice(int item) {
    if (state == ACCEPT) {
        if (item >= 1 && item <= menu.size()) {
            choice_ = item - 1;
            current_price = prices[choice_];
            state = CHECK;
            cout << "Choice made: " << menu[choice_] << "\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    else {
        cout << "Can't make a choice in this state\n";
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        int change = cash;
        cash = 0;
        state = WAIT;
        cout << "Order cancelled. Change: " << change << "\n";
    }
    else {
        cout << "Can't cancel in this state\n";
    }
}

void Automata::cook() {
    if (state == CHECK) {
        if (cash >= current_price) {
            cash -= current_price;
            state = COOK;
            cout << "Cooking...\n";
            cout << "Order ready: " << menu[choice_] << "\n";
            choice_ = -1;
            current_price = 0;
        }
        else {
            cout << "Not enough cash\n";
        }
    }
    else {
        cout << "Can't cook in this state\n";
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
    }
    else {
        cout << "Can't finish in this state\n";
    }
}

Automata::State Automata::getState() {
    return this->state;
}

int Automata::getCash() {
    cout << "Balance: " << cash << " coins" << endl;
    return cash;
}
