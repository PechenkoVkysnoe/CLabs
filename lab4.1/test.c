#include <assert.h>
#include "main.h"

void test() {
    assert(StoI(5, "12345") == 12345);
    assert(StoI(1, "0") == 0);
    assert(StoI(8, "91564832") == 91564832);
    assert(StoI(3, "321") == 321);
}
#undef main
int main() {
    test();
    return 0;
}