#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../header/KMP.h"

struct KMP_test_case {
  KMP_test_case(std::string&& str, std::string&& pattern, std::vector<size_t>&& entries_array = {}):
    str(str), pattern(pattern), entries_array(entries_array) {}

  std::string str;
  std::string pattern;
  std::vector<size_t> entries_array;
};

class KMP_test: public ::testing::TestWithParam<KMP_test_case> {
public:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_P(KMP_test, test) {
  KMP_test_case param = GetParam();
  auto entries_array = KMP(param.str, param.pattern);
  ASSERT_THAT(entries_array, testing::ElementsAreArray(param.entries_array));
}

INSTANTIATE_TEST_CASE_P(success, KMP_test, ::testing::Values(
      KMP_test_case("abacabadacaba", "acaba", {2, 8}),   // random
      KMP_test_case("abacabeabcabcabd", "abcabd", {10}),  // random
      KMP_test_case("mississipi", "ssiss", {2}),         // sym pattern
      KMP_test_case("aaa", "a", {0, 1, 2}),
      KMP_test_case("test", "test", {0}),
      KMP_test_case("xzasdasaasdcasad", "as", {2, 5, 8, 12}),
      KMP_test_case("kuababgabgrmuch", "abgabg", {4}) // repeat
    ));

INSTANTIATE_TEST_CASE_P(failure, KMP_test, ::testing::Values(
      KMP_test_case("aaa", "bbb", {}),
      KMP_test_case("abacabad", "ghmhmg", {}),
      KMP_test_case("alabamalama", "malamb", {})
    ));


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


