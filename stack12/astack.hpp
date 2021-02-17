
class astack : public rep{
    int curr_size;
    int max_size;
    long long int* arr;

    public :
            astack(int);
            ~astack();
            void push(long long int);
            long long int pop();
            void printstack();
            int size();  
            int c_size(); 
};

rep* convert_from_l_to_a(stack& s);
