#include "stack.hpp"
#include "lstack.hpp"

class llstack: public lstack{
    public:
        llstack(int size) : lstack(size) {}
        llstack(noop x) : lstack(x){}

        void push(long long int);
        long long int pop();

};
