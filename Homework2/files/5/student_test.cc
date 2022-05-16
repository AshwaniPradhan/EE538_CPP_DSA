#include <iostream>
#include <vector>
#include <stdio.h>
//#define NULL nullptr
#include "gtest/gtest.h"
#include "q.h"

// Write several test cases for each function.
//-----------------------------------------------------------------------------
// Make sure you add some test cases to check for nullptr.
TEST(ConcatenateDynamicArrays, test1) 
{
    CPPLib s;
     int arr1[4] = {10,20,30,40};
     int arr2[3] = {40,50,60};
     int expected[7] = {10,20,30,40,40,50,60};
    EXPECT_EQ(s.Concatenate(arr1,4,arr2, 3), expected);
}

TEST(ConcatenateDynamicArrays, test2) // null pointer
{
    CPPLib s;
     int *arr1 = nullptr;
     int *arr2 = nullptr;
     int *expected = nullptr;
    EXPECT_EQ(s.Concatenate(arr1,0,arr2, 0), expected);
}
//-----------------------------------------------------------------------------

TEST(ConcatenateVectors, test2) 
{
    CPPLib s;
    std::vector<int> vector1 {10,20,30};
    std::vector<int> vector2 {40,20,50};
    std::vector<int> expected {10,20,30,40,20,50};
    EXPECT_EQ(s.Concatenate(vector1,vector2), expected);

}
//////////////////////////////////////////////////////////////////////
TEST(ConcatenateVectors, test3) 
{
    CPPLib s;
    std::vector<int> vector1 {};
    std::vector<int> vector2 {};
    std::vector<int> expected {};
    EXPECT_EQ(s.Concatenate(vector1,vector2), expected);

}

//-----------------------------------------------------------------------------
