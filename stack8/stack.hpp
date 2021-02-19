/*
Stack8 stack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/

/*Interface for stack implementation*/

/*
Class: node for linked list
Data Members:
        data:data held in node
        next : pointer to next node

Methods: 
        node():constructor

*/
class node{
        public:
            long long int data;
            node* next;
        node(long long int);

};
/*
Class: stack
Data Members:
        curr_size:current size of the stack
        max_Size : maximum allowed size
        head : pointer to the head od the linked list

Methods:
        stack(): constructor
        ~stack(): destructor

        push(long long int): Push data in stack
                args: int to be pushed
                returns: void
        pop(): Pop a value from stack
                args:
                returns: popped value
        printstack(): Print the stack
                args:
                returns: void

*/
class stack{
                node* head;
                int max_size;
                int curr_size;

        public:
                void push(long long int);
                long long int pop();
                void printstack();

                stack(int);
                ~stack();
};