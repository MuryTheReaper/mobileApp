#include "services.h"

using std::make_unique;

std::ostream &operator<<(std::ostream &out, const servicesException &ex) {
  out << ex.msg;
  return out;
}

void services::add(const string &name, const float &price, const int &units) {

  val.validate(name, price, units);
  product x{name, price, units};
  undoList.push_back(make_unique<UndoAdd>(x, repo));
  repo.add(x);
}

void services::remove(const string &name, const float &price,
                      const int &units) {

  val.validate(name, price, units);
  product x{name, price, units};
  undoList.push_back(make_unique<UndoRemove>(x, repo));
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
  undoList.push_back(make_unique<UndoModify>(repo.find(x), repo));
  repo.modify(x);
}

void services::undo() {
  if (undoList.empty()) {
    throw servicesException("Nothing left to undo!");
  }

  undoList.back()->do_undo();
  undoList.pop_back();
}
