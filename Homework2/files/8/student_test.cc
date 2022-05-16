#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(UniqueVectorNotBySet, test1) {
    CPPLib s;
    std::vector<int> input = {1,3,3,4,0,8,7,9,9};
    std::vector<int> expected = {1,3,4,0,8,7,9};
    s.UniqueVectorNotBySet(input);
    //std::sort(input.begin(), input.end());
    EXPECT_EQ(input,expected);
}
//-----------------------------------------------------------------------------
TEST(UniqueVectorBySet, test1) {
    CPPLib s;
    std::vector<int> input = {1,3,3,4,0,8,7,9,9};
    std::vector<int> expected = {1,3,4,0,8,7,9};
    s.UniqueVectorBySet(input);
    //std::sort(input.begin(), input.end());
    EXPECT_EQ(input,expected);

}
//-----------------------------------------------------------------------------
TEST(IntersectVectors, test2) 
{
    CPPLib s;
    std::vector<int> input1 = {1,3,3,4};
    std::vector<int> input2 = {3,4,7,9};
    std::vector<int> expected = {3,4};
   // s.IntersectVectors(input1, input2);
    //std::sort(input.begin(), input.end());
    EXPECT_EQ(s.IntersectVectors(input1, input2),expected);

}