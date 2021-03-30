#include <assert.h>
#include "main.h"

void test() {
    int arr[8][8]={0};
    arr[0][0]=1;
    assert(impactCheck(0,0, arr) == 0);
    arr[0][2]=1;
    assert(impactCheck(0,0, arr) == 1);
    arr[0][2]=0;
    arr[5][0]=1;
    assert(impactCheck(0,0, arr) == 1);
    arr[5][0]=0;
    arr[5][5]=1;
    assert(impactCheck(0,0, arr) == 1);
    arr[5][5]=0;
    arr[5][4]=1;
    arr[4][5]=1;
    assert(impactCheck(0,0, arr) == 0);
    arr[3][2]=1;
    arr[5][4]=0;
    assert(impactCheck(3,2, arr) == 0);
    arr[2][1]=1;
    assert(impactCheck(3,2, arr) == 1);
}
#undef main
int main() {
    test();
    return 0;
}