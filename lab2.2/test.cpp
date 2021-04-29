  
#include <assert.h>
#include "DoubleList.h"

void test() {
    DoubleList list1,list2,res,test;
    list1.push_back(1);
    list1.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    res = DoubleList::merge(list1, list2);
    assert(test==res);
    
}

int main() {
    test();
    return 0;
}