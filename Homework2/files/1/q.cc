#include <iostream>
#include <list>
#include <set>
#include <vector>

// Given two separate strings for first and last names, prints the full name.
void PrintFullName(std::string& first_name, std::string& last_name) 
{
  //std::string full_name;
  //full_name = first_name + last_name;
  std::cout<<"The full name is: " <<first_name <<' '<< last_name <<std::endl;
}

// Reads the first and last names from the input and stores them in first_name
// and last_name.
void GetFullName(std::string& first_name, std::string& last_name) 
{
  std::cout<<"Enter the first name: "<<std::endl;
  getline(std::cin, first_name);
  std::cout<<"Enter the last name: "<<std::endl;
  getline(std::cin, last_name);
}

int main() {
  std::string first_name, last_name;
  GetFullName(first_name, last_name);
  PrintFullName(first_name, last_name);
  return 0;
}