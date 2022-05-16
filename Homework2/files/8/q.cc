#include <iostream>
#include <vector>
#include<algorithm>
#include <set>


#include "q.h"

// Write a function that takes a vector of positive integers as input. The
// output is the same vector where all duplicates are removed. Note that the
// output is the same vector means the function's return type should be void and
// do the modifications on the input vector. Example: before: v=[1, 2, 2, 4],
// after : v=[1, 2, 4] Solve this for the following cases: You cannot use
// std::set
void CPPLib::UniqueVectorNotBySet(std::vector<int> &input) 
{
    std::vector<int> unique_vec;
    int i;
    for(auto i : input)
    {
        if (std::count(unique_vec.begin(), unique_vec.end(), i) == 0)
        {
            unique_vec.push_back(i);
        }
    }
    input = unique_vec;
}
// You can use std::set
void CPPLib::UniqueVectorBySet(std::vector<int> &input) 
{
    std::set<int> vec;
    int pos =0;
    for(auto &value:input)
    {
        if (vec.count(value) == 0)
        {
            vec.insert(value);
            input[pos++] = value;
        }

    }
    input.resize(pos);
}

// Write a function that takes two vectors v1 and v2 and returns a new vector
// that is the intersection of the values in v1 and v2. All the values in return
// vector should be unique.
// Example: input: v1={1, 2, 2, 3}, v2={3, 4, 4, 5},
// output = {1, 2, 3, 4, 5}
//intersection of sets

std::vector<int> CPPLib::IntersectVectors(std::vector<int> &input1,
                                          std::vector<int> &input2) 
                                          {
                                              std::vector<int> intersection_vec;
                                            //   std::sort(input1.begin(), input1.end());
                                            //   std::sort(input2.begin(), input2.end());
                                            //   std::set_intersection(input1.begin(), input1.end(),input2.begin(), input2.end(), back_inserter(intersection_vec));
                                                std::set<int> input1_set(input1.begin(), input1.end());
                                                std::set<int> input2_set(input2.begin(), input2.end());
                                                for (auto i:input1_set)
                                                {
                                                   if( std::count(input2_set.begin(), input2_set.end(),i)==1)
                                                   {
                                                       intersection_vec.push_back(i);
                                                   }

                                                }

                                              return intersection_vec;

                                          }
