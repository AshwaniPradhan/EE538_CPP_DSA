#include "q.h"

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include<limits.h>
// Implement each function of `q.h` here.

// TODO: Implement the following functions in q.cc.

// Given a non-negative integer n, Implement a function that calculates the
// n(th) Fibonacci number.

// Your implementation should have a worst case runtime complexity of O(n) and
// memory complexity of O(1).
int Fibonacci(int n)
{
    int first_num = 0;
    int second_num = 1;
    int temp , i;

    if (n == 0)
    {
        return first_num;
    }
    if(n == 1)
    {
      return second_num;
    }
    for(i = 2; i <= n; i++)
    {
        temp = first_num + second_num;
        first_num = second_num;
        second_num = temp;
    }
    return second_num;
}

//-----------------------------------------------------------------------------
// Remember the Coin Change Problem:

// Given n different coin types and an integer representing the total amount of
// money, find the minimum number of coins to make up that amount. You can use
// as many coins as you want from each coin type.

// Example:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
//-----------------------------------------------------------------------------

// Implement a function that calculates the minimum number and use memoization
// but with a twist: you are only allowed to use an std::list for the memo (Do
// not use map, unordered_map, set, vector, or array).

// CoinChangeMemo is not a recursive function, but it is a wrapper around
// CoinChangeMemo_Helper that is recursive. Use std::list<int> for memo.
int CoinChangeMemo(std::vector<int>& coins, int amount)
{
    std::list<int> memo;
    return CoinChangeMemo_Helper(coins, amount, memo);
}

int CoinChangeMemo_Helper(std::vector<int>& coins, int amount, std::list<int>& memo)
{
  // Coins for base condition
    if (amount == 0)
      return 0; 
    if (amount < 0)
      return -1;

    // Initialize iterator
    std::list<int>::iterator iter;

    // Set iterator to start of list
    iter = memo.begin();

    // If list size is greater than amount, amount is already initialized
    // if (memo.size() > amount) {
    //   std::advance(iter, amount); 
    //   return *iter;
    // }

    // Add elements at the end till amount is reached to initialize list till list[amount]
    // Initialization happens only once because memo.size() will be same as list[amount] after first iteration
    for (int i = memo.size();i<=amount;++i) {
      memo.push_back(INT_MIN);
    }


    int count = INT_MAX;
    for (int i=0; i < coins.size(); i++)
    {
      int coinValue = coins[i];

      // Compare value and add minimum recursively by putting in the amount difference similar to class example
      int n = CoinChangeMemo_Helper(coins, amount - coinValue, memo);
      if(n >= 0) {
        count = std::min(n, count);
      } 
    }

    // Add memoized value to array
    iter = memo.begin(); 
    advance(iter, amount);
    if (count >= 0 && count < INT_MAX) {
        *iter = count+1;
      
    }
    else {
      // Not possible
      *iter = -1;
    }

    return *iter; 
}

// Implement a function that calculates the minimum number and use tabulation
// but with a twist: you are only allowed to use an std::list for the table
// inside this function (Do not use map, unordered_map, set, vector, or array):
int CoinChangeTabulation(std::vector<int>& coins, int amount)
{
    std::list<int> amt_list(amount + 1);
    
    // Initialize iterator
    std::list<int>::iterator iter;

    // Set iterator to start of list
    iter = amt_list.begin();
    
    //amt_list[0] = 0
    *iter = 0;
    
    
    for (int i = 1; i <= amount; i++) {
        //amt_list[i]
        iter = amt_list.begin();
        advance(iter,i);
        *iter = INT_MAX-1; 
       
        // Second iterator for amt_list[i-coin]
        std::list<int>::iterator iter2;
        
        for (auto coin : coins) {
            if (i - coin >= 0) {
                iter2 = amt_list.begin();
                advance(iter2,i-coin);
                *iter = std::min(*iter2 + 1,*iter);
            }
        }   
   }
    
    iter = amt_list.begin();
    advance(iter,amount); 
    return *iter > amount ? -1 : *iter;
}

