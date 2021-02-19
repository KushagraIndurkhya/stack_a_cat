# 16 Ways to stack integers

In this repository to explore and learn rich C++ features and programming techniques used in C++ i have implemented various ways to use and implement stacks in C++ as described in the paper [Sixteen ways to stack a cat](https://stroustrup.com/stack_cat.pdf) by Bjarne Stroustrup.

# Compiling and Running

## Compiling

The repo includes a make file at root for easy compilation of the source code.

For compilation of the source codes , g++ needs to be installed.

All the binaries are produced in ./bin directory .

## ``` $ make ```
or

## ``` $ make compile```

## Input and output

All the binaries produced in ./bin  directory after successfull compilation takes input from stdin in the following format

+ forst line contains two space seperated integers m,n where m is the number of stacks to be created and n is the number of operation.
+ After this in the subsequent n lines contains operation to be performed on the stacks with either of these two syntaxes:
    + ```<stack_id> <"push"> <integer_to_be_pushed>```
    + ```<stack_id> <"pop">```

Output is given to stdout where each line is of format:

```<stack_id> <tail_element> <tail_element -1>......<head>```
### Sample input:

inp.txt
```
3 10
1 push 1
1 pop
1 push 2
1 push 3
1 pop
2 push 10
2 push 20
2 push 30
3 push 100
3 pop 
```
```$ ./bin/stack0 < inp.txt```
### Sample Output:

```
1 2 
2 30 20 10 
3  
```

## Cleanup

For removing all the compiled binaries simple run ```$ make clean``` in the root of the repository

# Brief Explanations

## Stack0

Stack0 is a very trivial attempt of the implementation of stack using linked list where stack is not a class but rather a struct containing the information such as the pointer to the the head of the linked list , maximum size and current size , and these structs are contained in a vector seg_id is simply the index of the struct in that vector.This method doesn't make use of rich c++ features.

## Stack1

In stack0 stack_id was not a genuine id type is was typedef so here we make a struct containing the integer id hence its now a genuine type

## Stack2

In stack2 the stack_id and all the static methods are contained in a class thus providing a namespace for stack operations

## Stack3

To prevent the access of stack_id outside the stack class we use a member class having integer id as its member instead of struct and make the stack class its friend class so the stack_id is accessed by the operations

## Stack4

Till now we were using integer ids to access actual stack_meta info stored elsewhere now we put the actual stack representation  as private members of the rep class which cant be accessed from the outside so they can be passed around but cannot be looked into

## Stack5

In stack5 we improve upon stack4 by  preventing the users from allocating stack representations by controlling the copying and creation of reps by using constructor,copy constructor inside the rep class

## Stack6
in stack6 to minimize the recompilation costs we place the stack representation in a different class making implementation details both inaccssible and out of sight from the user.

## Stack7
Stack7 is a natural improvement to the above  implementations of stack where actual representation of the stack are class members and operations are it operations are static methods

## Stack8
Here we make use of c++ features and follow the object oriented way of implementing things where actual representation of the stack are class members , push and pop are functions and constructors and destructors are used to create and destroy the stack

## Stack9

In stack 9 we keep the actual representation of the stack in a struct and use its pointer to access the stack this enables us to change the representation of a stack without recompilation

## Stack10

In the above stacks the functions were bound with the name of operations thereby allowing only one kind of implementation but in stack12 we use multiple implementations of stacks(linked list and array in my case)
to achieve this we provide a common stack interface providing pure virtual functions which can be implemented in different ways by different classes inheriting it.

## Stack11

In stack11 we implement a mechanism to replace a function binding while a programme is running,this is achieved by creating an identical class to lstack with redefined operations,and we can update the pointer of a lstack object which was constructed in such a manner tht only its vbtl was created to vbtl of this new llstack class functions

## Stack12

In stack10 we changed the representation of the stack at run time in, stack 11  we changed operations at run time in stack12 we implement a technique to replace both representation and the operations for an object at run time.
we use simple forwarding functions to operation on rep in class stack and use get_rep() and put_rep() to change representation at run time

## Stack13
in stack13 we simulate dynamic type-checking by having a oper_table(list of (object_identifier,function) pair) to invoke the function as nedded by the type and there oper_table elements can be added at run time to the oper_table thus allowing type-checking,this technique can make large systems slow and codebases messy.

## Stack14

In stack14 we improve upon stack13 by:
+ Hiding the message passing (ugly implementation details from the user) by wrraping it up in a class.
+ Allowing a fixed number of argument types to be passed as opposed to the fixed argument type in stack13

## Stack15

In stack 15 further improving on stack14 we add space and time optimizations by instead of giving each object its own list of acceptable operations we keep set of acceptable operations on a common set of objects , for this we use a class to represent these.



### ```Submitted by : Kushagra Indurkhya```
###  ``` CS19B1017```