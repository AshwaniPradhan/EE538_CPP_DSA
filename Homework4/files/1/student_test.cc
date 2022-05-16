#include <iostream>
#include <string>
#include <limits.h>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(MyTest, Test1) 
{
    std::vector<std::string> names = {"Shiva", "Peter", "Jackie", "Tian", "Abdul"};
    std::vector<int> grades = {20,10,30,40,60};
    std::vector<Student> students;
    
    for(int i = 0; i < names.size(); i++)
    {
        students.push_back(Student(names[i], grades[i]));
    }
    StudentMaxHeap s = StudentMaxHeap(students);
    EXPECT_EQ(s.GetParent(0).grade, INT_MIN);
    EXPECT_EQ(s.GetParent(1).grade, 60);
    EXPECT_EQ(s.GetParent(3).grade, 40);
    EXPECT_EQ(s.size(),5);
    EXPECT_EQ(s.empty(), false);
    EXPECT_EQ(s.top().grade, 60);
    EXPECT_EQ(s.GetLeft(1).grade, 10);
    EXPECT_EQ(s.GetParent(3).grade, 40);
    
};

TEST(MyTest, Test2) 
{
    std::vector<std::string> names = {"Shiva", "Peter", "Jackie", "Tian", "Abdul", "Ravi", "Zhang", "Lee", "Kiran"};
    std::vector<int> grades = {35, 33, 42, 10, 14, 19, 27, 44, 26};
    std::vector<Student> students;
    
    for(int i = 0; i < names.size(); i++)
    {
        students.push_back(Student(names[i], grades[i]));
    }

    StudentMaxHeap s = StudentMaxHeap(students);
    EXPECT_EQ(s.size(), 9);
    std::string name = "Jen";
    int grade = 31;
    s.push(Student(name, grade));
    EXPECT_EQ(s.size(), 10);
    EXPECT_EQ(s.empty(), false);
    EXPECT_EQ(s.top().grade, 44);
    s.pop();
    EXPECT_EQ(s.GetRight(4).grade, INT_MIN);
    EXPECT_EQ(s.GetLeft(3).grade, 10);
    EXPECT_EQ(s.size(), 9);
    EXPECT_EQ(s.GetParent(1).grade, 42);
    //EXPECT_EQ(s.GetLargestChildIndex(-1), INT_MAX );
    EXPECT_EQ(s.GetLargestChildIndex(3), 8);


}


TEST(MyTEST, Test3_heapsort)
{
    std::vector<std::string> names = {"Shiva", "Peter", "Jackie", "Tian", "Abdul"};
    std::vector<int> grades = {20,10,30,40,60};
    std::vector<int> grades_exp = {10,20,30,40,60};
    std::vector<int> grades1 = {};
    std::vector<Student> students;
    
    for(int i = 0; i < names.size(); i++)
    {
        students.push_back(Student(names[i], grades[i]));
    }
    // HeapSort s = HeapSort(students);
    HeapSort(students);
    for (int j  = 0; j < names.size(); j++)
    {
        grades1.push_back(students[j].grade);
    }
    EXPECT_EQ(grades_exp, grades1);
}

TEST(MyTEST, Test3_heapsort2)
{
    std::vector<std::string> names = {"Shiva", "Peter", "Jackie", "Tian", "Abdul", "g", "h"};
    std::vector<int> grades = {17,25,12,48,23,56,1};
    std::vector<int> grades_exp = {1, 12, 17, 23, 25, 48,56};
    std::vector<int> grades1 = {};
    std::vector<Student> students;
    
    for(int i = 0; i < names.size(); i++)
    {
        students.push_back(Student(names[i], grades[i]));
    }
    // HeapSort s = HeapSort(students);
    HeapSort(students);
    for (int j  = 0; j < names.size(); j++)
    {
        grades1.push_back(students[j].grade);
    }
    EXPECT_EQ(grades_exp, grades1);
}