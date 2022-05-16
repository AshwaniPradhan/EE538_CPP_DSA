#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(IndexOfFirstSpace, test1)  // if no space in string
{
    std::string s;
    CPPLib s1;
    s = "this";
   // int actual, a;
    //actual = s1.IndexOfFirstSpace(s);
    int expected = -1;
    EXPECT_EQ(s1.IndexOfFirstSpace(s), expected);
    //std::cout<<post<<std::endl;
}
TEST(IndexOfFirstSpace, test2) //valid case
{
    std::string s;
    CPPLib s1;
    s = "this is a test";
    //int actual, a;
    //actual = s1.IndexOfFirstSpace(s);
    double expected = 4;
    EXPECT_EQ(s1.IndexOfFirstSpace(s), expected);
    //std::cout<<post<<std::endl;
}
TEST(IndexOfFirstSpace, test3) //if the string starts witha space, position will be 0 i.e. first position
{
    std::string s;
    CPPLib s1;
    s = " starts with space";
    //int actual, a;
    //actual = s1.IndexOfFirstSpace(s);
    double expected = 0;
    EXPECT_EQ(s1.IndexOfFirstSpace(s), expected);
    //std::cout<<post<<std::endl;
}
TEST(IndexOfFirstSpace, test4) //if the string starts witha space, position will be 0 i.e. first position
{
    std::string s;
    CPPLib s1;
    s = "";
    //int actual, a;
    //actual = s1.IndexOfFirstSpace(s);
    double expected = -1;
    EXPECT_EQ(s1.IndexOfFirstSpace(s), expected);
    //std::cout<<post<<std::endl;
}
//-----------------------------------------------------------------------------
TEST(SeparateFirstAndLastNames, test1) 
{
    std::string full_name;
    CPPLib s1;
    full_name = "Patrick Harris";
    std::string first_name="", last_name="", exp_f, exp_l;
    s1.SeparateFirstAndLastNames(full_name, first_name="", last_name="");
    exp_f = "Patrick";
    exp_l = "Harris";
    EXPECT_EQ(first_name, exp_f);
    EXPECT_EQ(last_name, exp_l);
    
}
TEST(SeparateFirstAndLastNames, test2) 
{
    std::string full_name;
    CPPLib s1;
    full_name = "Neil Patrick Harris";
    std::string first_name="", last_name="", exp_f, exp_l;
    s1.SeparateFirstAndLastNames(full_name, first_name="", last_name="");
    exp_f = "Neil";
    exp_l = "Patrick Harris";
    EXPECT_EQ(first_name, exp_f);
    EXPECT_EQ(last_name, exp_l);
    
}
TEST(SeparateFirstAndLastNames, test3) 
{
    std::string full_name;
    CPPLib s1;
    full_name = "Patrick";
    std::string first_name="", last_name="", exp_f, exp_l;
    s1.SeparateFirstAndLastNames(full_name, first_name="", last_name="");
    exp_f = "Patrick";
    exp_l = "";
    EXPECT_EQ(first_name, exp_f);
    EXPECT_EQ(last_name, exp_l);
    
}
//-----------------------------------------------------------------------------
TEST(NumberOfVowels, test1) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="Aeiouklklklkl !";
    num=s1.NumberOfVowels(s);
    EXPECT_EQ(num, 5);
}
TEST(NumberOfVowels, test2) //empty string
{
    CPPLib s1;
    std::string s;
    int num;
    s="";
    num=s1.NumberOfVowels(s);
    EXPECT_EQ(num, 0);
}

TEST(NumberOfVowels, test3) //no vowel in string
{
    CPPLib s1;
    std::string s;
    int num;
    s="zxcvbnm lkjhgfd bnmvcbnb";
    num=s1.NumberOfVowels(s);
    EXPECT_EQ(num, 0);
}
//-----------------------------------------------------------------------------
TEST(NumberOfConsonants, test1) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="This!";
    num=s1.NumberOfConsonants(s);
    EXPECT_EQ(num, 4);

}
TEST(NumberOfConsonants, test2) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="ae this is louis#$%^$^&%";
    num=s1.NumberOfConsonants(s);
    EXPECT_EQ(num, 17);

}
TEST(NumberOfConsonants, test3) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="";
    num=s1.NumberOfConsonants(s);
    EXPECT_EQ(num, 0);

}
//-----------------------------------------------------------------------------
TEST(Reverse, test1) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="";
    num=s1.Reverse(s);
    EXPECT_EQ(num, -1);
}
TEST(Reverse, test2) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="THIS";
    num=s1.Reverse(s);
    EXPECT_EQ(num, 1);
}
TEST(Reverse, test3) 
{
    CPPLib s1;
    std::string s;
    int num;
    s="%^&%^*(";
    num=s1.Reverse(s);
    EXPECT_EQ(num, 1);
}
