#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"
// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(SwapByPointer, test1) 
{
     CPPLib s;
    float input1 = 5;
    float input2 = 7;
    s.SwapByPointer(&input1,&input2);
    EXPECT_EQ(input1, 7);
    EXPECT_EQ(input2, 5);

}
//-----------------------------------------------------------------------------

TEST(SwapByReference, test2) 
{
    CPPLib s;
    float input1 = 5;
    float input2 = 7;
    s.SwapByReference(input1,input2);
    EXPECT_EQ(input1, 7);
    EXPECT_EQ(input2, 5);
}
//-----------------------------------------------------------------------------
