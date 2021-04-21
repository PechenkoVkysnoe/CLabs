#include <iostream>
#include <utility>

#include "tree.h"
using namespace std;


int main()
{
    Tree tree;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        tree.insert(str[i]);
    }
    cout << tree.MaxDepth()<<endl;
    system("pause");
    return 0;
}