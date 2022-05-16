#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(CheckValidExpression, test1) // correct order of brackets
{
    CPPLib s;
    std::string input;
    input = "{1+2+(6/3)}";
    EXPECT_EQ(s.CheckValidExpression(input), true);
}

TEST(CheckValidExpression, test2) //incorrect order of brackets 
{
    CPPLib s;
    std::string input;
    input = "(7h+[5c)+7]";
    EXPECT_EQ(s.CheckValidExpression(input), false);
}


TEST(CheckValidExpression, test3) //incorrect order of brackets 
{
    CPPLib s;
    std::string input;
    input = ")}{}))))))]]]]";
    EXPECT_EQ(s.CheckValidExpression(input), false);
}


TEST(CheckValidExpression, test4) //incorrect order of brackets 
{
    CPPLib s;
    std::string input;
    input = "{(a-b)+c-{a}})}";
    EXPECT_EQ(s.CheckValidExpression(input), false);
}
TEST(CheckValidExpression, test5) //correct order of brackets 
{
    CPPLib s;
    std::string input;
    input = "(a+b)[c*d]{5g+h}{}()";
    EXPECT_EQ(s.CheckValidExpression(input), true);
}

///////////////////////////////////////////////////////////////
////////PALINDROME TEST///////////////////////////////////////
TEST(IsPalindrome, invalid_test) 
{
    CPPLib s;
    std::string input;
    input = "abA";
    EXPECT_EQ(s.IsPalindrome(input), false);
}

TEST(IsPalindrome, test_invalid) 
{
    CPPLib s;
    std::string input;
    input = "ZAQWSXCDERFV";
    EXPECT_EQ(s.IsPalindrome(input), false);
}

TEST(IsPalindrome, test_valid1) 
{
    CPPLib s;
    std::string input;
    input = "abba";
    EXPECT_EQ(s.IsPalindrome(input), true);
}

TEST(IsPalindrome, test_valid2) 
{
    CPPLib s;
    std::string input;
    input = "";
    EXPECT_EQ(s.IsPalindrome(input), true);
}
TEST(IsPalindrome, test4) 
{
    CPPLib s;
    std::string input;
    input = "aacaa";
    EXPECT_EQ(s.IsPalindrome(input), true);
}

///////////////////////////////////////////////////////////////
////////////Odd character test////////////////////////////////

TEST(OddChar, test_valid) 
{
    CPPLib s;
    std::string input;
    input = "abbas";
    EXPECT_EQ(s.OddChar(input), 115); // comparing with ascii numbers
}
TEST(OddChar, test_invalid) 
{
    CPPLib s;
    std::string input;
    input = "maann";
    EXPECT_EQ(s.OddChar(input), 109);
}
TEST(Oddchar, test3)
{
    CPPLib s;
    std::string in = "tenet";
    std::string res = std::string(1, (char)s.OddChar(in)); // comparing with resultant character
    std::string expected_res = "n";
    EXPECT_EQ(res, expected_res);
}