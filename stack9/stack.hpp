/*
Stack0 stack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/


//interface for stack
class node{
        public:
            long long int data;
            node* next;
        node(long long int);

};

class stack{
    
            /*struct for stack_id*/
            struct rep{
                node* head;
                int max_size;
                int curr_size;
            };
            rep* p;

            public:
                void push(long long int);
                long long int pop();
                void printstack();

                stack(int);
                ~stack();
};