
# HW2 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, Feburary 15th by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -- | -- |
| 1  | 10 |
| 2  | 25 |
| 3  | 20 |
| 4  | 10 |
| 5  | 20 |
| 6  | 25 |
| 7  | 10 |
| 6  | 15 |

- Total: 135 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.


Ques6:

Ans:
    Q1: 
    Ans: Vector is defined but not initialized.
         To read the elements from the input, we need to pushback the element in vector for each element read from the user input given via cin.

    Q2:
    Ans: Pointer initialization is done and now we need to do the memory allocation for the pointer, which we have dynalically allocated in heap memory

    Q3:
    Ans: The dynamic memory allocation done for the a and b pointer has to be cleared at the end, which we are doing using delete function

    Q4:
    Ans: when we increment the pointer a and b, actually location is incremented, which might have any garbage value, so we can use new pointers as c and d, then use them for further operation. In the end we can again release the memmory allocated to all the pointers.

    Q5:
    Ans: i=i-1, creates an infifnite loop, so we can alter that step or we can just remove that step from the code.


Ques 5:
        Question 1: Why did we have to proved size_1, size_2 as an input? 
        Ans: We need the size of the array so that we can dynamically allocate the memory for the array
        Question 2: How can we know the size of the output?- 
        Ans: The given size of input array, will give the idea about final size for the output array 
                     adding the both sizes for given array will provide the size for output array 

        Question 1: Why didn't we provide the sizes? 
        Ans:  We don't need dynamic memory allocation it's taken care by the vector. 
        Question 2: We have two functions with the name of Concatenate. Is this ok? 
        Ans: The input parameters for both the functions are different and return type is also different so it will not cause any error.