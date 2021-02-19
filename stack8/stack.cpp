/*
Stack8 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include <vector> 
#include "stack.hpp"
using namespace std;
//constructor for node class
node::node(long long int val){
    data=val;
    next=NULL;
}
//constructor for stack class
stack::stack (int max_size)
{
    this->head=NULL;
    this->max_size=max_size;
    this->curr_size=0;
}
//desstructor for stack class
stack::~stack()
{
    while(this->head)
    {
        this->pop();
    }
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

void stack::push (long long int data)
{
    if (this->curr_size == this->max_size || this->max_size == 0)
        return;

    node* temp = new node(data);

    if (!this->head)
    {
        this->head = temp;
    } 
    else
    {
        node* curr_head = this->head;
        temp->next = curr_head;
        this->head = temp;
        this->curr_size += 1;
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
    
    if (!this->head)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        node* curr = this->head;
        long long int res = curr->data;
        this->head=curr->next;
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
    if (!this->head)
        cout << " "; 
    else
    {
        node* curr = this->head;
        while(curr)
        {
            cout << curr->data <<" ";
            curr = curr->next;
        }
    }
    cout << "\n" ;     
}