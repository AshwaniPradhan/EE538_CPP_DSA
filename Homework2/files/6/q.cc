#include <iostream>
#include <vector>

// Returns element at i index.
int ReturnElementI(std::vector<int>& input, int i) { return input[i]; }

// - What is wrong with each piece of code below?
// - For each case modify the code so that the issue is fixed:
int main() {
  // Question 1: To read the elements from the input, we need to pushback the element in vector for each element read from the user input
  {
    std::vector<int> elements;

    // Number of values to read from the input
    int number_of_items;
    std::cin >> number_of_items;

    // Reading elements from the input.
    for (int i = 0; i < number_of_items; i++) {
      int element;
      std::cin >> element;
      elements.push_back(element); // to read the elements from the input we need to pushback the element in vector
      //std::cin >> elements[i];
    }
  }

  // Question 2: Memory allocation is required for the pointer initialization; 
  {
    int* a = new int(); // memory allocation is required
    std::cin >> (*a);
    (*a)++;
    std::cout << "(*a): " << (*a) << std::endl;
  }

  // Question 3:
  {
    int* a = new int;
    int* b = new int;
    std::cin >> (*a);
    std::cin >> (*b);

    std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
    delete a; // clearing the memory
    delete b;
  }

  // Question 4:
  {
    int* a = new int;
    int* b = new int;
    std::cin >> (*a);
    std::cin >> (*b);
    std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;

    //a++;
    //b++;
    int* c = new int;
    int* d = new int;
    std::cin >> (*c);
    std::cin >> (*d);
    std::cout << "(*a) + (*b): " << (*c) + (*d) << std::endl;
    delete a;
    delete b;
    delete c;
    delete d;
  }

  // Question 5:
  {
    for (int i = 0; i < 10; i++) {
      std::cout << "i: " << i << std::endl;
      //i = i - 1; -- it will create a infinite loop
      // we can use any other steps eg; i=i+1 or i+2 or just remove this line
      i=i+2;
      std::cout << "i: " << i << std::endl;
    }
  }

  return 0;
}