
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test1) 
{
    CPPLib s;
    std::string input, expected;
    input = "this";
    s.CapitalizeFirstLetter(input);
    expected = "This";
    EXPECT_EQ(input,expected);
}
//-----------------------------------------------------------------------------

TEST(CapitalizeFirstLetter, test2) {
    CPPLib s;
    std::string input, expected;
    input = "This";
    //EXPECT_EQ(s.CapitalizeFirstLetter(input), true );
    s.CapitalizeFirstLetter(input);
    expected = "This";
    EXPECT_EQ(input,expected);
    
}
//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test3) {
    CPPLib s;
    std::string input, expected;
    input = "";
    
    //expected = "";
    EXPECT_EQ(s.CapitalizeFirstLetter(input),false);
}