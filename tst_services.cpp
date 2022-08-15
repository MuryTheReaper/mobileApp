#include "/home/mury/App_info/mobileApp/services.cpp"
#include "/home/mury/App_info/mobileApp/services.h"
//#include "/home/mury/App_info/mobileApp/validator.cpp"
//#include "/home/mury/App_info/mobileApp/validator.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

class servicesTesting : public ::testing::Test {
protected:
  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  repository repo;          // NOLINT
  validator val;            // NOLINT
  services serv{repo, val}; // NOLINT
};

TEST_F(servicesTesting, getAll) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example{name, price, units};

  repo.add(example);

  vector<product> list{serv.getAll()};

  ASSERT_EQ(list.size(), 1);
  EXPECT_EQ(list.at(0).getName(), name);
  EXPECT_EQ(list.at(0).getPrice(), price);
  EXPECT_EQ(list.at(0).getUnits(), units);
}

TEST_F(servicesTesting, add) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);

  vector<product> list{serv.getAll()};

  ASSERT_EQ(list.size(), 1);
  EXPECT_EQ(list.at(0).getName(), name);
  EXPECT_EQ(list.at(0).getPrice(), price);
  EXPECT_EQ(list.at(0).getUnits(), units);
}

TEST_F(servicesTesting, find) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);

  product result{serv.find(name, price, units)};

  EXPECT_EQ(result.getName(), name);
  EXPECT_EQ(result.getPrice(), price);
  EXPECT_EQ(result.getUnits(), units);
}

TEST_F(servicesTesting, remove) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);
  serv.add(name + "N", price, units);

  serv.remove(name, price, units);

  ASSERT_EQ(serv.getAll().size(), 1);

  serv.remove(name + "N", price, units);

  ASSERT_EQ(serv.getAll().size(), 0);
}

TEST_F(servicesTesting, modify) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);
  serv.modify(name, price + 1, units + 1);

  product result{serv.getAll().at(0)};

  EXPECT_EQ(result.getName(), name);
  EXPECT_EQ(result.getPrice(), price + 1);
  EXPECT_EQ(result.getUnits(), units + 1);
}
