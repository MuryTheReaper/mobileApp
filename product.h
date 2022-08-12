#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using std::string;

class product {

private:
  string name;
  float price;
  int units;

public:
  product(const string &name, const float &price, const int &units)
      : name{name}, price{price}, units{units} {}

  ~product() = default;

  product &operator=(const product &) = default;

  product(product &&) = default;

  product &operator=(product &&) = default;

  product(const product &x) = default;

  const string getName() const noexcept { return name; }

  const float getPrice() const noexcept { return price; }

  const int getUnits() const noexcept { return units; }

  void setName(const string name) noexcept { this->name = name; }

  void setPrice(const float price) noexcept { this->price = price; }

  void setUnits(const int units) noexcept { this->units = units; }

  friend bool operator==(const product &x, const product &y) {
    return x.getName() == y.getName();
  }
};

#endif // PRODUCT_H
