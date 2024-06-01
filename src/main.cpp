// Copyright 2024 Yuri Shalnov

#include "Automata.h"

int main() {
    Automata machine = Automata();
    machine.on();
    machine.coin(100);
    machine.choice(1);
    machine.cook();
    machine.finish();
    return 0;
}

