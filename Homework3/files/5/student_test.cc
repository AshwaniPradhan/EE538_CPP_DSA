#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(SinglyLinkedList, Test1) 
{
    
    std::vector<int> vec1 = {9,1,2,3,3,5,6,7};
    std::vector<int> exp =  {9,1,2,3,5,6,11,11};
    std::vector<int> unique1 =  {9,1,2,3,5,6,11};

    SinglyLinkedList s(vec1);
    
    s.pop_back();
    EXPECT_EQ(s.size(), 7);
    s.push_back(11);
    s.push_back(11);
    s.convert_to_vector();
    s.erase(3);
    EXPECT_EQ(s.convert_to_vector(),exp);
    EXPECT_EQ(s.size(), 8);
    s.remove_duplicates();
    std::vector<int> vec_3=s.convert_to_vector();
    EXPECT_EQ(vec_3, unique1);
}
TEST(SinglyLinkedList, Test2)
{
    std::vector<int> vec1={1,2,3,4,5};
    SinglyLinkedList s(vec1);
    EXPECT_EQ(s.size(),5);
    SinglyLinkedList s_2=s;
    EXPECT_EQ(s_2.size(),5);
    EXPECT_EQ(s.empty(),false);
    EXPECT_EQ(s.head()->val,1);
    EXPECT_EQ(s.head()->next->val,2);
    s.push_back(7);
    EXPECT_EQ(s.size(),6);
    EXPECT_EQ(s_2.size(),5);
    EXPECT_EQ(s.back(),7);
    EXPECT_EQ(s.pop_back(),true);
    EXPECT_EQ(s.size(),5);
    EXPECT_EQ(s.GetBackPointer()->val,5);
    EXPECT_EQ(s.GetBackPointer()->next,nullptr);
    EXPECT_EQ(s.size(),5);
    EXPECT_EQ(s.GetIthPointer(3)->val,4);
    
    EXPECT_EQ(s.GetIthPointer(3)->next->val,5);
    EXPECT_EQ(s[2],3);
    EXPECT_EQ(s.head()->val,1);
    EXPECT_EQ(s.convert_to_vector(),vec1);
    EXPECT_EQ(s.erase(3)->val,3);
    EXPECT_EQ(s.size(),4);
    std::vector<int> test_next={1,2,3,5};
    EXPECT_EQ(s.convert_to_vector(),test_next);
}

TEST(SinglyLinkedList, Test3) 
{
    SinglyLinkedList s;
    s.push_back(2);
    s.push_back(5);
    s.push_back(7);
    s.pop_back();
    s.pop_back();
    s.pop_back();

    //s.convert_to_vector(s);
    EXPECT_EQ(s.size(), 0);
}


