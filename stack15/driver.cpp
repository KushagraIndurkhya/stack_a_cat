/*
Stack15 driver.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/
#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

//driver code
int main()
{
    int m,n;
    cin >> m >> n;
    //creating m stacks
    argument_object* stacks[m];

    for (int i = 1; i <= m; i++)
        stacks[i] = make_stack();

    //performing n operations
    for (int i = 0; i < n; i++)
    {
        int sid;
        long long int in;
        string operation;
        cin >> sid >> operation ;
        if (operation=="push")
        {
            cin >> in;
            (*stacks[sid])(stack_push,in);
        }
        else if (operation=="pop")
            (*stacks[sid])(stack_pop);
        else
        {
            cout << "INVALID INPUT";
            exit(1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
        (*stacks[i])(stack_print); //printing stack
        (*stacks[i])(stack_destroy);//destroying stack
    }

    return 0;
}