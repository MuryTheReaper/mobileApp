#ifndef SERVICES_H
#define SERVICES_H

#include "repository.h"
#include "validator.h"

class services {

private:
  repository &repo;
  validator &val;

public:
  services(repository &repo, validator &val) : repo{repo}, val{val} {};

  services(const services &x) = delete;

  ~services() = default;

  services &operator=(const services &) = delete;

  services(services &&) = default;

  services &operator=(services &&) = delete;

  void add(const int &id, const string &name, const float &price,
           const int &units);

  void remove(const int &id, const string &name, const float &price,
              const int &units);

  void modify(const int &id, const string &name, const float &price,
              const int &units);

  const product &find(const int &id, const string &name, const float &price,
                      const int &units);

  const vector<product> &getAll() const noexcept { return repo.getAll(); }
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
