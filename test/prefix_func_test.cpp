#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../header/prefix_func.h"

TEST(Prefix_func, test) {
  ASSERT_THAT(prefix_func("efefeftef"), testing::ElementsAre(0, 0, 1, 2, 3, 4, 0, 1, 2));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

