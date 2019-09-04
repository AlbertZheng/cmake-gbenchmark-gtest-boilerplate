#include <benchmark/benchmark.h>
#include "demo/sum.h"

static void sum(benchmark::State &state) {
  for (auto _ : state) {
    demo::sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  }
}
BENCHMARK(sum);

BENCHMARK_MAIN();
