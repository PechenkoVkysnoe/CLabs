#include <assert.h>
#include "tree.h"

void test() {
    Tree tree;
    tree.insert('a');
    assert(tree.MaxDepth() == 1);
    tree.insert('b');
    assert(tree.MaxDepth() == 2);
    tree.insert('a');
    tree.insert('c');
    assert(tree.MaxDepth() == 3);
    tree.insert('m');
    tree.insert('i');
    tree.insert('s');
    tree.insert('h');
    tree.insert('a');
    assert(tree.MaxDepth() == 6);
}

int main() {
    test();
    return 0;
}