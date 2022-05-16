#include <string>

#include "q.h"

// A function that capitalize the first letter of a string.
// If it was possible, returns true, otherwise false.
bool CPPLib::CapitalizeFirstLetter(std::string &input) 
{
    int str_size = input.size();
    if (str_size == 0)
    {
        return false;
    }
    if((input[0] >= 97 && input[0] <=122) || ((input[0] >= 65 && input[0] <=90)))
    {
    input[0]=toupper(input[0]);
    }
    else
    {
    return false;
    }
    return true;
}
