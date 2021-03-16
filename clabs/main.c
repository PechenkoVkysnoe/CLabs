#include <stdio.h>
#include "main.h"

double get() {
    double value;
    char ch;
    printf("Enter the amount of money\n");
    while (scanf("%lf%c", &value, &ch) != 2 || ch != '\n' || value < 0 || value >= 9999999999) {
        printf("Enter the correct number\n");
        while (getchar() != '\n') {
        }
    }
    return value;
}
int convert_rub(double value){
    return (int) ((value * 100 + 0.5000000000001) / 100);
}
int convert_pen(double value,int rub){
    return (int) (100 * (value - rub) + 0.5);
}
int main() {
    double value;
    value = get();
    int rub = convert_rub(value);
    int pen = convert_pen(value,rub);
    printf("%d rub. %d pen.\n", rub, pen);
    getchar();
    return 0;
}
