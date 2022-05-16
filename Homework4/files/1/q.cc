#include "q.h"

#include <iostream>
#include <vector>
#include <limits.h>
#include <iterator>
#include <algorithm>
//parameterized constructor
Student::Student(std::string name, int grade): name(name), grade(grade)
{}
//non-parameterized constructor
 Student::Student(): name("NO_NAME"), grade(INT_MIN)
 { }

  // Copy constructor. 
  Student::Student(const Student& rhs): name(rhs.name), grade(rhs.grade)
  { }


  // The following operators are overloaded. They only compare the grade part of
  // the class with other objects.

  // Returns true if grade is less than the grade of other Student objects and
  // false otherwise.
  bool Student::operator<(const Student& rhs) const
  {
      if(grade < rhs.grade)
      {
        return true;
      }
      else
      {
        return false;
      }
  }

  // Returns true if grade is greater than the grade of other Student objects
  // and false otherwise.
  bool Student::operator>(const Student& rhs) const
  {
      if(grade > rhs.grade)
      {
          return true;
      }
      else
      {
          return false;
      }

  }

  // Returns true if grade is equal to the grade of other Student objects and
  // false otherwise.
  bool Student::operator==(const Student& rhs) const
  {
      if (rhs.grade == grade)
      {
          return true;
      }
      else
      {
          return false;
      }
  }


  // Parameterized constructor: creates a max heap from the given input.
  StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input)
  {
      //data_ = input;
    //   int size = input.size();
      for(auto i:input)
      {
        push(i);
      }
  }

  // Returns the parent of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful. 
  Student StudentMaxHeap::GetParent(int i)
  {
      if(i == 0)
      {
        return Student();
      }
      else
      {
        return data_[(i-1)/2];
      }
  }

  // Returns the left child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetLeft(int i)
  {
       if(2*i+1 > data_.size()-1)
        {
            return Student();
        }
      //return student
    //   if(i == 0)
    //   {
    //     return Student();
    //   }
      else
      {
        return data_[(2*i) + 1];
      }
  }

  // Returns the right child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetRight(int i)
  {
    if(2*i+2 > data_.size()-1)
    {
        return Student();
    }
    else
    {
        return data_[(2*i) + 2];
    }

  }

  // Returns the index of the parent of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetParentIndex(int i) // check for root parents????????????????????????????????
  {
      if(i==0)
      {
          return INT_MAX;
      }
      else
      {
          return (i-1)/2;
      }

  }

  // Returns the index of the left child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetLeftIndex(int i)
  {
      if(((2*i)+1) > data_.size()-1)
      {
          return INT_MAX;
      }
      else
      {
          return ((2*i)+1);
      }
  }

  // Returns the index of the right child of a n45ode given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetRightIndex(int i)
  {
      if(((2*i)+2) > data_.size()-1)
      {
          return INT_MAX;
      }
      else
      {
          return ((2*i)+2);
      }

  }

  // Returns the index of the largest child of a node given its index in the
  // tree. Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetLargestChildIndex(int i)
  {
      int left_index = GetLeftIndex(i);
      int right_index = GetRightIndex(i);

      if(left_index == -1 && right_index == -1)
      {
          return INT_MAX;
      }

      if(GetRight(i) > GetLeft(i))
      {
          return GetRightIndex(i);
      }
      else
      {
          return GetLeftIndex(i);
      }

  }

  // Returns the top of the heap. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::top()
  {
      if(data_.size() == 0)
      {
          return Student();
      }
      else
      {
          return data_[0];
      }
  }

  // Adds a new Student to the heap.
  void StudentMaxHeap::push(const Student& student)
  {
      data_.push_back(student);
      TrickleUp(data_.size() - 1);
  }

  // Removes the top. Returns
  // true if successful and false otherwise.
  bool StudentMaxHeap::pop()
  {
      if(data_.size() == 0)
      {
          return false;
      }
      data_[0] = data_.back();
      data_.pop_back();
      TrickleDown(0); // check data_size>0???
      return true;
  }

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void StudentMaxHeap::TrickleUp(int i)
  {
      while (i!= 0 && (data_[i] > GetParent(i)))
      {
        //   std::swap(data_[i], GetParent(i));
        //   i=GetParentIndex(i);
        Student temp;
        temp =  data_[i];
        data_[i] = data_[GetParentIndex(i)];
        data_[GetParentIndex(i)] = temp;
        i = GetParentIndex(i);
      }

  }

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void StudentMaxHeap::TrickleDown(int i)
  {
      if(GetLeftIndex(i) > data_.size() && (GetRightIndex(i) > data_.size()))
      {
          return;
      }
      int max_index = GetLargestChildIndex(i);
      if(data_[i] < data_[max_index])
      {
          std::swap(data_[i], data_[max_index]);
          TrickleDown(max_index);
      }

  }

  // Converts the given input into a max heap and stores that into data_.
  void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input)
  {
    for(auto i:input)
    {
      push(i);
    }
  }


// Sorts the given input vector of students in place. The sort is in ascending
// // order based on the grades.
// void heapify(std::vector<Student> inp_vec, int n, int i)
// {
//     int max = i; // initialize max as root
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;
//     // if left child has larger value than root value
//     if(left < n && inp_vec[left].grade > inp_vec[max].grade)
//     {
//         max = left;
//     }
//     // if right child is largest
//     if(right < n && inp_vec[right].grade > inp_vec[max].grade)
//     {
//         max = right;
//     }
//     //if largest is not root
//     if (max != i)
//     {
//         std::swap(inp_vec[i], inp_vec[max]);
//          // recusively heapifyig the affected sub tree
//         heapify(inp_vec, n, max);
//     }
   
    
// }
// void HeapSort(std::vector<Student>& input)
// {
//     int n = input.size();
//     //buiding heap
//     for (int i = (n/2) - 1; i >= 0; i--)
//     {
//         //std::swap(input[0], input[i]);
//         heapify(input, n ,i);
//     }
//   // One by one extract an element from heap and rearrane in ascending order
// 	for (int i = n - 1; i >= 0; i--) 
//     {
// 		// Move current root to end
// 		std::swap(input[0], input[i]);

// 		// call max heapify on the reduced heap
// 		heapify(input, i, 0);
// 	}
// }

void HeapSort(std::vector<Student>& input)
{
    StudentMaxHeap s;
    s.ConvertToHeap(input);
    std::vector<Student> res;
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    std::reverse(res.begin(), res.end());
    input = res;

}
