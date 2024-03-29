#include <iostream>
using namespace std;
//node of linked list
class node
{
public:
    long long int data;
    node *next;
    node(long long int);
};
//stack representation struct
struct rep
{
    node *head;
    int curr_size;
    rep()
        : head(NULL), curr_size(0) {}

    void push(long long int);
    long long int pop();

    void printstack();
    void delete_stack();
};
//.................................................................................................................................


class argument
{
    //type indicator enum
    enum type_indcator{ non_arg, int_arg,ptr_arg,string_arg,ll_arg};
    type_indcator t;
    //union of different data types
    union
    {
        int i;
        void *p;
        char *s;
        long long int l;
    };
//arguments and operators
public:
    argument() : t(non_arg) {}
    argument(int ii) : i(ii), t(int_arg) {}
    argument(void *pp) : p(pp), t(ptr_arg) {}
    argument(char *ss) : s(ss), t(string_arg) {}
    argument(long long ll) : l(ll), t(ll_arg) {}

    operator int() { return t == int_arg ? i : -1; }
    operator void *() { return t == ptr_arg ? p : 0; }
    operator char *() { return t == string_arg ? s : 0; }
    operator long long int() { return t == ll_arg ? l : -1; }
};

//type defining argument
typedef argument (*PargumentF)(void *, argument);

//node for operations liked list
struct oper_link
{
    oper_link *next;
    int oper;
    PargumentF fct;

    oper_link(int oo, PargumentF ff, oper_link *nn)
        : oper(oo), fct(ff), next(nn) {}
};
//.................................................................................................................

//class for holding argument representation and methods
class argument_class_rep
{
public:
    oper_link *oper_table;
    argument_class_rep()
        : oper_table(0) {}

    void add_oper(int, PargumentF);
    void remove_oper(int);
};
//................................................................................................................
//stack operations
enum stack_oper{stack_destroy = 99,stack_push,stack_pop,stack_print};

static argument stack_push_fct(void *p, argument c)
{
    ((rep *)p)->push(c);
    return -1;
}
static argument stack_pop_fct(void *p, argument)
{
    return (argument)((rep *)p)->pop();
}
static argument stack_print_fct(void *p, argument)
{
    ((rep *)p)->printstack();
    return -1;
}
static argument stack_destroy_fct(void *p, argument)
{
    ((rep *)p)->delete_stack();
    return -1;
}
//...................................................................................................................
//creating stack_class of type argument_class_rep
static argument_class_rep stack_class = *(new argument_class_rep());
argument_class_rep *get_stack_class();

//argument_object
class argument_object
{
    void *p;
    argument_class_rep *crep;

public:
    //constructor
    argument_object(argument_class_rep *cc, void *rep = 0)
        : crep(cc), p(rep) {}
    argument operator()(int oper, argument arg = argument());
};

argument_object *make_stack();
