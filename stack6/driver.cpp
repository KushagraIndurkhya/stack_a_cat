/*
Stack6 driver.cpp
Author: Kushagra Indurkhya (CS19B1017)
*/

#include <iostream>
#include <string>
#include "stack.hpp" //including stack interface
using namespace std;

//driver code
int main()
{
    int m,n;
    cin >> m >> n;
    //creating m stacks
    stack::stack_id stacks[m];
    for (int i = 1; i <= m; i++)
        stacks[i]=stack::create(n);
    //performing n operatons
    for (int i = 0; i < n; i++)
    {
        int sid;
        long long int in;
        string operation;
        cin >> sid >> operation ;
        if (operation=="push")
        {
            cin >> in;
            stack::push(stacks[sid],in);
        }
        else if (operation=="pop")
            stack::pop(stacks[sid]);

        else
        {
            cout << "INVALID INPUT";
            exit(1);
        }         
    }
    //printing the state of all stacks after all operations
    for (int i = 1; i <= m; i++)
    {
        // cout << i << stacks[i] <<"\n";
        cout << i << " ";
        stack::printstack(stacks[i]);
    }
    //destroying all stacks
    for (int i = 1; i <= m; i++)
    {
        stack::destroy(stacks[i]);
        stack::cleanup(stacks[i]);
    }

    return 0;
}