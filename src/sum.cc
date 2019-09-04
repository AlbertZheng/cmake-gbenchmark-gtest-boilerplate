#include "demo/sum.h"
#include <iostream>

namespace demo {

int sum_foo() {
  std::cout << "sum of values: " << demo::sum(0.1f, 1.2f, 3.4f, 5.6f) << std::endl;

  return 0;
}

}