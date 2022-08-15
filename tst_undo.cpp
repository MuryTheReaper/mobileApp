#include "/home/mury/App_info/mobileApp/services.h"
#include "/home/mury/App_info/mobileApp/undo.cpp"
//#include "/home/mury/App_info/mobileApp/undo.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

class undoTesting : public ::testing::Test {
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

TEST_F(undoTesting, add) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);
  serv.undo();

  ASSERT_EQ(serv.getAll().size(), 0);

  serv.add(name + "N", price, units);
  serv.add(name, price, units);
  serv.add(name + "X", price, units);

  serv.undo();
  serv.undo();

  vector<product> list{serv.getAll()};

  ASSERT_EQ(list.size(), 1);
  EXPECT_EQ(list.at(0).getName(), name + "N");
  EXPECT_EQ(list.at(0).getPrice(), price);
  EXPECT_EQ(list.at(0).getUnits(), units);
}

TEST_F(undoTesting, remove) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);
  serv.remove(name, price, units);
  serv.undo();

  vector<product> list{serv.getAll()};

  ASSERT_EQ(list.size(), 1);
  EXPECT_EQ(list.at(0).getName(), name);
  EXPECT_EQ(list.at(0).getPrice(), price);
  EXPECT_EQ(list.at(0).getUnits(), units);
}

TEST_F(undoTesting, modify) {

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;

  serv.add(name, price, units);
  serv.modify(name, price + 1, units + 1);
  serv.undo();

  vector<product> list{serv.getAll()};

  ASSERT_EQ(list.size(), 1);
  EXPECT_EQ(list.at(0).getName(), name);
  EXPECT_EQ(list.at(0).getPrice(), price);
  EXPECT_EQ(list.at(0).getUnits(), units);
}
