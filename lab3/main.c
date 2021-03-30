#include <stdio.h>
int impactCheck(int y, int x, int arr[8][8])
{
    int value = 0;
    int i=0;
    for (i = 0; i < 8; i++)
    {
        if (i!=x)
        {
            if (arr[y][i] == 1)
            {
                value = 1;
            }
        }
        if (i != y)
        {
            if (arr[i][x] == 1)
            {
                value = 1;
            }
        }
    }
    int tmpX = x, tmpY = y;
    while (tmpX < 7 && tmpY < 7)
    {
        if (arr[++tmpY][++tmpX] == 1)
        {
            value = 1;
        }
    }
    tmpX = x, tmpY = y;
    while (tmpX > 0 && tmpY > 0)
    {
        if (arr[--tmpY][--tmpX] == 1)
        {
            value = 1;
        }
    }
    tmpX = x, tmpY = y;
    while (tmpX < 7 && tmpY > 0)
    {
        if (arr[--tmpY][++tmpX] == 1)
        {
            value = 1;
        }
    }
    tmpX = x, tmpY = y;
    while (tmpX > 0 && tmpY < 7)
    {
        if (arr[++tmpY][--tmpX] == 1)
        {
            value = 1;
        }
    }
    return value;
}
int main()
{
    int arr[8][8] = { 0 };
    arr[0][2] = arr[1][5] = arr[2][3] = arr[3][0] = arr[4][7] = arr[5][4] = arr[6][6] = arr[7][1] = 1;
    int check=0;
    int i=0;
    for (i = 0; i < 8; i++)
    {
        int j=0;
        for (j = 0; j < 8; j++)
        {
            if (arr[i][j]==1)
            {
                if (impactCheck(i, j, arr))
                {
                    check = 1;
                    printf("The queen is under attack");
                }
            }
        }
    }
    if (check==0)
    {
        printf("The check was successful, the queens are not under attack\n");
        int i=0;
        for (i = 0; i < 8; i++)
        {
            int j=0;
            for (j = 0; j < 8; j++)
            {
                printf("%d",arr[i][j]);
                printf(" ");
            }
            printf("\n");
        }
    }
    getchar();
    return 0;
}


