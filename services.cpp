#include "services.h"

std::ostream &operator<<(std::ostream &out, const servicesException &ex) {
  out << ex.msg;
  return out;
}

void services::add(const int &id, const string &name, const float &price,
                   const int &units) {

  val.validate(id, name, price, units);
  product x{id, name, price, units};
  repo.add(x);
}

void services::remove(const int &id, const string &name, const float &price,
                      const int &units) {

  val.validate(id, name, price, units);
  product x{id, name, price, units};
  repo.remove(x);
}

const product &services::find(const int &id, const string &name,
                              const float &price, const int &units) {

  val.validate(id, name, price, units);
  product x{id, name, price, units};
  return repo.find(x);
}

void services::modify(const int &id, const string &name, const float &price,
                      const int &units) {

  val.validate(id, name, price, units);
  product x{id, name, price, units};
  repo.modify(x);
}
