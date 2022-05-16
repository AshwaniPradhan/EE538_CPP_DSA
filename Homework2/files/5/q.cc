#include "q.h"

#include <iostream>
#include <vector>


// Concatenate two dynamic arrays.
// Example:
// array_1 = {1, 2}, size_1 = 2
// array_2 = {2, 3, 4}, size_12 = 3
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why did we have to proved size_1, size_2 as an input? --Ans::  We need the size of the array so that we can dynamically allocate the memory for the array
// Question 2: How can we know the size of the output?- Ans:: The given size of input array, will give the idea about final size for the ouput array 
//i.e. adding the both sizes for given array will provide the size for output array 
int* CPPLib::Concatenate(int* array_1, int size_1, int* array_2, int size_2) 
{
    if((size_1+size_2)==0)
    {
        return nullptr;
    }
    int *result = new int[size_1 + size_2];
    std::copy(array_1, array_1+size_1, result);
    std::copy(array_2, array_2 + size_2, result +size_1);
    return result;
}
//-----------------------------------------------------------------------------
// Concatenate two dynamic vectors.
// Example:
// vector_1 = {1, 2}
// vector_2 = {2, 3, 4}
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why didn't we provide the sizes? -- we dont need dynamic memory allocation its taken care by the vector
// Question 2: We have two functions with the name of Concatenate. Is this ok? - the input parameters for both the functions are different 
std::vector<int> CPPLib::Concatenate(std::vector<int>& vector_1,
                                     std::vector<int>& vector_2) 
                                     {
                                         std::vector<int> result;
                                         result.reserve(vector_1.size() + vector_2.size());
                                         result.insert(result.end(), vector_1.begin(), vector_1.end());
                                         result.insert(result.end(), vector_2.begin(), vector_2.end());
                                         return result;
                                     }
//-----------------------------------------------------------------------------
