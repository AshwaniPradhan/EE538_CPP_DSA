// NOTE: Add your own q2 tests in this file
#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q2_Student, FindAverageTest) {
  CPPLib s;
  std::vector<int> x = {1,2,3,4};
  double expected = 2.5;
  EXPECT_EQ(s.FindAverage(x), expected);
}

TEST(Q2_Student, FindAverageTest1) {
  CPPLib s;
  std::vector<int> x = {};
  double expected = -1;
  EXPECT_EQ(s.FindAverage(x), expected);
}

TEST(Q2_Student, FindAverageTest2) {
  CPPLib s;
  std::vector<int> x = {0,0,0,0};
  double expected = 0;
  EXPECT_EQ(s.FindAverage(x), expected);
}

TEST(Q2_Student, FindAverageTest3) {
  CPPLib s;
  std::vector<int> x = {11,22,33,44,55,66};
  double expected = 38.5;
  EXPECT_EQ(s.FindAverage(x), expected);
}