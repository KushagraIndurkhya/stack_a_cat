/*
Stack7 stack.cpp
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

// function to create a stack
stack::stack_id stack::create(int max_size)
{
    stack*s=(stack*)malloc(sizeof(stack));
    s->head=NULL;
    s->max_size=max_size;
    s->curr_size=0;
    return s;
}

//deleting the stack
void stack::cleanup(stack::stack_id id)
{
    free(id);   
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

void stack::push (stack::stack_id id,long long int data)
{
    if (id->curr_size == id->max_size || id->max_size == 0)
        return;

    node* temp = new node(data);

    if (!id->head)
    {
        id->curr_size += 1;
        id->head = temp;
    } 
    else
    {
        node* curr_head = id->head;
        temp->next = curr_head;
        id->head = temp;
        id->curr_size += 1;
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
long long int stack::pop (stack::stack_id id)
{
    
    if (!id->head)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        node* curr = id->head;
        long long int res = curr->data;
        id->head=curr->next;
        delete(curr);
        id->curr_size -= 1;
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
void stack::destroy(stack::stack_id id)
{
    if(!id->head)
        return ;
    node* curr = id->head;
    while (id->head)
        stack::pop(id);
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
void stack::printstack(stack::stack_id id)
{
    if (!id->head)
        cout << " "; 
    else
    {
        node* curr = id->head;
        while(curr)
        {
            cout << curr->data <<" ";
            curr = curr->next;
        }
    }
    cout << "\n" ;     
}