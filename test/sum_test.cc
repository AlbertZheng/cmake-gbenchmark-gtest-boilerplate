#include "gtest/gtest.h"
#include "demo/sum.h"

TEST(sum_test, should_return_sum_of_the_given_int_values) {
  EXPECT_EQ(1, demo::sum(1));
  EXPECT_EQ(6, demo::sum(1, 2, 3));
}

TEST(sum_test, should_return_sum_of_the_given_double_values) {
  EXPECT_DOUBLE_EQ(1.1, demo::sum(1.1));
  EXPECT_DOUBLE_EQ(6.6, demo::sum(1.1, 2.2, 3.3));
}

TEST(sum_test, should_return_sum_of_the_given_float_values) {
  EXPECT_FLOAT_EQ(1.1f, demo::sum(1.1f));
  EXPECT_FLOAT_EQ(6.6f, demo::sum(1.1f, 2.2f, 3.3f));
}
