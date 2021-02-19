class node{
        public:
            long long int data;
            node* next;
        node(long long int);

};
class noop{};
class lstack:public stack {
                node* head;
                int max_size;
                int curr_size;

        public:

                void push(long long int);
                long long int pop();
                void printstack();

                lstack(noop){}
                lstack(int);
                ~lstack();
};