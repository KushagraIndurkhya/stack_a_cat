#include "stack.hpp"
class node{
        public:
            long long int data;
            node* next;
        node(long long int);

};

struct rep{
    node* head;
    int curr_size;
    rep()
        : head(NULL), curr_size(0){}
    
    void push(long long int);
    long long int pop();

    void printstack();
    void delete_stack();

};

static long long int stack_push_fct(void* p,long long int c)
{
    ((rep*)p) -> push(c);
    return -1;
}

static long long int stack_pop_fct(void* p,long long int c)
{
    return ((rep*)p) -> pop();
}
static long long int stack_print_fct(void* p,long long int)
{
    ((rep*)p) -> printstack();
    return -1;
}
static long long int stack_destroy_fct(void* p,long long int)
{
    ((rep*)p) -> delete_stack();
    return -1;
}

