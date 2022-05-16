#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.

// Implement your own Queue class!
// TODO: Implement these functions in q.cc.

  // Copy constructor.
  Queue::Queue(const Queue& rhs)
  {
      v_ =  rhs.v_;

    //   for (int i = 0; i < rhs.size(); i++)
    //   {
    //       v_.push_back(rhs[i]);       
    //   }
  }

  // Inserts in the back of the queue.
  bool Queue::Enqueue(int value)
  {
      //std::cout<<"inserting" << value <<std::endl;
      v_.push_back(value);
      return true;
  }

  // Removes from the front of the queue. If the queue is empty, return false,
  // otherwise true.
  bool Queue::Dequeue()
  {
      int v_size = v_.size();
      if(IsEmpty())
      {
          return false;
      }
      else 
      {
        v_.erase(v_.begin());
        return true;
      }
  }

  // Returns true if the queue is empty.
  bool Queue::IsEmpty()
  {
    return v_.empty();
  }

  // Returns the value in the front of the queue. If the queue is empty, return
  // -1.
  int Queue::Front()
  {
    if(IsEmpty())
    {
        return -1;
    }
    else
    {
        return v_[0];
    }
}