#include "/home/mury/App_info/mobileApp/product.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

// class productTesting : public ::testing::Test {
// protected:
//   void SetUp() override {
//     // Code here will be called immediately after the constructor (right
//     // before each test).
//   }

//  void TearDown() override {
//    // Code here will be called immediately after each test (right
//    // before the destructor).
//  }

//  product example{0, "Name", 12.3, 5};
//};

TEST(productTesting, getters) // NoLINT
{
  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example{name, price, units};

  EXPECT_EQ(example.getName(), name);
  EXPECT_LE(example.getPrice() - price, 0.1);
  EXPECT_EQ(example.getUnits(), units);
}

TEST(productTesting, setters) // NoLINT
{
  const string nameInitial = "Name";
  const float priceInitial = 12.3;
  const int unitsInitial = 5;

  product example{nameInitial, priceInitial, unitsInitial};

  const string name = "Name1";
  const float price = 12.31;
  const int units = 51;

  example.setName(name);
  example.setPrice(price);
  example.setUnits(units);

  EXPECT_EQ(example.getName(), name);
  EXPECT_LE(example.getPrice() - price, 0.1);
  EXPECT_EQ(example.getUnits(), units);
}

TEST(productTesting, equality) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example1{name, price, units};
  product example2{name, price + 1, units + 1};

  EXPECT_EQ(example1, example2);
}
