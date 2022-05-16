#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
//push back and size 
TEST(MyVector, Test1) {
    MyVector my_vector;
    //MyVector my_vector2;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.size(),2);
}
//push back, pop and size function
TEST(MyVector, Test2) {
    MyVector my_vector;
    //MyVector my_vector2;
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.pop_back();

    EXPECT_EQ(my_vector.size(),1);
}

//push_front, at, copy constructor, error function check
TEST(MyVector, Test3) 
{
    MyVector vector1;
    vector1.push_front(1);
    vector1.push_front(2);
    EXPECT_EQ(2, vector1.size());
    EXPECT_EQ(ErrorCode::kNoError, vector1.get_error());

    int vect_exp[] = {2,1};
    for (int i = 0; i < vector1.size(); i++)
    {
        EXPECT_EQ(vect_exp[i], vector1.at(i));
    }

    MyVector vector2(vector1);
    vector2.push_front(3);
    int vect_exp2[] = {3,2,1};
    for(int i=0; i<vector2.size(); i++)
    {
        EXPECT_EQ(vect_exp2[i], vector2.at(i));
    } 
}
//convert to std vector check
TEST(MyVector, Test4) {
    MyVector my_vector;
    //MyVector my_vector2;
    my_vector.push_back(1);
    my_vector.push_back(2);
    //my_vector.pop_back();
    my_vector.insert(4,1);
    my_vector.ConvertToStdVector();
    std::vector<int> vec = {1,4,2};

    EXPECT_EQ(my_vector.ConvertToStdVector(),vec);
}
