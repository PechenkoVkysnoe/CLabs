#include <assert.h>
#include "main.h"
#include <malloc.h>

void test() {
    struct Medicines *med = (struct Medicines*)calloc(1, sizeof(struct Medicines));
    med[0].name[0]='Y';
    med[0].name[1]='g';
    med[0].name[2]='o';
    med[0].name[3]='l';
    med[0].date[0]='2';
    med[0].date[1]='7';
    med[0].date[2]='.';
    med[0].date[3]='0';
    med[0].date[4]='1';
    med[0].date[5]='.';
    med[0].date[6]='1';
    med[0].date[7]='0';
    med[0].num[0]='6';
    med[0].cost[0]='9';
    assert(FullCost(med, 0) == 54);
    med[0].num[0]='2';
    med[0].num[1]='3';
    med[0].cost[0]='4';
    med[0].cost[1]='2';
    assert(FullCost(med, 0) == 966);
    med[0].num[0]='1';
    med[0].num[1]='2';
    med[0].cost[0]='4';
    med[0].cost[1]='8';
    assert(FullCost(med, 0) == 576);
}
#undef main
int main() {
    test();
    return 0;
}