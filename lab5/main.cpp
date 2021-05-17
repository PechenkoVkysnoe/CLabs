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
    cout << "Fill list1"<<endl;;
    for (int i = 0; i < length; i++)
    {
        cout << "Write value " << i+1 <<" elements " <<endl;
        cin >> value;
        list1.push_back(value);
    }
    cout << "Fill list2"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Write value " << i+1 <<" elements " <<endl;
        cin >> value;
        list2.push_back(value);
    }
    DoubleList res = DoubleList::merge(list1, list2);
    res.print();
    getchar();
    system("pause");
}