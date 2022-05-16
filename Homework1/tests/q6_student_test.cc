#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
//Test to check if given vector is empty
TEST(Q6_Student, Flatten3DVector_empty) 
{
  CPPLib s;
  std::vector<std::vector<std::vector<int>>> inputs = {{}};
  std::vector<int> expect = {};

  EXPECT_EQ(s.Flatten3DVector(inputs), expect);
}

//Testing for a 3D vector as given in the question
TEST(Q6_Student, Flatten3DVector_full) 
{
  CPPLib s;
  std::vector<std::vector<std::vector<int>>> inputs = {{{1,2},{3,4}}, {{5},{6},{}}, {{7,8}}};
  std::vector<int> expect = {1,2,3,4,5,6,7,8};

  EXPECT_EQ(s.Flatten3DVector(inputs), expect);
}

//Testing for a 3D vector with partial values
TEST(Q6_Student, Flatten3DVector_partial) 
{
  CPPLib s;
  std::vector<std::vector<std::vector<int>>> inputs = {{{1,2},{3,4}}, {}, {{12,15}}};
  std::vector<int> expect = {1,2,3,4, 12,15};

  EXPECT_EQ(s.Flatten3DVector(inputs), expect);
}

//Testing for a 3D vector as given in the question
TEST(Q6_Student, Flatten3DVector_valid) 
{
  CPPLib s;
  std::vector<std::vector<std::vector<int>>> inputs = {{{1,2},{3,4}}, {{5},{6},{}}, {{7,8,9}}};
  std::vector<int> expect = {1,2,3,4,5,6,7,8, 9};

  EXPECT_EQ(s.Flatten3DVector(inputs), expect);
}