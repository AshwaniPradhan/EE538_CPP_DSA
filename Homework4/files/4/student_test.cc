#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
//no dynamic programming

TEST(MyTest, Test_NDP) 
{
    std::vector<int> val =  {10, 20, 30, 40};
    std::vector<int> wt = {30, 10, 40, 20};
    int w = 40;
    int exp = knapSack01NoDynamicProgramming(wt, val, w);
    EXPECT_EQ(exp, 60);
}

TEST(MyTest, Test1) 
{
    std::vector<int> val =  {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int w = 50;
    int exp = knapSack01NoDynamicProgramming(wt, val, w);
    EXPECT_EQ(exp, 220);
}
TEST(MyTest, Test2) 
{
    std::vector<int> val =  {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int w = 0;
    int exp = knapSack01NoDynamicProgramming(wt, val, w);
    EXPECT_EQ(exp, 0);
}
//////////////////////////////////////////////////////////////
// Memoizaiton
TEST(MyTest, Test3) 
{
    std::vector<int> val =  {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int w = 50;
    int exp = knapSack01Memo(wt, val, w);
    EXPECT_EQ(exp, 220);
}

TEST(MyTest, Test4) 
{
    std::vector<int> val =  {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int w = 0;
    int exp = knapSack01Memo(wt, val, w);
    EXPECT_EQ(exp, 0);
}
TEST(MyTest, Test8) 
{
    std::vector<int> val =  {10, 20, 30, 40};
    std::vector<int> wt = {30, 10, 40, 20};
    int w = 40;
    int exp = knapSack01Memo(wt, val, w);
    EXPECT_EQ(exp, 60);
}

/////////////////////////////////////////////////////////////////
///Tabulation
TEST(MyTest, Test5) 
{
    std::vector<int> val =  {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int w = 50;
    int exp = knapSack01Tablulation(wt, val, w);
    EXPECT_EQ(exp, 220);
}
TEST(MyTest, Test6) 
{
    std::vector<int> val =  {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int w = 0;
    int exp = knapSack01Tablulation(wt, val, w);
    EXPECT_EQ(exp, 0);
}

TEST(MyTest, Test7) 
{
    std::vector<int> val =  {10, 20, 30, 40};
    std::vector<int> wt = {30, 10, 40, 20};
    int w = 40;
    int exp = knapSack01Tablulation(wt, val, w);
    EXPECT_EQ(exp, 60);
}