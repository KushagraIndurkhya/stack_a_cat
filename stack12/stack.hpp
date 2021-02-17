class stack{
    rep* p;
    
    public:
        stack(int size);
        ~stack();

        rep* get_rep(){return p;}
        void put_rep(rep* q){p=q;}

        void push(long long int c){p->push(c);}
        long long int pop(){return p->pop();}
        void printstack(){return p->printstack();}

        int size(){return p->size();}
        int c_size(){return p->c_size();}
};