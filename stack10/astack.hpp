
class astack : public stack{
    int curr_size;
    int max_size;
    long long int* arr;

    public :
            astack(int);
            ~astack();
            void push(long long int);
            long long int pop();
            void printstack(); 
};
