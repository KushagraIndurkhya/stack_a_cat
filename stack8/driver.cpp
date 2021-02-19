/*
Stack8 driver.cpp
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
    stack* stacks[m];
    for (int i = 1; i <= m; i++)
        stacks[i]=new stack(n);
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
            stacks[sid]->push(in);
        }
        else if (operation=="pop")
            stacks[sid]->pop();

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
        stacks[i]->printstack();
    }
    //destroying all stacks
    for (int i = 1; i <= m; i++)
    {
        delete(stacks[i]);
    }

    return 0;
}