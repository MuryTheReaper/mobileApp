#include "repository.h"
#include <algorithm>
#include <vector>

void repository::add(const product &x) {

  if (exist(x)) {
    throw repoException("This product already exist: " + x.getName());
  }
  list.push_back(x);
}

bool repository::exist(const product &x) const {

  try {
    find(x);
    return true;
  } catch (repoException &) {
    return false;
  }
}

const product &repository::find(const product &x) const {

  for (const auto &y : list) {
    if (x == y) {
      return y;
    }
  }

  throw repoException("This product does not exist: " + x.getName());
}

void repository::remove(const product &x) {

  if (!exist(x)) {
    throw repoException("This product does not exist: " + x.getName());
  }
  list.erase(std::remove(list.begin(), list.end(), x));
}

void repository::modify(const product &x) {

  bool found = false;
  for (auto &y : list) {
    if (x == y) {
      y.setName(x.getName());
      y.setPrice(x.getPrice());
      y.setUnits(x.getUnits());
      found = true;
      break;
    }
  }
  if (!found) {
    throw repoException("This product does not exist: " + x.getName());
  }
}
std::ostream &operator<<(std::ostream &out, const repoException &ex) {

  out << ex.msg;
  return out;
}
