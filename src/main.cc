#include <iostream>
#include <cstdlib>
#include "demo/foo.h"
#include "demo/sum.h"


auto main(int argc, char **argv) -> int {
  size_t times = argc < 2 ? 3 : std::max(1, std::atoi(argv[1]));
  std::cout
    << "foo(): " << times << " times of 2: " 
    << demo::foo(times) << "\n";
  
  demo::sum_foo();

  return 0;
}
