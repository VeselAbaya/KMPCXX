#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../header/KMP.h"

/*
 it('should find all entries of pattern', () => {
    const entriesArray: Array<number> | -1 = KMP('abab', 'ab');
    expect(entriesArray).to.deep.equal([0, 2]);
  });

  it('should return -1', () => {
    const entriesArray: Array<number> | -1 = KMP('abcef', 'abcd');
    expect(entriesArray).to.equal(-1);
  });
 */

TEST(KMP_func, test) {
  auto entriesArray = KMP("abab", "ab");
  ASSERT_THAT(entriesArray, testing::ElementsAre(0, 2));
}

TEST(KMP_func, test_no_matches) {
  auto entriesArray = KMP("abcef", "abcd");
  ASSERT_THAT(entriesArray, testing::SizeIs(0));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


