/*
Stack1 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include <vector> 
#include "stack.hpp"
using namespace std;
/*
 * Class: node
 * --------------------
 * node of the linked list for stack implementaton
 * members:
 *          public
 *               data:data stored in the node
 *               next:pointer to the next node
 *          private:                    
 */
class node
{
    public:
        long long int data;
        node* next;
        /*
        * Constructor
        * --------------------
        * val: data to be stored in the node
        * Initializes next to Null
        */
        node(long long int val)
        {
            data = val;
            next = NULL;
        }     
};
/*
 * Struct: stack_meta
 * --------------------
 * Holds info about stack
 * 
 *      head: pointer to the head of the linked list storing the stack
 *      max_size: maximum permissible size for the stack
 *      curr_size: current size of the stack
 *
 * 
 *                     
 */

typedef struct stack_meta{
        node* head;
        int max_size;
        int curr_size;
}stack;

/*vector to hold the stack_meta structs*/
vector<stack> stacks;

/*
 * Function:  create
 * --------------------
 * Create a stack
 * max_size: maximum size of the stack
 * returns: stack_id of the created stack
 *                     
 */
stack_id create(int max_size)
{
    stack temp;
    temp.head=NULL;
    temp.max_size=max_size;
    temp.curr_size=0;

    stacks.push_back(temp);
    stack_id res;
    res.i = stacks.size();
    return res;
}
/*
 * Function:  push
 * --------------------
 * pushes a long long int in the stack having given stack_id
 *
 * id: Stack_id
 * data: int to be pushed
 *
 *
 * returns: Void
 *                     
 */

void push (stack_id id,long long int data)
{
    int idx=id.i-1;
    
    
    if (stacks[idx].curr_size == stacks[idx].max_size || stacks[idx].max_size == 0)
        return;
    node* temp=new node (data);
    if (!stacks[idx].head)
    {
        stacks[idx].curr_size += 1;
        stacks[idx].head = temp; 
    }
    else
    {
        node* curr_head = stacks[idx].head;
        temp->next = curr_head;
        stacks[idx].head = temp;
        stacks[idx].curr_size += 1;
    }
    
}
/*
 * Function:  pop
 * --------------------
 * performs pop operation on the stack with given stack_id
 *
 * id: Stack_id
 *
 *
 * returns: Void
 *                     
 */
long long int pop (stack_id id)
{
    int idx=id.i-1;
    
    if (!stacks[idx].head)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        node* curr = stacks[idx].head;
        long long int res = curr->data;
        stacks[idx].head=curr->next;
        delete(curr);
        stacks[idx].curr_size -= 1;
        return res;
    }
}
/*
 * Function:  destroys
 * --------------------
 * destroyes the  stack of given stack_id
 *
 * id: Stack_id
 *
 *
 * returns: Void
 *                     
 */
void destroy(stack_id id)
{
    int idx=id.i-1;
    if(!stacks[idx].head)
        return ;
    node* curr = stacks[idx].head;
    while (stacks[idx].head)
        pop(id);
}
/*
 * Function:  printstack
 * --------------------
 * Print the contents of the stack with given stack_id
 * 
 * id: Stack_id
 *
 *
 * returns: Void
 *                     
 */
void printstack(stack_id id)
{
    int idx=id.i-1;
    if (!stacks[idx].head)
        cout << " "; 
    else
    {
        node* curr = stacks[idx].head;
        while(curr)
        {
            cout << curr->data <<" ";
            curr = curr->next;
        }
    }
    cout << "\n" ;     
}