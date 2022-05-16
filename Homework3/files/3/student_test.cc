#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyQueue, Test1) 
{
    Queue q;
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(8);
    EXPECT_EQ(q.Enqueue(9), true);
    EXPECT_EQ(q.Dequeue(), true);
    int val;
    val = q.Front();
    EXPECT_EQ(val, 5);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    
    EXPECT_EQ(q.IsEmpty(), true);

}

TEST(MyQueue, Test2) 
{
    Queue q;
    std::vector<int> vec = {1,2,4};
    q.Enqueue(7);
    q.Enqueue(11);
    q.Enqueue(13);
    EXPECT_EQ(q.Enqueue(15), true);
    EXPECT_EQ(q.Dequeue(), true);
    int val;
    val = q.Front();
    EXPECT_EQ(val, 11);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    
    EXPECT_EQ(q.IsEmpty(), true);
}



