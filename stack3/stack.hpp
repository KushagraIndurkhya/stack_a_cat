/*
Stack0 stack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/


//interface for stack
class stack{
    public:
            /*struct for stack_id*/
            class stack_id{
                    friend stack;
                    private:
                        int i;
                    };
            /*
            * Function:  create
            * --------------------
            * Create a stack
            * returns: stack_id of the created stack
            *                     
            */
            static stack_id create(int) ;
            /*
            * Function:  push
            * --------------------
            * pushes a long long int in the stack having given stack_id
            * returns: Void
            *                     
            */
            static void push(stack_id,long long int) ;
            /*
            * Function:  pop
            * --------------------
            * performs pop operation on the stack with given stack_id
            * returns: Void
            *                     
            */
            static long long int pop(stack_id);
            /*
            * Function:  destroys
            * --------------------
            * destroyes the  stack of given stack_id
            * returns: Void
            *                     
            */
            static void destroy(stack_id) ;
            /*
            * Function:  printstack
            * --------------------
            * Print the contents of the stack with given stack_id
            * returns: Void
            *                     
            */
            static void printstack(stack_id);
    //Making stack an abstract class
    private:
            virtual void dummy() = 0;
};