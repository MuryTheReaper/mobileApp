#include "product.h"

bool operator==(const product &x, const product &y) {

  return x.getId() == y.getId();
}
