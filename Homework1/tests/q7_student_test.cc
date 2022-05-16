#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q7_Student, climbStairs1) 
{
  CPPLib s;
 
  int input = 5;
  int actual;
  actual= s.climbStairs(input);
  int expected = 8;
  EXPECT_EQ(expected, actual);
}

TEST(Q7_Student, climbStairs2) 
{
  CPPLib s;
 
  int input = 6;
  int actual;
  actual= s.climbStairs(input);
  int expected = 13;
  EXPECT_EQ(expected, actual);
}
//test for zero stairs
TEST(Q7_Student, climbStairs3) 
{
  CPPLib s;
 
  int input = 0;
  int actual;
  actual= s.climbStairs(input);
  int expected = 0;
  EXPECT_EQ(expected, actual);
}
//test for negative number of steps given
TEST(Q7_Student, climbStairs4) 
{
  CPPLib s;
 
  int input = -5;
  int actual;
  actual= s.climbStairs(input);
  int expected = -1;
  EXPECT_EQ(expected, actual);
}

TEST(Q7_Student, climbStairs5) 
{
  CPPLib s;
 
  int input = 20;
  int actual;
  actual= s.climbStairs(input);
  int expected = 10946;
  EXPECT_EQ(expected, actual);
}