# 16 Ways to stack integers

In this repository to explore and learn various features and techniques used in C++ i have implemented various ways to use and implement stacks in C++ as described in the paper [Sixteen ways to stack a cat](https://stroustrup.com/stack_cat.pdf) by Bjarne Stroustrup.

## Compiling

The repo includes a make file at root for easy compilation of the source code.

For compilation of the cource codes , g++ needs to be installed.

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


## Stack0









