#include "/home/mury/App_info/mobileApp/validator.cpp"
#include "/home/mury/App_info/mobileApp/validator.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(validatorTesting, validate) {

  const string name = "ame";
  const float price = -12.3;
  const int units = -5;

  validator val;

  try {
    val.validate(name, price, units);
    ASSERT_TRUE(0);
  } catch (validatorException &ex) {
    EXPECT_EQ(ex.getMsg().at(0), "First letter must be uppercase!");
    EXPECT_EQ(ex.getMsg().at(1), "Price is invalid!");
    EXPECT_EQ(ex.getMsg().at(2), "Number of units below 0!");
  }
}
