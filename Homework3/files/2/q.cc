#include "q.h"

#include <iostream>
#include <stack>
#include <vector>
// Implement each function of `q.h` here.


bool CPPLib::CheckValidExpression(const std::string& input)
{
    std::stack<char> stack;
    char c;
    int i;
    int str_size =  input.size();
    for (i=0; i < str_size; i++)
    {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{' )
        {
            stack.push(input[i]);
            continue;
        }
        if(input.empty())
        {
            return true; // as given empty string is a valid string 
        }

        switch(input[i])
        {
            case ')': 
                if (stack.empty()) return false;
                c = stack.top();
                stack.pop();
                if (c == '[' || c == '{')
                return false;
                break;

            case ']':
                if (stack.empty()) return false;
                c = stack.top();
                stack.pop();
                if (c == '{' || c == '(')
                return false;
                break;

            case '}':
                if (stack.empty()) return false;
                c = stack.top();
                stack.pop();
                if(c == '[' || c == '(')
                return false;
                break;
        }
    }
    return (stack.empty()); // return true when stack in empty
}


bool CPPLib::IsPalindrome(const std::string& input)
{
    int str_size =  input.size();
    //std::stack<std::string> output;
    //str_size = input.size();
    //int i;
    //std::string ouput = ""

    for(int i = 0; i < (str_size/2); i++)
    {
        if (input[i] != input[ (str_size) - i -1])
        return false;
    }
    return true;
}

int CPPLib::OddChar(const std::string& input)
{
    // store the occurence of each character in the string and check if its occuring for odd number of times
    // only for lowercase letters
    int i;
    //int occurence[26] = {0};
    //int str_size = input.size();

    int odd_val=0;
    for(auto i: input) odd_val = odd_val^i;
    return odd_val;

    // for (i = 0; i < str_size; i++)
    // {
    //     occurence[input[i] - 97]++;
    // }

    // for (i = 0; i < 26; i++)
    // {
    //     if (occurence[i] % 2 == 1)
    //     {
    //         return -1;
    //     }
    // }
    // return 1;
}