#include <assert.h>
#include <math.h>
#include "main.h"

void test() {
    assert(calc(1, 0.1) == 2);
    assert(calc(-1, 0.1) == 2);
    assert(calc(0, 0.1) == 0);
    assert(calc(1.5, 0.0001) == 5);
    assert(calc(0.2, 0.042) == 1);
}
#undef main
int main() {
    test();
    return 0;
}