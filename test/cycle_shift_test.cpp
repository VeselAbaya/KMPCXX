#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../header/cycle_shift.h"

struct Cycle_shift_case {
  Cycle_shift_case(std::string&& str1, std::string&& str2, int&& res):
      str1(str1), str2(str2), res(res) {}

  std::string str1;
  std::string str2;
  int res;
};

class Cycle_shift_test: public ::testing::TestWithParam<Cycle_shift_case> {
public:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_P(Cycle_shift_test, test) {
  Cycle_shift_case param = GetParam();
  int res = cycle_shift(param.str1, param.str2);
  ASSERT_EQ(res, param.res);
}

INSTANTIATE_TEST_CASE_P(success, Cycle_shift_test, ::testing::Values(
    Cycle_shift_case("abacaba", "cabaaba", 3),
    Cycle_shift_case("alasdfa", "alasdfa", 0),
    Cycle_shift_case("aaaa", "aaaa", 0)
));

INSTANTIATE_TEST_CASE_P(failure, Cycle_shift_test, ::testing::Values(
    Cycle_shift_case("vgsf", "haee", -1),
    Cycle_shift_case("aaaaa", "bbbbb", -1),
    Cycle_shift_case("mississipi", "ipississim", -1)
));


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


