/*Interface for array implementation*/
/*

Class: astack
Data Members:
        curr_size:current size of the stack
        max_Size : maximum allowed size
        arr : pointer to the array containing the stack

Methods:
        astack(): constructor
        ~astack(): destructor

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
class astack : public stack{
    int curr_size;
    int max_size;
    long long int* arr;

    public :
            astack(int);
            ~astack();
            
            void push(long long int);
            long long int pop();
            void printstack(); 
};
