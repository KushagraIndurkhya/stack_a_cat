/*
Stack0 stack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/

class rep{
    public:
                virtual void push(long long int) = 0;
                virtual long long int pop()=0;
                virtual void printstack()=0;
                virtual int size()=0;
                virtual int c_size()=0;
                
};