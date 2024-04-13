#include "gtest/gtest.h"
#include"Automata.h"
#include"Product.h"
class AutomataTest : public testing::Test {
protected:
	Automata Coffe;
};

TEST(TestCoffeeMACHINE, Vkluchenie) {
	Automata Coffe;
	Coffe.ON();
  EXPECT_TRUE(wait,Coffe.get_State());
}