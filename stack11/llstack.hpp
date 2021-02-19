/*
Stack11 llstack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/
#include "lstack.hpp"

/*
Class: llstack

Methods:

        push(long long int): Push data in stack
                args: int to be pushed
                returns: void
        pop(): Pop a value from stack
                args:
                returns: popped value

*/
class llstack: public lstack{
    public:

        llstack(int size) : lstack(size) {}
        llstack(noop x) : lstack(x){}

        void push(long long int);
        long long int pop();
        //overriding new operator
        void* operator new(size_t,void*p){return p;}
};
