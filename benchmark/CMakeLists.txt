set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)

set(BENCHMARKS_EXE_NAME benchmarks)

set(BENCHMARKS_src
  sum_benchmark.cc
)

add_executable(${BENCHMARKS_EXE_NAME} ${BENCHMARKS_src})

target_include_directories(${BENCHMARKS_EXE_NAME}
  PUBLIC 
    ../third-party/benchmark/include
)

target_link_libraries(${BENCHMARKS_EXE_NAME}
  benchmark
  ${APP_LIB_NAME}
  ${CMAKE_THREAD_LIBS_INIT}
  ${MATH_LIBS}
)
