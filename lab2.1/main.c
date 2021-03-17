#include <stdio.h>
int get(int a) {
    int value;
    char ch;
    while (scanf("%d%c", &value, &ch) != 2 || ch != '\n' || value < 1 || value > a) {
        printf("Enter correct number\n");
        while (getchar() != '\n') {
        }
    }
    return value;
}
double to_km(double value){
    return value/ 1000000;
}
double to_m(double value){
    return value/ 1000;
}
double to_c(double value){
    return value/ 10;
}
double to_verst(double value){
    return value/ 1066800;
}
double to_s(double value){
    return value/ 2133.6;
}
double to_a(double value){
    return value/ 711.2;
}
double to_versh(double value){
    return value/ 44.45;
}
double to_miles(double value){
    return value/ 1609344;
}
double to_y(double value){
    return value/ 914.4;
}
double to_f(double value){
    return value/ 304.8;
}
double to_i(double value){
    return value / 25.4;
}
int main() {
    int value;
    double length=0;
    double tmp;
    while (1) {
        printf("Enter 1 to input length(kilometers, meters, centimeters,millimeters)\n"
               "Enter 2 to conversion length into Russian traditional units (versts,arshins, sazhens, vershoks)\n"
               "Enter 3 to conversion length into English traditional units (miles,yards, feet, inches)\n"
               "Enter 4 to output of a report the entered length (kilometers,meters,centimeters,millimeters)\n"
               "Enter 5 to see information about the version and the author of the program\n"
               "Enter 6 to quite the program\n");
        value = get(6);
        switch (value) {
            case 1:
                printf("Enter 1 to input length in kilometers\n"
                       "Enter 2 to input length in meters\n"
                       "Enter 3 to input length in centimeters\n"
                       "Enter 4 to input length in millimeters\n");
                value = get(4);
                switch (value) {
                    case 1:
                        printf("Enter length\n");
                        scanf("%lf", &tmp);
                        length = tmp*1000000;
                        break;
                    case 2:
                        printf("Enter length\n");
                        scanf("%lf", &tmp);
                        length = tmp*1000;
                        break;
                    case 3:
                        printf("Enter length\n");
                        scanf("%lf", &tmp);
                        length = tmp*10;
                        break;
                    case 4:
                        printf("Enter length\n");
                        scanf("%lf", &tmp);
                        length = tmp;
                        break;
                }
                break;
            case 2:
                printf("Enter 1 to conversion length in versts\n"
                       "Enter 2 to conversion length in arshins\n"
                       "Enter 3 to conversion length in sazhens\n"
                       "Enter 4 to conversion length in vershoks\n");
                value = get(4);
                switch (value) {
                    case 1:
                        printf("Length in versts is: %lf\n", to_verst(length));
                        break;
                    case 2:
                        printf("Length in arshins is: %lf\n", to_a(length) );
                        break;
                    case 3:
                        printf("Length in sazhens is: %lf\n",to_s(length) );
                        break;
                    case 4:
                        printf("Length in vershoks is: %lf\n",to_versh(length));
                        break;
                }
                break;
            case 3:
                printf("Enter 1 to conversion length in miles\n"
                       "Enter 2 to conversion length in yards\n"
                       "Enter 3 to conversion length in feet\n"
                       "Enter 4 to conversion length in inches\n");
                value = get(4);
                switch (value) {
                    case 1:
                        printf("Length in miles is: %lf\n", to_miles(length) );
                        break;
                    case 2:
                        printf("Length in yards is: %lf\n", to_y(length) );
                        break;
                    case 3:
                        printf("Length in feet is: %lf\n", to_f(length) );
                        break;
                    case 4:
                        printf("Length in inches is: %lf\n", to_i(length));
                        break;
                }
                break;
            case 4:
                printf("Enter 1 to output of a report the entered length in kilometers\n"
                       "Enter 2 to output of a report the entered length in meters\n"
                       "Enter 3 to output of a report the entered length in centimeters\n"
                       "Enter 4 to output of a report the entered length in millimeters\n");
                value = get(4);
                switch (value) {
                    case 1:
                        printf("Length in kilometers is: %lf\n", to_km(length));
                        break;
                    case 2:
                        printf("Length in meters is: %lf\n", to_m(length));
                        break;
                    case 3:
                        printf("Length in centimeters is: %lf\n", to_c(length));
                        break;
                    case 4:
                        printf("Length in millimeters is: %lf\n", length);
                        break;
                }
                break;
            case 5:
                printf("Program: measures of length \n"
                       "Version: 1.0.0\n"
                       "Author: Hryharchuk Mikhail\n");
                break;
            case 6:
                return 0;
            default:
                break;
        }
    }
}