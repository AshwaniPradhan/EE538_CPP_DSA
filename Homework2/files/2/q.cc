#include "q.h"

#include <iostream>
#include <string>

// Returns the index of the first space character in a string.
int CPPLib::IndexOfFirstSpace(std::string& input) 
{
    int str_size = input.size();
    int  i;
    int pos = 0;
    for (i=0; i <= str_size; i++)
    {
      if (input[i] == ' ')
      {
        pos = i;
        break;
      }
      else
      {
        pos+=1;
        //i++;
      }
      if (input[i] != ' ')
      {
        pos = -1;
      }
    }
    return pos;
}

// Given the full_name, it returns the first_name and last_name.
// Note: you should use IndexOfFirstSpace function and cannot use any other
// std:: functions.
void CPPLib::SeparateFirstAndLastNames(std::string& full_name,
                                       std::string& first_name,
                                       std::string& last_name) 
                                       {
                                           int post;
                                           int i;
                                           int str_size = full_name.size();
                                           post = IndexOfFirstSpace(full_name);
                                          
                                        if (post == -1)
                                        {
                                            for (i=0; i< str_size; i++)
                                            {
                                                 first_name.push_back(full_name[i]);

                                            }
                                        }
                                        else
                                        {

                                            for (i=0; i< post ; i++)
                                            {
                                                 first_name.push_back(full_name[i]);

                                            }
                                            for(i=post+1; i < str_size; i++)
                                            {
                                                last_name.push_back(full_name[i]);
                                            }
                                        }
                                           //first_name = full_name.substr(0,post);
                                           //last_name = full_name.substr(post+1);
                                       }

// Returns the number of vowles (a, e, i, o, u) in a string.      
int CPPLib::NumberOfVowels(std::string& input) 
{
    int str_size;
    str_size = input.size();
    int i, count=0;
    for(i = 0; i < str_size; i++)
    {
        if ((input[i] == 'a') || (input[i] == 'e') || (input[i] == 'i') || (input[i] == 'o') || \
            (input[i] == 'u') || (input[i] == 'A') || (input[i] == 'E') || (input[i] == 'I') || (input[i] == 'O') || (input[i] == 'U'))
        {
            count++;
        }
        // else
        // {
        //     return -1;
        // }
    }
    return count;

}

// Returns the number of consonants (letters that are not a, e, i, o, u) in a
// string.
int CPPLib::NumberOfConsonants(std::string& input) 
{
    int str_size;
    str_size = input.size();
    int num_vowel = NumberOfVowels(input);
    int num_consonants;
    num_consonants = str_size - num_vowel;
    return num_consonants;

}

// Returns the revers of a string.
// Example input: 'ted', output: 'det'.
// Note: You cannot use any std:: functions.
int CPPLib::Reverse(std::string& input)
{
    int str_size;
    str_size = input.size();
    int i;
    std::string reverse_str;

    if(str_size == 0)
    {
        return -1;
    }
    else
    {
    for (i = str_size; i>=0; i--)
        {
            reverse_str.push_back(input[i]);
        }
    input = reverse_str;
    return 1; // if its reveresed then return 1
    }
    //std::cout<<reverse_str<<std::endl;

}
