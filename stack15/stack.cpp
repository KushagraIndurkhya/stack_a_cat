/*
Stack0 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include "stack.hpp"

using namespace std;
node::node(long long int val)
{
    data = val;
    next = NULL;
}

void rep::push(long long int data)
{
    node *temp = new node(data);
    if (!head)
    {
        head = temp;
        curr_size += 1;
    }
    else
    {
        node *curr_head = head;
        temp->next = curr_head;
        head = temp;
        curr_size += 1;
    }
}

long long int rep::pop()
{

    if (!this->head)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        node *curr = this->head;
        long long int res = curr->data;
        this->head = curr->next;
        delete (curr);
        this->curr_size--;
        return res;
    }
}
void rep::printstack()
{
    if (!this->head)
        cout << " ";
    else
    {
        node *curr = this->head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    cout << "\n";
}

void rep::delete_stack()
{
    node *curr = this->head;
    node *temp;
    while (curr)
    {
        temp = curr;
        curr = temp->next;
        delete (temp);
    }
}

argument argument_object ::operator()(int oper, argument arg)
{
    for (oper_link *pp = this->crep->oper_table; pp; pp = pp->next)
        if (oper == pp->oper)
            return pp->fct(p, arg);
    return -1;
}

void argument_class_rep::add_oper(int oo, PargumentF ff)
{
    oper_link *temp = new oper_link(oo, ff, oper_table);
    this->oper_table = temp;
}

void argument_class_rep ::remove_oper(int oo)
{
    if (this->oper_table->oper == oo)
    {
        oper_link *temp = oper_table;
        this->oper_table = temp->next;
        delete (temp);
    }
    else
    {
        for (oper_link *pp = this->oper_table; pp; pp = pp->next)
        {
            if (pp->next->oper == oo)
            {
                oper_link *temp = pp->next;
                pp->next = temp->next;
                delete (temp);
            }
        }
    }
}

argument_class_rep *get_stack_class()
{
    if (stack_class.oper_table == 0)
    {
        stack_class.add_oper(stack_push, &stack_push_fct);
        stack_class.add_oper(stack_pop, &stack_pop_fct);
        stack_class.add_oper(stack_destroy, &stack_destroy_fct);
        stack_class.add_oper(stack_print, &stack_print_fct);
    }
    return &stack_class;
}

argument_object *make_stack()
{
    return new argument_object(get_stack_class(), new rep);
}
