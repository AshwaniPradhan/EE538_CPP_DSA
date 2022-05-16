#include "cpplib.h"
#include "limits"

std::string CPPLib::PrintHelloWorld() { return "**** Hello World ****"; }

// NOTE: write your own function declaration q2 here
double CPPLib::FindAverage(std::vector<int> input)
{
    double sum = 0;
    double average;
    if (input.size() == 0) // check if the given vector size is zero
    {
        return -1;
    }

    for (auto x: input)
    {
        sum +=x;
    }
    average = sum/input.size();
    return average;
}

// Question 5 Print your self-introduction
std::string CPPLib::PrintIntro() {
    // Please fill up this function.
    return "I am Ashwani Pradhan. \n"
            "I am pursuing my Master's at Viterbi School of Engineering with specialization in Machine Learning & Data Science. \n"
            "My contact: ashwanik@usc.edu \n"
            "My interests are playing cricket, listening to classical music and Indian cooking.\n"; 
}

// Question 6
std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input){
    // Please fill up this function.
    std::vector<int> res_1D;
    //checking if the vector is empty
    if(input.empty())
    {
        return res_1D;
    }
    for (auto vector1:input)
    {
        if (vector1.empty()) //check if vector1 is empty
        {
            continue;
        }
        for(auto vector2:vector1) //or combine vector 1 with vector 2
        {
            if (vector2.empty()) //check if vector2 is empty
            {
                continue;
            }
            for(auto i:vector2) // taking the full length of 3 vectors and combine them to be 1d vector
            {
                res_1D.push_back(i);

            }
        }
    }
    return res_1D;
}

// Question 7 Climbing Stairs
int CPPLib::climbStairs(int n){
    // Please fill up this function.
    if (n<0) //if neagtive number of steps are given
    return -1;

    if(n ==0) // if the given number of steps is equal to 0 or 1 or 2
    return 0;

    if(n==1)
    return 1;

    if(n==2)
    return 2;
    // by observation we can see that the number of ways can be found by adding the last two values in the process to find total number of ways to reach to top
    else
    {
        return  climbStairs(n-1) + climbStairs(n-2); //recursively calling the function to give the total ways to reach to top
    } 
}

