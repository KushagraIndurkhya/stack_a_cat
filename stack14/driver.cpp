/*
Stack14 driver.cpp
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
    stack stacks[m];
    for (int i = 1; i <= m; i++)
        stacks[i] = *(new stack());

    for (int i = 0; i < n; i++)
    {  
        int sid;
        long long int in;
        string operation;
        cin >> sid >> operation ;
        if (operation=="push")
        {
            cin >> in;
            stacks[sid].push(in);
        }
        else if (operation=="pop")
            stacks[sid].pop();
        else
        {
            cout << "INVALID INPUT";
            exit(1);
        }         
    }
    //printing all the stacks
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
        stacks[i].print();
    }

    return 0;
}