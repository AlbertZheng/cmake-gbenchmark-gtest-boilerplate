#ifndef DEMO_SUM_H_
#define DEMO_SUM_H_

namespace demo {

template <typename... T>
constexpr auto sum(const T &... args) {
  return (... + args);
}

int sum_foo();

}

#endif
