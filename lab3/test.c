#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_position() {
    int** array = array_malloc(5, 5);
    calculation(array, 5);
    assert(test(3, 3, array) == 2);
    assert(test(1, 1, array) == 3);
    assert(test(4, 4, array) == 4);
    assert(test(2, 1, array) == 4);
    assert(test(2, 3, array) == 1);
	array_free(array, 5);
    return 0;
}
#undef main
int main() {
    test_position();
    return 0;
}
