/*
Class: stack
Data Members:
        p:representation of stack
Methods:
        stack(): constructor
        ~stack(): destructor

        get_rep():retrieve rep
        put_rep(rep*):replace rep

        push(long long int): Push data in stack
                args: int to be pushed
                returns: void
        pop(): Pop a value from stack
                args:
                returns: popped value
        printstack(): Print the stack
                args:
                returns: void


        size():returns the max_size of the stack
        c_size():returns the current size of stack

*/

class stack{
    rep* p;
    
    public:
        stack(int size);
        ~stack();

        rep* get_rep(){return p;}
        void put_rep(rep* q){p=q;}

        void push(long long int c){p->push(c);}
        long long int pop(){return p->pop();}
        void printstack(){return p->printstack();}

        int size(){return p->size();}
        int c_size(){return p->c_size();}
};