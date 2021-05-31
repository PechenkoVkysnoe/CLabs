#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test() {
    int** array = array_malloc(5, 5);
    calculation(array, 5);
    assert(testing(3, 3, array) == 2);
    assert(testing(1, 1, array) == 3);
    assert(testing(4, 4, array) == 4);
    assert(testing(2, 1, array) == 4);
    assert(testing(2, 3, array) == 1);
	array_free(array, 5);
    return 0;
}
#undef main
int main() {
    test();
    return 0;
}
