/*
Stack0 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include "rep.hpp"

using namespace std;
//......................................................................implementation of rep.hppp functions.................................................
node::node(long long int val){
    data=val;
    next=NULL;
}

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

void rep::delete_stack()
{
    node* curr = this->head;
    while(this->head)
    {
        this->pop();
    }
    delete(this);
}
//........................................................................implementation of stack.hpp functions..............................................

//finding and exectuting the operation with id oper 
long long int cat_object :: operator() (int oper, long long int arg)
{
    for(oper_link*pp=oper_table;pp;pp=pp->next)
        if (oper == pp->oper) return pp->fct(p,arg);
    return -1;
}
// adding ff to operations_table
void cat_object::add_oper(int oo,PcatF ff)
{
    oper_link* temp=new oper_link(oo,ff,oper_table);
    this->oper_table = temp;
}

//removing operation with id oo from oper_table
void cat_object :: remove_oper(int oo)
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
cat_object* make_stack(cat_object* p)
{
    //if p==0 create a new cat_object
    if(p==0) p=new cat_object(0,new rep());
    //adding operations to p
    p->add_oper(stack_push,&stack_push_fct);
    p->add_oper(stack_pop,&stack_pop_fct);
    p->add_oper(stack_destroy,&stack_destroy_fct);
    p->add_oper(stack_print,&stack_print_fct);
    return p;
}





