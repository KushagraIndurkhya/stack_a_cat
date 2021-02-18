
class noop{};

class argument{
    enum type_indcator {non_arg,int_arg,ptr_arg,string_arg,ll_arg};
    type_indcator t;
    union{
        int i;
        void* p;
        char* s;
        long long int l;
    };

    public:
        argument() : t(non_arg) {}
        argument(int ii) :i(ii),t(int_arg) {}
        argument(void* pp) :p(pp), t(ptr_arg) {}
        argument(char* ss) :s(ss), t(string_arg) {}
        argument(long long ll) :l(ll), t(ll_arg) {}

        operator int() {return t==int_arg ? i :-1;}
        operator void*() {return t==ptr_arg ? p :0;}
        operator char*() {return t==string_arg ? s :0;}
        operator long long int() {return t==ll_arg ? l :-1;}
};

typedef argument (*PargumentF)(void*,argument);

struct oper_link{
    oper_link* next;
    int oper ;
    PargumentF fct;

    oper_link(int oo, PargumentF ff, oper_link*nn)
        : oper(oo) , fct(ff) , next(nn) {}
};

class argument_object {
    void* p;
    oper_link* oper_table;
    public:

        argument_object(oper_link*tbl=0, void*rep=0)
            : oper_table(tbl),p(rep){}

        argument operator()(int oper, argument arg=argument());

        void add_oper(int , PargumentF);
        void remove_oper(int);
};
class node{
        public:
            long long int data;
            node* next;
        node(long long int);

};

argument_object* make_stack(argument_object* = 0);
enum stack_oper {stack_destroy=99,stack_push,stack_pop,stack_print};

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

static argument stack_push_fct(void* p,argument c)
{
    ((rep*)p) -> push(c);
    return -1;
}

static argument stack_pop_fct(void* p,argument)
{
    return ((rep*)p) -> pop();
}
static argument stack_print_fct(void* p,argument)
{
    ((rep*)p) -> printstack();
    return -1;
}
static argument stack_destroy_fct(void* p,argument)
{
    ((rep*)p) -> delete_stack();
    return -1;
}

class stack : public argument_object
{
    argument_object*p;
    public:
        stack() {this->p=new argument_object(0,new rep());make_stack(this->p);}
        ~stack() {(*this->p)(stack_destroy);}

        void push(long long int c) {(*this->p)(stack_push,c);}
        long long int pop(){return (*this->p)(stack_pop);}
        void print(){(*this->p)(stack_print);}
        void destroy(){(*this->p)(stack_destroy);}
};









