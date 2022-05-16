
# HW3 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, March 1st by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -- | -- |
| 1  | 28 |
| 2  | 15 |
| 3  | 30 |
| 4  | 32 |
| 5  | 30 |


- Total: 135 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.


Question: 4

Answers:

Q1 Output:

Q1
Non-parameterized constructor
o1.v_.size(): 0
Destructor

Explanation:
L1: The initial print specifies the question index as Q1.
L2: MyClass o1 is a call without any parameters being passed. This calls the non parameterized constructor which has the appropriate print statement.
L3: Since the non-parameterized constructor is being called, there is no initilization of the vector. This results the size of vector to be 0.
L4: As the scope ends at line 95, the local variable o1 is being freed by the operating system. This initiates the destructor sequence of MyClass for it's object o1.

---------------------------------------------------------------
Q2 Output:

Q2
Non-parameterized constructor
Parameterized constructor
Copy constructor
Destructor
Destructor
Destructor

Explanation:
L1: The initial print specifies the question index as Q2.
L2: Similar to Q1, we create an object of MyClass without providing any parameters, this calls the non-parameterized constructor of MyClass.
L3: Now, we create object o2 as parameterized constructor with parameters 1, 3. This calls the relevant print statement.
L4: The object o3 is created as a copy of o1, that is, this is a special type of parameterized constructor taking it's own type as a paramter to create a copy.
L5-8: Since there are 3 local objects o1, o2, and o3. The OS proceeds to cleanup as the scope ends, this calls the destructor for each object of MyClass individually to free there individual resources.


---------------------------------------------------------------
Q3 Output:

Q3
Non-parameterized constructor
Copy constructor
Something 1.
Destructor
Destructor

Explanation:
L1: The initial print specifies the question index as Q3.
L2: Object o is created without any initial parameters, this calls the non-parameterized constructor of MyClass.
L3: The function DoSomething1 uses a pass by value method, this causes the program to create a copy of object o inside DoSomething1, thus calling the copy constructor.
L4: As function DoSomething1 goes out of scope the local variable which was created as explained in L3 is now being destructed.
L5: As the question block goes out of scope, the local variable o is being desctructed.


---------------------------------------------------------------
Q4 Output:

Q4
Non-parameterized constructor
Something 2.
Destructor

Explanation:
L1: This initial print specifies the question index as Q4.
L2: Object o is created without any initial parameters, this calls the non-parameterized constructor of MyClass.
L3: The function DoSomething2 is called as a pass by reference and the print statement is printed. 
L4: As the local variable o of question block goes out of scope, the program calls the destructor to cleanup its resources.

The output is difference from Q3 since in Q4, pass by reference is used. This simply uses the same variable and same address for the local to function variable o. In Q3 pass by value was used which creates a copy of the parameter being passed. 

---------------------------------------------------------------
Q5 Output:

Q5
Non-parameterized constructor
Something 3.
Destructor

Explanation:
This is same as Q4

---------------------------------------------------------------
Q6 Output:

Q6
Non-parameterized constructor
Copy constructor
Something 4.
Destructor
Destructor

Explanation:
L1: This initial print specifies the question index as Q6.
L2: Object o is created without any initial parameters, this calls the non-parameterized constructor of MyClass.
L3: DoSomething4 is a function which has pass by reference, hence the object o is not copied. In the function DoSomething4, we copy o to create o2 which calls the copy constructor. 
L4: Since function DoSomething4 goes out of scope, the destructor of o2 is being called.
L5: As the question block goes out of scope, the destructor for o is being called to free its resources.


---------------------------------------------------------------
Q7 Output:

Q7
Parameterized constructor
Copy constructor
Destructor
p1.first.v_.size(): 0
p1.second: 0
Copy constructor
p2.first.v_.size(): 0
p2.second: 0
Destructor
Destructor

Explanation:
L1: This initial print specifies the question index as Q7.
L2: The RHS in statement with first std::pair calls the MyClass object creation with parameters, this calls the paramterized constructor
L3: As the MyClass(1, 2) has been created, it is now copied to the first index of p1. This initiates the copy constructor.
L4: As the program counter moves from statement std::pair, it destructs the object created in RHS.
L5: Since the vector in MyClass object not yet initialized, the size of 0.
L6: The second value is 0 since it is set so in the first std::pair line.
L7: Since p2=p1, this internally does p2.first = p1.first. This would be a call to copy constructor.
L8: Similar to p1, p2's vector is also size 0.
L9: Similar to p1, the second value is 0 as well.
L10: As p1 and p2 go out of scope, there respective desctructors are being called. 

---------------------------------------------------------------
Q8 Output:

Q8
Parameterized constructor
Copy constructor
Destructor
Something 2.
Something 2.
Something 2.
Destructor

Explanation:
L1: This initial print specifies the question index as Q8.
L2: The RHS in std::pair has MyClass(1,2) which calls a parameterized constructor.
L3: This is being copied to first value of p which is a copy constructor.
L4: After the copy is completed, the MyClass(1,2) object shall be destructed.
L5-7: Since the loop iterates for 3 count, DoSomething2 is to be called 3 times. Since DoSomething2 is a pass by refernce, no copy is being created.
L8: Since only  

