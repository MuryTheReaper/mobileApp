#ifndef SERVICES_H
#define SERVICES_H

#include "repository.h"
#include "undo.h"
#include "validator.h"
#include <memory>

using std::unique_ptr;

class services {

private:
  repository &repo;
  validator &val;
  vector<unique_ptr<UndoAction>> undoList;

public:
  services(repository &repo, validator &val) : repo{repo}, val{val} {}

  services(const services &x) = delete;

  ~services() = default;

  services &operator=(const services &) = delete;

  services(services &&) = default;

  services &operator=(services &&) = delete;

  void add(const string &name, const float &price, const int &units);

  void remove(const string &name, const float &price, const int &units);

  void modify(const string &name, const float &price, const int &units);

  const product &find(const string &name, const float &price, const int &units);

  const vector<product> &getAll() const noexcept { return repo.getAll(); }

  void undo();
};

class servicesException {

private:
  std::string msg;

public:
  servicesException(std::string m) : msg{m} {}
  std::string getMsg() const { return msg; }

  friend std::ostream &operator<<(std::ostream &out,
                                  const servicesException &ex);
};
#endif // SERVICES_H
