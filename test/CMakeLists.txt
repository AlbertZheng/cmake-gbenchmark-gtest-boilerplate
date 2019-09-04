set(TESTS_EXE_NAME tests)

set(TESTS_src
  run_all.cc
  foo_test.cc
  sum_test.cc
)

add_executable(${TESTS_EXE_NAME} ${TESTS_src})

target_include_directories(${TESTS_EXE_NAME}
  PUBLIC 
    ../third-party/googletest/googletest/include
)

target_link_libraries(${TESTS_EXE_NAME}
  gtest
  ${APP_LIB_NAME}
  ${CMAKE_THREAD_LIBS_INIT}
  ${MATH_LIBS}
)

add_test(
  NAME TEST_CASES
  COMMAND ${TESTS_EXE_NAME}
)
