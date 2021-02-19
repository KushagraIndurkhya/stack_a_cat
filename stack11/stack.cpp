/*
Stack0 stack.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

// Implementation of interface(stack.hpp) functions
#include <iostream>
#include "stack.hpp"
#include "lstack.hpp"
#include "astack.hpp"

using namespace std;
node::node(long long int val){
    data=val;
    next=NULL;
}

lstack::lstack (int max_size)
{
    this->head=NULL;
    this->max_size=max_size;
    this->curr_size=0;
}
lstack::~lstack()
{
    while(this->head)
    {
        this->pop();
    }
}


void lstack::push (long long int data)
{
    if (this->curr_size == this->max_size || this->max_size == 0)
        return;

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

long long int lstack::pop ( )
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

void lstack::printstack()
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

void astack::printstack()
{
    if (!this->arr)
        cout << " ";
    else
    {
        long long int * stack= this->arr;
        for(int i=this->curr_size-1;i>=0;i--)
        {
            cout<<stack[i]<<" ";
        }
        cout << "\n" ;
    }

}
astack::astack (int max_size)
{ 
    this->arr= new long long int[max_size];
    this->max_size=max_size;
    this->curr_size=0;
}
astack::~astack()
{
    delete[] this->arr;
}
void astack::push (long long int data)
{
    if (this->curr_size == this->max_size || this->max_size == 0)
        return;
    else
    {
        this->arr[this->curr_size]=data;
        this->curr_size++;
    } 
}
long long int astack::pop ( )
{
    
    if (!this->arr)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        long long int res = this->arr[this->curr_size];
        this->curr_size--;
        return res;
    }
}
