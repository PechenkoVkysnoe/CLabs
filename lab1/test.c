#include <assert.h>
#include "main.h"

void test(){
    assert(convert_rub(2.0) == 2);
    assert(convert_rub(2.99) == 2);
    assert(convert_rub(2.15645645245245) == 2);
    assert(convert_pen(2.15, 2) == 15);
    assert(convert_pen(2.289, 2) == 29);
    assert(convert_pen(2.299, 2) == 30);
    assert(convert_pen(2.0009, 2) == 0);
}
#undef main
int main(){
    test();
    return 0;
}
