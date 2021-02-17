/*
Stack0 stack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/

class node{
        public:
            long long int data;
            node* next;
        node(long long int);

};

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