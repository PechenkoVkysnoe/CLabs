#include <stdlib.h>
#include <stdio.h>

int** array_malloc(int n, int m)
{
    int** array;
    if (!(array = (int**) malloc(n * sizeof(int*))))
    {
        printf("Error: can't allocate memory");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++)
    {
        if (!(array[i] = (int*) malloc(m * sizeof(int))))
        {
            printf("Error: can't allocate memory");
            exit(1);
        }
    }
    return array;
}

void array_free(int **array, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);
}

void calculation(int **array, int n)
{
    int i;
    for (i = 0; i < n; i++)
	{
		int a = i + 1;
        int j;
		for (j = 0; j < n; j++)
		{
			array[i][j] =  a;
			a++;
			if (a > n) a = 1;
		}
	}
}
int testing(int x, int y, int** array)
{
    return array[x][y];
}

int main()
{
    int n;
	printf("Enter number of lines : ");
	scanf("%d$", &n);
	int **array = array_malloc(n, n);
	calculation(array, n);
    int i;
	for (i = 0; i < n; i++)
	{
        int j;
		for (j = 0; j < n; j++)
		{
			printf("%5d ", array[i][j]);
		}
		printf("\n");
	}
    array_free(array, n);
	getchar();
	return 0;
}
