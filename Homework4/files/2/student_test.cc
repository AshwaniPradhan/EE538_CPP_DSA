#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyTest, Test1) 
{
    int n=5;
    //int fib_num = Fibonacci(n);
    //int expected = 1;
    EXPECT_EQ(Fibonacci(n), 5);
}

TEST(MyTest, Test2) 
{
    int n=5;
    //int fib_num = Fibonacci(n);
    //int expected = 1;
    EXPECT_EQ(Fibonacci(6), 8);
    EXPECT_EQ(Fibonacci(0), 0);
    EXPECT_EQ(Fibonacci(1), 1);
    EXPECT_EQ(Fibonacci(7), 13);
}
/////////////////////////////////////////////////////////////////////////

TEST(MyTest, CoinChangeMemo1)
{
    std::vector<int> coins= {10, 25, 5};
    int amount = 30;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 2);

}
TEST(MyTest, CoinChangeMemo2)
{
    std::vector<int> coins= {1,2,3};
    int amount = 4 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 2);
}

TEST(MyTest, CoinChangeMemo3)
{
    std::vector<int> coins= {11, 22, 33, 44};
    int amount = 33 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 1);
}

TEST(MyTest, CoinChangeMemo4)
{
    std::vector<int> coins= {11, 22, 33, 44};
    int amount = 0 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 0);
}

TEST(MyTest, CoinChangeMemo6)
{
    std::vector<int> coins= {1, 2, 5};
    int amount = 11 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 3);
}

TEST(MyTest, CoinChangeMemo5)
{
    std::vector<int> coins= {1};
    int amount = 4 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 4);
}
TEST(MyTest, CoinChangeMemo9)
{
    std::vector<int> coins= {12};
    int amount = 4 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), -1);
}

TEST(MyTest, CoinChangeMemo7)
{
    std::vector<int> coins= {1, 2, 3};
    int amount = 6 ;

    EXPECT_EQ(CoinChangeMemo(coins, amount), 2);
}


/////////////////////////////////////////////////////////////////////////
TEST(MyTest, CoinChangeMemoTab1)
{
    std::vector<int> coins= {10, 25, 5};
    int amount = 30;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 2);

}// passing

TEST(MyTest, CoinChangeMemoTab2)
{
    std::vector<int> coins= {1,2,3};
    int amount = 4 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 2);

}// this is failing

TEST(MyTest, CoinChangeMemotab3)
{
    std::vector<int> coins= {11, 22, 33, 44};
    int amount = 33 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 1);
}

TEST(MyTest, CoinChangeTabulationtab4)
{
    std::vector<int> coins= {11, 22, 33, 44};
    int amount = 0 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 0);
}

TEST(MyTest, CoinChangeTabulationtab6)
{
    std::vector<int> coins= {1, 2, 5};
    int amount = 11 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 3);
}

TEST(MyTest, CoinChangeTabulationtab5)
{
    std::vector<int> coins= {1};
    int amount = 4 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 4);
}

TEST(MyTest, CoinChangeTabulationtab7)
{
    std::vector<int> coins= {1, 2, 3};
    int amount = 6 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), 2);
}

TEST(MyTest, CoinChangetab9)
{
    std::vector<int> coins= {12};
    int amount = 4 ;

    EXPECT_EQ(CoinChangeTabulation(coins, amount), -1);
}