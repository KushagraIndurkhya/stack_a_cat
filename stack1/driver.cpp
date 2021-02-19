/*
Stack1 driver.cpp
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
    stack_id stacks[m];
    for (int i = 1; i <= m; i++)
        stacks[i]=create(n);
    //performing n operatons
    for (int i = 0; i < n; i++)
    {
        int sid,in;
        string operation;
        cin >> sid >> operation ;
        if (operation=="push")
        {
            cin >> in;
            push(stacks[sid],in);
        }
        else if (operation=="pop")
            pop(stacks[sid]);

        else
        {
            cout << "INVALID INPUT";
            exit(1);
        }         
    }
    //printing the state of all stacks after all operations
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
        printstack(stacks[i]);
    }
    //destroying all stacks
    for (int i = 1; i <= m; i++)
        destroy(stacks[i]);

    return 0;
}