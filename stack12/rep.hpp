/*
Stack12 rep.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/
/*
Class: rep
Consists of pure virtual functions for various stack operations
*/
class rep{
    public:
                virtual void push(long long int) = 0;
                virtual long long int pop()=0;
                virtual void printstack()=0;
                virtual int size()=0;
                virtual int c_size()=0;
                
};