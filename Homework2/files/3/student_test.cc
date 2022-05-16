#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Calculate, add) //add
{
    CPPLib s;
    int a = 5;
    int b = 6;
    double output;
    output= s.Calculate(a,b,Operation::add);
    EXPECT_EQ(output, 11);
}
//-----------------------------------------------------------------------------

TEST(Calculate, test2) //subtract
{
    CPPLib s;
    int a = 5;
    int b = 6;
    double output;
    output= s.Calculate(a,b,Operation::subtract);
    EXPECT_EQ(output, -1);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test3) 
{
    CPPLib s;
    int a = 5;
    int b = 6;
    double output;
    output= s.Calculate(a,b,Operation::multiplication);
    EXPECT_EQ(output, 30);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test5) //divide by zero
{
    CPPLib s;
    int a = 15;
    int b = 0;
    double output;
    output= s.Calculate(a,b,Operation::division);
    EXPECT_EQ(output, -1);
}
TEST(Calculate, test11)  //division
{
    CPPLib s;
    int a = 15;
    int b = 6;
    double output;
    output= s.Calculate(a,b,Operation::division);
    EXPECT_EQ(output, 2);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test6) 
{
    CPPLib s;
    int a = 15;
    int b = 5;
    double output;
    output= s.Calculate(a,b,Operation::bitwise_AND);
    EXPECT_EQ(output, 5);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test7) 
{
    CPPLib s;
    int a =15;
    int b = 5;
    double output;
    output= s.Calculate(a,b,Operation::bitwise_OR);
    EXPECT_EQ(output, 15);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test8) 
{
    CPPLib s;
    int a = 15;
    int b = 5;
    double output;
    output= s.Calculate(a,b,Operation::bitwise_XOR);
    EXPECT_EQ(output, 10);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test9) 
{
    CPPLib s;
    int a = 15;
    int b = 5;
    double output;
    output= s.Calculate(a,b,Operation::shift_left);
    EXPECT_EQ(output, 480);
}
//-----------------------------------------------------------------------------
TEST(Calculate, test10) 
{
    CPPLib s;
    int a = 15;
    int b = 5;
    double output;
    output= s.Calculate(a,b,Operation::shift_right);
    EXPECT_EQ(output, 0);
}