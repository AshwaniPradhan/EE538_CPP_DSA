#include "q.h"

#include <iostream>
#include <vector>
#include <limits.h>
// Implement each function of `q.h` here.

// Given a vector of weights and values and an integer value representing total
// capacity of a knapsack, implement the following function.

// The knapSack01NoDynamicProgramming function does not use Dynamic Programming
// and it is not a recursive function. Instead it calls a recursive function
// knapSack01NoDynamicProgramming_Helper (which is also not using dynamic
// programming).

// 1. Implement knapSack01NoDynamicProgramming:
int knapSack01NoDynamicProgramming(const std::vector<int> &weights,
                                   const std::vector<int> &values, int w)
                                   {
                                       int i = weights.size();
                                       return knapSack01NoDynamicProgramming_Helper(weights, values, w, i);
                                       
                                   }

// 2. Define knapSack01NoDynamicProgramming_Helper and implement it in the .cc
// file. This function has takes similar arguments like
// knapSack01NoDynamicProgramming with some extra helper parameters:
int knapSack01NoDynamicProgramming_Helper(const std::vector<int> &weights,
                                          const std::vector<int> &values, int w,
                                          int i)
                                          {
                                              if(i == 0 || w == 0)
                                              {
                                                return 0;
                                              }
                                              if(weights[i-1] > w)
                                              {
                                                  return knapSack01NoDynamicProgramming_Helper(weights, values, w, i-1);
                                              }
                                              else if (weights[i-1] <= w)
                                              {
                                                  return std::max(knapSack01NoDynamicProgramming_Helper(weights, values, w, i-1), 
                                                                    values[i-1] + knapSack01NoDynamicProgramming_Helper(weights,values, w - weights[i-1], i -1) );
                                              }
                                          }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3. Implement knapSack01Memo:

// The knapSack01Memo function itself doesn't use a memo. It's just a wrapper
// around knapSack01Memo_Helper.
int knapSack01Memo(const std::vector<int> &weights,
                   const std::vector<int> &values, int w)
                   {
                       int n=weights.size();
                        std::vector<std::vector<int>> vec (n+1,std::vector<int> (w+1, INT_MIN));
                        return knapSack01Memo_Helper(weights, values, w, n, vec);

                   }

// 4. Implement knapSack01Memo_Helper. This function has takes similar arguments
// like knapSack01Memo with some extra helper parameters such as i and memo,
// which is a two-dimensional vector:
int knapSack01Memo_Helper(const std::vector<int> &weights,
                          const std::vector<int> &values, int w, int i,
                          std::vector<std::vector<int>> &memo)
                          {


                            if(i == 0 || w == 0)
                                {
                                return 0;
                                }
                            if ( memo [i][w] != INT_MIN)
                            {
                                return memo[i][w];
                            }
                            else if(memo[i][w]==INT_MIN){
                                if(weights[i-1] <= w)
                                {
                                    return memo[i][w] = std::max(knapSack01Memo_Helper(weights, values, w, i-1, memo), 
                                                    values[i-1] + knapSack01Memo_Helper(weights,values, w - weights[i-1], i -1, memo ));  
                                    
                                }
                                else
                                {return memo[i][w] = knapSack01Memo_Helper(weights, values, w, i-1, memo);
                                }
                            }

                          }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 3. Implement knapSack01Tablulation. Use a two-dimensional vector for the
// table.
int knapSack01Tablulation(const std::vector<int> &weights, const std::vector<int> &values, int w)
{
    //shifting the 2d vector by 1 
    std::vector<std::vector<int>> d(values.size() + 1 , std::vector<int> (w + 1, 0) );
    //so d[0][w] menas no item being used and d[i][w] means using items 1 to i
    //anyways values and weights vector starts from index 0

    for(int i = 0; i <= weights.size(); i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0)
            {
                d[i][j] = 0;
            }
            else if (weights[i-1] > j)
            {
                d[i][j] = d[i-1][j];
            }
            else
            {
                d[i][j] = std::max(values[i - 1] + d[i - 1][j - weights[i-1]], d[i-1][j]);
            }
            
        }
    }
    return d[values.size()][w];

}