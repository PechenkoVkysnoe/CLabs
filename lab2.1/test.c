#include <assert.h>
#include <math.h>
#include "main.h"

void test(){
    assert(to_km(1000000)==1);
    assert(to_m(1000000)==1000);
    assert(to_c(1000000)==100000);
    assert(fabs(to_miles(1000000)-0.621371)<0.00001);
    assert(fabs(to_s(1000000)-468.691414)<0.00001);
    assert(fabs(to_a(1000000)-1406.074241)<0.00001);
    assert(fabs(to_versh(1000000)-22497.187852)<0.00001);
    assert(fabs(to_y(1000000)-1093.613298)<0.00001);
    assert(fabs(to_f(1000000)-3280.839895)<0.00001);
    assert(fabs(to_i(1000000)-39370.078740)<0.00001);
    assert(fabs(to_verst(1000000)-0.937383)<0.00001);
}
#undef main
int main(){
    test();
    return 0;
}