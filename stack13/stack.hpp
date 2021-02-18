typedef long long int (*PcatF)(void*,long long int);

struct oper_link{
    oper_link* next;
    int oper ;
    PcatF fct;

    oper_link(int oo, PcatF ff, oper_link*nn)
        : oper(oo) , fct(ff) , next(nn) {}
};

class cat_object {
    void* p;
    oper_link* oper_table;

    public:
        cat_object(oper_link*tbl=0, void*rep=0)
            : oper_table(tbl),p(rep){}

        long long int operator()(int oper, long long int arg=0);

        void add_oper(int , PcatF);
        void remove_oper(int);

        void delete_cat();
        ~cat_object();
};


cat_object* make_stack(cat_object* = 0);

enum stack_oper {stack_destroy=99,stack_push,stack_pop,stack_print};


