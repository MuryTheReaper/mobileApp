#include "services.h"

std::ostream &operator<<(std::ostream &out, const servicesException &ex) {
  out << ex.msg;
  return out;
}

void services::add(const string &name, const float &price, const int &units) {

  val.validate(name, price, units);
  product x{name, price, units};
  repo.add(x);
}

void services::remove(const string &name, const float &price,
                      const int &units) {

  val.validate(name, price, units);
  product x{name, price, units};
  repo.remove(x);
}

const product &services::find(const string &name, const float &price,
                              const int &units) {

  val.validate(name, price, units);
  product x{name, price, units};
  return repo.find(x);
}

void services::modify(const string &name, const float &price,
                      const int &units) {

  val.validate(name, price, units);
  product x{name, price, units};
  repo.modify(x);
}
