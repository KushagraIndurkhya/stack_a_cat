/*
Stack0 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include <vector> 
#include "stack.hpp"
using namespace std;
node::node(long long int val){
    data=val;
    next=NULL;
}

stack::stack (int max_size)
{
    stack::rep* new_rep = (stack::rep*) malloc(sizeof(stack::rep));
    this->p=new_rep;
    this->p->head=NULL;
    this->p->max_size=max_size;
    this->p->curr_size=0;
}
stack::~stack()
{
    while(this->p->head)
        this->pop();
    free(this->p);
}

// void stack::cleanup(stack::stack_id id)
// {
//     free(id);   
// }

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

void stack::push (long long int data)
{
    if (this->p->curr_size == this->p->max_size || this->p->max_size == 0)
        return;

    node* temp = new node(data);

    if (!this->p->head)
    {
        this->p->head = temp;
    } 
    else
    {
        node* curr_head = this->p->head;
        temp->next = curr_head;
        this->p->head = temp;
        this->p->curr_size += 1;
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
long long int stack::pop ( )
{
    
    if (!this->p->head)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        node* curr = this->p->head;
        long long int res = curr->data;
        this->p->head=curr->next;
        delete(curr);
        return res;
    }
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
void stack::printstack()
{
    if (!this->p->head)
        cout << " "; 
    else
    {
        node* curr = this->p->head;
        while(curr)
        {
            cout << curr->data <<" ";
            curr = curr->next;
        }
    }
    cout << "\n" ;     
}