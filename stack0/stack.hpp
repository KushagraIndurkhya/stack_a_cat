//interface for stack
typedef int stack_id;
stack_id create(int) ;
void destroy(stack_id) ;
void push(stack_id,long long int) ;
long long int pop(stack_id);
void printstack(stack_id);