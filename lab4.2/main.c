#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <locale.h>
#include <math.h>
#include <malloc.h>

int FullCost(struct Medicines* med, int i) {
    int k = 0, j = 0, num = 0, cost = 0, fullCost = 0, tr = 1;
    while (med[i].cost[k] != '\0') {
        k++;
    }
    while (med[i].num[j] != '\0') {
        j++;
    }
    k--;
    j--;
    for (j; j >= 0; j--) {
        num += tr * ((int)(med[i].num[j] - '0'));
        tr *= 10;
    }
    for (tr = 1, k; k >= 0; k--) {
        cost += tr * ((int)(med[i].cost[k] - '0'));
        tr *= 10;
    }
    return fullCost = cost * num;
}

int main()
{
    struct Medicines* med = NULL;
    char buff[512];
    int i = 0, j = 0, k = 0, count = 0, fullCost = 0, cost = 0, num = 0, tr = 0;
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Input file is invalid");
        exit(-1);
    }
    while (!feof(file)) {
        fgets(buff, BUFSIZ, file);
        count++;
    }
    med = (struct Medicines*)calloc(count, sizeof(struct Medicines));
    if (med == NULL) {
        printf("Error: can't allocate memory");
        return 0;
    }
    fseek(file, 0, 0);
    while (j < count) {
        fgets(buff, BUFSIZ, file);
        for (k = 0, i; buff[i] != ' '; i++, k++) {
            med[j].name[k] = buff[i];
        }
        med[j].name[k] = '\0';
        i++;
        for (k = 0, i; buff[i] != ' '; i++, k++) {
            med[j].date[k] = buff[i];
        }
        med[j].date[k] = '\0';
        i++;
        for (k = 0, i; buff[i] != ' '; i++, k++) {
            med[j].num[k] = buff[i];
        }
        med[j].num[k] = '\0';
        i++;
        for (k = 0, i; buff[i] != ' ' && buff[i] != '\n' && buff[i] != '\0'; i++, k++) {
            med[j].cost[k] = buff[i];
        }
        med[j].cost[k] = '\0';
        j++;
        i = 0;
    }
    fclose(file);
    int date = 0;
    for (i = 0; i < count; i++) {
        date = fullCost = num = cost = 0;
        for (tr = 0, j = 7; j >= 6; j--, tr++) {
            date += (int)pow(10, tr) * (((int)med[i].date[j]) - 48);
        }
        if (date < 21) {
            printf("%s %s %s %s Full cost = %d\n", med[i].name, med[i].date, med[i].num, med[i].cost, FullCost(med, i));
        }
        else if (date == 21) {
            date = 0;
            for (tr = 0, j = 4; j >= 3; j--, tr++) {
                date += (int)pow(10, tr) * (((int)med[i].date[j]) - 48);
            }
            if (date < 4) {
                printf("%s %s %s %s Full cost = %d\n", med[i].name, med[i].date, med[i].num, med[i].cost, FullCost(med, i));
            }
            else if (date == 4) {
                date = 0;
                for (tr = 0, j = 1; j >= 0; j--, tr++) {
                    date += (int)pow(10, tr) * (((int)med[i].date[j]) - 48);
                }
                if (date < 8) {
                    printf("%s %s %s %s Full cost = %d\n", med[i].name, med[i].date, med[i].num, med[i].cost, FullCost(med, i));
                }
            }
        }
    }
    free(med);
    getchar();
    return 0;
}