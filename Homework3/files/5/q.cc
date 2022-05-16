#include "q.h"

#include <iostream>
#include <vector>
#include<set>
// Implement each function of `q.h` here.


  // *********************************************************************
  // TODO: Implement the following functions in q.cc.
  // *********************************************************************
  // Write a new parameterized constructor that takes a vector as an input and
  // crates a linked list based on that. Note that your constructor should
  // assign a valid value for head_. Example:
  // Input:  v = {1, 4, 5, 6, 10}
  // The created list: 1->4->5->6->10, and head_ will point to the first node
  // with value 1.
  SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v)
  {
      size_ = 0;
      if(v.size() > 0)
      {
          int vec_size = v.size();
          //size_++;
          head_ = new ListNode(v[0]);
          size_++;
          ListNode * ptr1 = head_;
          for (int i = 1; i < (vec_size); i++)
          {
              ListNode* ptr2 = new ListNode(v[i]);
              ptr1->next = ptr2;
              ptr1 = ptr1->next;
              size_++;
          }
      }
  }

  // Copy constructor.
  SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs)
  {
      size_ = 0;
      if(rhs.head_ != nullptr)
      {
          ListNode* ptr1 = rhs.head_;
          ListNode* ptr2;
          ListNode* ptr3 = new ListNode(ptr1->val);
          head_ = ptr3;
          size_++;
          ptr2 = head_;

          while (ptr1->next != nullptr)
          {
            ptr1 = ptr1->next;
            ListNode* ptr3 = new ListNode(ptr1->val); 
            ptr2->next = ptr3;
            ptr2 = ptr3;
            size_++;
          }
          
      }
  }

  // Returns true if the list is empty, false otherwise.
  bool SinglyLinkedList::empty()
  {
    if(head_ == nullptr)
    {
        return true;
    }
    return false;
  }
  //listnode *p->next == nullptr??

  // Returns the current size of the list.
  int SinglyLinkedList::size()
  {
      return size_;
  }

  // Returns a pointer to the head of the list.
  ListNode* SinglyLinkedList::head()
  {
      return head_;
  }

  // Insert i at the back of the list.
  void SinglyLinkedList::push_back(int i)
  {
      if (head_ == nullptr){
          head_ = new ListNode(i);
          size_ = 1;
          return;
      }
      ListNode* p = GetBackPointer();
      ListNode* new_node = new ListNode(i);
      p->next = new_node;
      size_++;
  }

  // Removes an item from the back of the list. Returns true if it was
  // successfull.
  bool SinglyLinkedList::pop_back()   ////////////////////////////////////////////////
  {
     if (size_ == 0)
    {
      return false;
    }
    else if (size_ == 1)
    {
      head_ = nullptr;
      size_ = 0;
      return true;
    }
    else
    {
      //int* new_data = new int[size_ - 1];
      ListNode *ptr1 = head_;
      ListNode *ptr2 = ptr1->next;
      while(ptr2->next != nullptr)
      {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;        
      }
      // delete ptr2;
      ptr1->next = nullptr;
      size_--;
      return true;

    //   int res=data_[size_-1];
    //   delete data_;
    //   data_=new_data;

    }
  }

  // Returns the item in the back of the list. Returns -1 if empty.
  int SinglyLinkedList::back()
  {
      if (size_ == 0) // or head_ is pointing to nullptr
      {
        return -1;
      }
      else
      {
          ListNode *temp=head_;
          while(temp->next != nullptr)
          {
            temp = temp->next;
          }
          return temp->val;
      }
  }

  // Returns a pointer to the back of the list.
   ListNode* SinglyLinkedList::GetBackPointer()
   {
       ListNode *ptr=head_;
       while(ptr->next != nullptr)
       {
           ptr = ptr->next;
       }
       return ptr;

   }

  // Returns a pointer to the i(th) element in the list. nullptr if it doesn't
  // exist.
  ListNode* SinglyLinkedList::GetIthPointer(int i)
  {
      ListNode *ptr = head_;
      for(int j = 0; j< i; j++)
      {
          ptr = ptr->next;
      }
      return ptr;
  }

  // Returns the i(th) element in the list. -1 if it doesn't exits.
  int & SinglyLinkedList::operator[](int i)
  {
      if(GetIthPointer(i)==nullptr){
          return minus_;
      }
      else
      {
          return GetIthPointer(i)->val;
      }
  }

  // Prints the items in the list.
  void SinglyLinkedList::print()
  {
      ListNode *temp = head_;
      if(head_ == nullptr)
      {
        std::cout<<"The list is empty";
      }
      while(temp != nullptr)
      {
          std::cout << temp->val << " ";
          temp = temp->next;
      }
  }

  // Write a function that converts the list into a vector. Example:
  // The list: 1->4->5->6->10
  // Output: a vector with value: {1, 4, 5, 6, 10}
  std::vector<int> SinglyLinkedList::convert_to_vector()
  {
      std::vector<int> res_vec={};
      if (head_ == nullptr)
      {
          return res_vec;
      }
      else{
      ListNode* ptr = head_;
      while (ptr != nullptr)
      {
          res_vec.push_back(ptr->val);
          ptr = ptr->next;
      }
      return res_vec;
      }
  }

  // Erases element i from the list if it exists and returns a pointer to item
  // i-1. If item i doesn't exist, returns nullptr. The first item in the list
  // has index 0.

  // Example:
  // Input: 1 -> 5 -> 10 ->20, i= 2.
  // Output: 1 -> 5 -> 20, return value: a pointer to element 5.
  ListNode* SinglyLinkedList::erase(int i)
  {
      if(i > size()-1 || (i == 0 && size() == 0))
      {
          return nullptr;
      }
      ListNode* ptr = head_;

      if(i == 0)
      {
          if(ptr->next != nullptr) // for more than one nodes
          {
              ListNode* ptr_next = ptr->next;
              delete head_;
              head_ = ptr_next;
          }
          //only one node
          else
          {
              delete head_;
              head_ = nullptr;
          }
          size_--;
          return nullptr;
      }
      else
      {
          //pointer point to i-1
          for (int j = 0; j < i-1; j++)
          {
              ptr = ptr->next;
          }
          //if need to delete the last node
          if(ptr->next->next == nullptr)
          {
              delete ptr->next;
              ptr->next = nullptr;
          }
          //if we have one more node after the deleted node
          else
          {
              ListNode* ptr_new_next = ptr->next->next;
              delete ptr->next;
              ptr->next = ptr_new_next;
          }
          size_--;
          return ptr;

      }
  }

  // Removes duplicate elements and only keeps the first one.
  // Example:
  // Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32
  // Output: 1 -> 5 -> 20 -> 4 -> 32
  void SinglyLinkedList::remove_duplicates()
  {
      std::set<int> new_set = {}; // set for unique elements 
      ListNode* ptr = head_;
      int i = 0;
      while(ptr->next != nullptr)
      {
          if(new_set.find(ptr->val) == new_set.end())
          {
              new_set.insert(ptr->val);
              ptr = ptr->next;
              i++; //incrementing index if the node need not to be deleted
          }
          else
          {
              ptr = ptr->next;
              ListNode* last = erase(i);
              last->next = ptr;

          }
      }
    //last node
        if(new_set.find(ptr->val) != new_set.end())
        {
            erase(i);
        }
  }