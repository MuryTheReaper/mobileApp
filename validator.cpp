#include "validator.h"

std::ostream &operator<<(std::ostream &out, const validatorException &ex) {
  for (const auto &msgs : ex.msg) {
    out << msgs + " ";
  }
  return out;
}

void validator::validate(const string &name, const float &price,
                         const int &units) {

  vector<string> msgs;

  if (name.size() == 0) {
    msgs.push_back("Name is empty!");
  }

  if (price <= 0) {
    msgs.push_back("Price is invalid!");
  }

  if (units <= 0) {
    msgs.push_back("Number of units below 0!");
  }

  if (msgs.size() > 0) {
    throw validatorException(msgs);
  }
}
