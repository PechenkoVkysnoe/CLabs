#include <iostream>
#include <iterator>
#include "DoubleList.h"
using namespace std;

int main()
{
    DoubleList list1,list2;
    int length;
    cout << "Write lenght" << endl;
    cin >> length;
    int value;
    cout << "Fill list1";
    for (int i = 0; i < length; i++)
    {
        cout << "Write value" << endl;
        cin >> value;
        list1.push_back(value);
    }
    cout << "Fill list2";
    for (int i = 0; i < length; i++)
    {
        cout << "Write value" << endl;
        cin >> value;
        list2.push_back(value);
    }
    DoubleList res = DoubleList::merge(list1, list2);
    res.print();
    getchar();
}