typedef long long int (*PcatF)(void*,long long int);

//node of link list of operation table
struct oper_link{
    oper_link* next; //next node
    int oper ; //oper id
    PcatF fct; //function

    //constructor
    oper_link(int oo, PcatF ff, oper_link*nn)
        : oper(oo) , fct(ff) , next(nn) {}
};


class cat_object {
    void* p; //pointer to representation
    oper_link* oper_table; //operation table

    public:
    //constructor
        cat_object(oper_link*tbl=0, void*rep=0)
            : oper_table(tbl),p(rep){}

        long long int operator()(int oper, long long int arg=0);
    //function to add operation to oper_table
        void add_oper(int , PcatF);
    //function to remove an operation from oper_table
        void remove_oper(int);
};

//function to make a stack
cat_object* make_stack(cat_object* = 0);

//enum of operations
enum stack_oper {stack_destroy=99,stack_push,stack_pop,stack_print};


