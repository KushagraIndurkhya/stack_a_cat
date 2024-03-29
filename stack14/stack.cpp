/*
Stack14 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include "stack.hpp"

using namespace std;

//node constructor
node::node(long long int val){
    data=val;
    next=NULL;
}

//push operation
void rep::push (long long int data)
{
    node* temp = new node(data);

    if (!this->head)
    {
        this->head = temp;
        this->curr_size += 1;
    } 
    else
    {
        node* curr_head = this->head;
        temp->next = curr_head;
        this->head = temp;
        this->curr_size += 1;
    }
    
}

//pop operation
long long int rep::pop ( )
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
        this->curr_size --;
        return res;
    }
}
//display the stack
void rep::printstack()
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
//destroying the stack
void rep::delete_stack()
{
    node* curr = this->head;
    while(this->head)
        this->pop();
    delete(this);
}
//...................................................................implementing argument functions................................................

//finding and executing the operation
argument argument_object :: operator() (int oper, argument arg)
{
    for(oper_link*pp=oper_table;pp;pp=pp->next)
        if (oper == pp->oper) return pp->fct(p,arg);
    return -1;
}

//adding an operation to operations linked list

void argument_object::add_oper(int oo,PargumentF ff)
{
    oper_link* temp=new oper_link(oo,ff,oper_table);
    this->oper_table = temp;
}

//removing an operation from oper_table
void argument_object :: remove_oper(int oo)
{
    if(this->oper_table->oper==oo)
    {
            oper_link* temp = oper_table;
            this->oper_table = temp->next;
            delete(temp);
    }
    else
    {
        for(oper_link*pp=this->oper_table;pp;pp=pp->next)
        {
            if (pp->next->oper==oo)
            {
                oper_link* temp = pp->next;
                pp->next = temp->next;
                delete(temp);
            }
        }
    }
}

//making a stack
argument_object* make_stack(argument_object* p)
{
    if(p==0) p=new argument_object(0,new rep());
    //adding operations
    p->add_oper(stack_push,&stack_push_fct);
    p->add_oper(stack_pop,&stack_pop_fct);
    p->add_oper(stack_destroy,&stack_destroy_fct);
    p->add_oper(stack_print,&stack_print_fct);

    return p;
}




