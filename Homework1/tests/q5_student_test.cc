#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q5_Student, ReturnIntro) {
  CPPLib s;
  std::string given = s.PrintIntro();
  std::string expected = "I am Ashwani Pradhan. \nI am pursuing my Master's at Viterbi School of Engineering with specialization in Machine Learning & Data Science. \nMy contact: ashwanik@usc.edu \nMy interests are playing cricket, listening to classical music and Indian cooking.\n";
  EXPECT_EQ(s.PrintIntro(), expected); 
}

/*// Negative test if no introduction given and will fail on running
TEST(Q5_Student, ReturnIntro1) {
  CPPLib s;
  std::string given = s.PrintIntro();
  std::string expected = ""; // if no introductio given, the string will be empty
  EXPECT_EQ(expected, given); // the test should fail here as we have the introduction available

}
*/