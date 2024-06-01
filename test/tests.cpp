// Copyright 2024 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(states, ON) {
   Automata machine = Automata();
   machine.on();
   EXPECT_EQ(Automata::WAIT, machine.getState());
}

TEST(states, OFF) {
   Automata machine = Automata();
   machine.on();
   machine.off();
   EXPECT_EQ(Automata::OFF, machine.getState());
}

TEST(states, ACCEPT) {
   Automata machine = Automata();
   machine.on();
   machine.coin(10);
   EXPECT_EQ(Automata::ACCEPT, machine.getState());
}

TEST(states, CANCEL) {
   Automata machine = Automata();
   machine.on();
   machine.coin(10);
   machine.cancel();
   EXPECT_EQ(Automata::WAIT, machine.getState());
}


TEST(states, CHECK) {
   Automata machine = Automata();
   machine.on();
   machine.coin(10);
   machine.choice(1);
   EXPECT_EQ(Automata::CHECK, machine.getState());
}

TEST(states, COOK) {
   Automata machine = Automata();
   machine.on();
   machine.coin(10);
   machine.choice(1);
   machine.cook();
   EXPECT_EQ(Automata::COOK, machine.getState());
}

TEST(states, FINISH) {
   Automata machine = Automata();
   machine.on();
   machine.coin(10);
   machine.choice(1);
   machine.cook();
   machine.finish();
   EXPECT_EQ(Automata::WAIT, machine.getState());
}

TEST(balanceTest, CASH) {
   Automata machine = Automata();
   machine.on();
   machine.coin(10);
   machine.getCash();
   EXPECT_EQ(10, machine.getCash());
}
