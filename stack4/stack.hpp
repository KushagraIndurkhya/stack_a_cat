/*
Stack4 stack.hpp
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

class stack{
    public:
             /*
                Class:rep :: class for representation of stack
                Data Members:
                        curr_size:current size of the stack
                        max_Size : maximum allowed size
                        head : pointer to the head od the linked list
                        
                Methods: 
                        rep(int):constructor

                */
            class rep{
                    friend stack;
                    private:
                            node* head;
                            int max_size;
                            int curr_size;
                    };
            typedef rep* stack_id;
            static void initialize(stack_id,int);
            static void cleanup(stack_id);
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