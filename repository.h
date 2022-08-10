#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "product.h"
#include <vector>
using std::vector;

class repository {

private:
  vector<product> list;

  bool exist(const product &x) const;

public:
  repository() = default;

  repository(const repository &x) = delete;

  ~repository() = default;

  repository &operator=(const repository &) = delete;

  repository(repository &&) = default;

  repository &operator=(repository &&) = delete;

  void add(const product &x);

  void remove(const product &x);

  void modify(const product &x);

  const product &find(const product &x) const;

  const std::vector<product> &getAll() const noexcept { return list; };
};

class repoException {

private:
  std::string msg;

public:
  repoException(std::string m) : msg{m} {}
  std::string getMsg() const { return msg; }
  friend std::ostream &operator<<(std::ostream &out, const repoException &ex);
};

#endif // REPOSITORY_H
