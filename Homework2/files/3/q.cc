#include "q.h"
#include<iostream>

// Given two integers, returns the result of the operation based on the given
// operator.


float CPPLib::Calculate(int a, int b, Operation operation) 
{
    int n;


    switch(operation)
    {
        case Operation::add: return (a+b); break;
        case Operation::subtract: return (a-b); break;
        case Operation::division: 
                            if(b==0) //divide by zero
                            {
                                return -1;
                            }
                            else
                            {
                                return (a/b);
                            }
                            break;
        case Operation::multiplication: return (a*b); break;
        case Operation::bitwise_AND: return (a&b); break;
        case Operation::bitwise_OR: return (a|b); break;
        case Operation::bitwise_XOR: return (a^b); break;
        case Operation::shift_right: return (a>>b); break;
        case Operation::shift_left: return (a<<b); break;
        default: return -1;

    }
    
}
