#include <stdio.h>
#include <math.h>
int calc(double x, double e) {
    double res = 0;
    int step = 0;
    int fact = 1;
    while (fabs(sin(x) - res) >= e)
    {
        res += (step % 2 == 0 ? 1 : -1) * pow(x, 2 * step + 1) / fact;
        step++;
        fact *= (2 * step + 1) * (2 * step);
    }
    return step;
}
double get_angle() {
    double value;
    char ch;
    while (scanf("%lf%c", &value, &ch) != 2 || ch != '\n' || value < -1.57 || value>1.57) {
        printf("Enter the correct angle, angle less PI/2, more -PI/2\n");
        while (getchar() != '\n') {
        }
    }
    return value;
}
double get_error() {
    double value;
    char ch;
    while (scanf("%lf%c", &value, &ch) != 2 || ch != '\n' || value <= 0) {
        printf("Enter the correct error, error more 0\n");
        while (getchar() != '\n') {
        }
    }
    return value;
}
int main()
{
    double x, e;
    printf("Enter angle in radian\n");
    x = get_angle();
    printf("Enter error\n");
    e = get_error();
    printf("%d", calc(x, e));
    getchar();
    return 0;
}


