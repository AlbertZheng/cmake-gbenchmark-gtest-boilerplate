#include <iostream>
#include "gtest/gtest.h"

#include "demo/foo.h"

TEST(DemoFoo, Positives) {
  EXPECT_EQ(8, demo::foo(4));
  EXPECT_EQ(32, demo::foo(16));
  EXPECT_EQ(0, demo::foo(0));
}

TEST(DemoFoo, Negatives) {
  EXPECT_NE(-180, demo::foo(-99));
  EXPECT_NE(0, demo::foo(-41));
  EXPECT_NE(-21, demo::foo(42));
}
