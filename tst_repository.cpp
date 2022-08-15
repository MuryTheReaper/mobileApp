#include "/home/mury/App_info/mobileApp/repository.cpp"
#include "/home/mury/App_info/mobileApp/repository.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(repositoryTesting, getAll) {
  repository repo;
  vector<product> list{repo.getAll()};
  EXPECT_EQ(list.size(), 0);
}

TEST(repositoryTesting, add) {
  repository repo;

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example{name, price, units};

  repo.add(example);

  ASSERT_EQ(repo.getAll().size(), 1);
  EXPECT_EQ(repo.getAll()[0].getName(), name);
  EXPECT_EQ(repo.getAll()[0].getPrice(), price);
  EXPECT_EQ(repo.getAll()[0].getUnits(), units);

  try {
    repo.add(example);
    ASSERT_TRUE(0);
  } catch (repoException &ex) {
    ASSERT_EQ(ex.getMsg(), "This product already exist: Name");
  }
}

TEST(repositoryTesting, find) {

  repository repo;

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example{name, price, units};
  repo.add(example);

  product example2{name, 0, 0};

  product result{repo.find(example2)};

  EXPECT_EQ(result.getName(), name);
  EXPECT_EQ(result.getPrice(), price);
  EXPECT_EQ(result.getUnits(), units);

  product example3{name + "N", price, units};
  try {
    repo.find(example3);
    ASSERT_TRUE(0);
  } catch (repoException &ex) {
    ASSERT_EQ(ex.getMsg(), "This product does not exist: NameN");
  }
}

TEST(repositoryTesting, remove) {

  repository repo;

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example1{name, price, units};
  product example2{name + "2", price, units};
  product example3{name + "3", price, units};

  repo.add(example1);
  repo.remove(example1);

  vector<product> list{repo.getAll()};
  EXPECT_EQ(list.size(), 0);

  repo.add(example1);
  repo.add(example2);
  repo.add(example3);

  repo.remove(example1);

  list = repo.getAll();
  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.at(0).getName(), name + "2");
  EXPECT_EQ(list.at(1).getName(), name + "3");

  try {
    repo.remove(example1);
    ASSERT_TRUE(0);
  } catch (repoException &ex) {
    ASSERT_EQ(ex.getMsg(), "This product does not exist: Name");
  }
}

TEST(repositoryTesting, modify) {

  repository repo;

  const string name = "Name";
  const float price = 12.3;
  const int units = 5;
  product example1{name, price, units};
  product example2{name, price + 1, units + 1};

  repo.add(example1);
  repo.modify(example2);

  ASSERT_EQ(repo.getAll().size(), 1);
  EXPECT_EQ(repo.getAll()[0].getName(), name);
  EXPECT_EQ(repo.getAll()[0].getPrice(), price + 1);
  EXPECT_EQ(repo.getAll()[0].getUnits(), units + 1);

  product example3{name + "N", price, units};

  try {
    repo.modify(example3);
    ASSERT_TRUE(0);
  } catch (repoException &ex) {
    ASSERT_EQ(ex.getMsg(), "This product does not exist: NameN");
  }
}