---------------------------------------------------------------
Q9 Output:

Q9
Parameterized constructor

L1: This initial print specifies the question index as Q9.
L2: *o is a pointer of type MyClass. The dynamic allocation with a parameters calls the parameterized constructor.

---------------------------------------------------------------
Q10 Output:

Q10
Parameterized constructor
Destructor

L1: This initial print specifies the question index as Q10.
L2: *o is a pointer of type MyClass. The dynamic allocation with a parameters calls the parameterized constructor.
L3: Delete the dynamically allocated *o which calls the destructor. This delete is necessary to avoid memory leak.

---------------------------------------------------------------
Q11 Output:

Q11
Non-parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Copy constructor
Destructor
Copy constructor
Destructor
Copy constructor
Destructor
Destructor
Destructor
Destructor

Explanation:
MyClass() calls non parameterized constructor, the {0, MyClass()} creates a copy constructed object. MyClass(1,2), MyClass(3,4) each call parameterized constructor followed by the copy constructor due to {3/5, object} creation.
Now these data are copied to my_map object calling 3 more copy constructors.
As the my_map object is created, the nested subsequent creations are now out of scope and destructed, calling 6 destructors. 
The auto e:my_map creates copies of all objects. The copy operation calls the copy operator and RHS operation then calls the destructor. 
As the question scope ends, the 3 MyClass objects in my_map will be destructed.


---------------------------------------------------------------
Q12 Output:

Q12
Non-parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor

Explanation:
The above ouptut is similar to Q11, however in the auto loop, e is created as a reference object. Thus, 3 separate copy and destruct sequences are avoided.

---------------------------------------------------------------
Q13 Output:

Q13
Parameterized constructor
Destructor

Explanation:
Same as Q10

---------------------------------------------------------------
Q14 Output:

Q14
Parameterized constructor
Operation took: 1605 milliseconds
Copy constructor
Copy constructor
Something 1.
Destructor
o2.v_.size(): 100000000
Destructor
Copy constructor
Copy constructor
Something 1.
Destructor
o2.v_.size(): 100000000
Destructor
Operation took: 1399 milliseconds
Destructor

Explanation:
L1: This initial print specifies the question index as Q14.
L2,3: MyClass o(N) calls the parameterized constructor. The time taken for this object creation is 1605 ms.
L4-15 are loop prints. In each iteration of loop, a copy of object o is created in o2, thereby calling the copy constructor. Since function DoSomething1 is pass by value, another copy is created inside it. As the scope of function DoSomething1 finishes, the local copy is destructed followed by the o2 v_size print and subsequent destruction of o2. This is repeated for another iteration.
The function PrintAndGetDuration finally prints the time taken, after which the object o is destructed. 

---------------------------------------------------------------
Q15 Output:

Q15
Parameterized constructor
Operation took: 1017 milliseconds
Copy constructor
Something 2.
o2.v_.size(): 100000000
Destructor
Copy constructor
Something 2.
o2.v_.size(): 100000000
Destructor
Operation took: 264 milliseconds
Destructor

Explanation:
L1: This initial print specifies the question index as Q15.
L2,3: MyClass o(N) calls the parameterized constructor. The time taken for this object creation is 1605 ms.
L4-8 are similar to Q14's loop with the difference being the function DoSomething2 using pass by reference. This omits the creation of copy of object o2 and instead uses o2 itself in the function.
L9-10 follows suit as in Q14.

---------------------------------------------------------------
Q16 Output:

Q16
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Operation took: 4978 milliseconds
Copy constructor
e.v_.size(): 10000000
Destructor
Copy constructor
e.v_.size(): 20000000
Destructor
Copy constructor
e.v_.size(): 30000000
Destructor
Copy constructor
e.v_.size(): 40000000
Destructor
Copy constructor
e.v_.size(): 50000000
Destructor
Copy constructor
e.v_.size(): 60000000
Destructor
Copy constructor
e.v_.size(): 70000000
Destructor
Operation took: 562 milliseconds
e.v_.size(): 10000000
e.v_.size(): 20000000
e.v_.size(): 30000000
e.v_.size(): 40000000
e.v_.size(): 50000000
e.v_.size(): 60000000
e.v_.size(): 70000000
Operation took: 0 milliseconds
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor


Explanation:
L1: This initial print specifies the question index as Q16.

Rest of the line blocks:
MyClass(N) for 10000000 to 7000000 creates 7 calls to the parameterized constructor as part of RHS evaluation for line 297. Now the objects are copied to create actual members of my_vector object.
The time for the above operation is printed.
In the auto loop, each value in my_vector is copied to e using a copy constructor. The size of the vector is then printed followed by the destructor call.
In the next auto loop, only references are used, thus no allocation and copy is done.


---------------------------------------------------------------