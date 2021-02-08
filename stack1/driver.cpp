#include <iostream>
#include <string>
#include <vector> 
#include "stack.hpp"
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        create(n);
    for (int i = 0; i < n; i++)
    {
        int sid,in;
        string operation;
        cin >> sid >> operation ;
        if (operation=="push")
        {
            cin >> in;
            push(sid,in);
        }
        else if (operation=="pop")
            pop(sid);

        else
        {
            cout << "INVALID INPUT";
            exit(1);
        }         
    }
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
        printstack(i);
    }
    for (int i = 1; i <= m; i++)
        destroy(i);

    return 0;
}