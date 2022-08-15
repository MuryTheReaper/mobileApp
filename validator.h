#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class validator {
public:
  void validate(const string &name, const float &price, const int &units);
};

class validatorException {

private:
  std::vector<std::string> msg;

public:
  validatorException(const std::vector<std::string> &errors) : msg{errors} {}
  std::vector<std::string> getMsg() const { return msg; }
  friend std::ostream &operator<<(std::ostream &out,
                                  const validatorException &ex);
};

#endif // VALIDATOR_H
