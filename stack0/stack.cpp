
#include <string>
#include <vector> 
#include <iostream>
#include "stack.hpp"
using namespace std;
class node
{
    public:
        long long int data;
        node* next;
        node(long long int val)
        {
            data = val;
            next = NULL;
        }     
};

class stack{
    public:
        node* head;
        int max_size;
        int curr_size;
        stack(int max_size)
        {
            this->head=NULL;
            this->max_size=max_size;
            this->curr_size=0;
        }
};

vector<stack*> stack_ids;

int create(int max_size)
{
    stack_ids.push_back(new stack(max_size));
    return stack_ids.size();
}



void push (stack_id id,long long int data)
{
    stack* stack_meta=stack_ids[id-1];
    if (stack_meta->curr_size == stack_meta->max_size || stack_meta->max_size == 0)
        return;
    node* temp=new node (data);
    if (!stack_meta->head)
        stack_meta->head = temp; 
    else
    {
        node* curr_head = stack_meta->head;
        stack_meta->head = temp;
        stack_meta->head->next = curr_head;
        stack_meta->curr_size += 1;
    }
    
}

long long int pop (stack_id id)
{
    stack* stack_meta=stack_ids[id-1];
    if (!stack_meta->head)
    {
        cout << "EMPTY STACK \n";
        return -1;
    }
    else
    {
        node* curr = stack_meta->head;
        long long int res = curr->data;
        stack_meta->head=curr->next;
        delete(curr);
        return res;
    }
}

void destroy(stack_id id)
{
    stack* stack_meta=stack_ids[id-1];
    if(!stack_meta->head)
        return ;
    node* curr = stack_meta->head;
    while (stack_meta->head)
        pop(id);
}

void printstack(stack_id id)
{
    stack* stack_meta = stack_ids[id-1];
    if (!stack_meta->head)
        cout << " "; 
    else
    {
        node* curr = stack_meta->head;
        while(curr)
        {
            cout << curr->data <<" ";
            curr = curr->next;
        }
    }
    cout << "\n" ;     
}