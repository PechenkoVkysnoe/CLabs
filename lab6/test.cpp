#include <assert.h>
#include "tree.h"

void test() {
    Tree tree;
    tree.insert('a');
    assert(tree.MaxDepth() == 1);
    tree.insert('b');
    assert(tree.MaxDepth() == 2);
}

int main() {
    test();
    return 0;
}