#include <stdio.h>
int StoI(int n, char str[80])
{
    int result = 0;
    int i;
	for (i = 0; i < n; i++)
	{
		result += str[i]-48;
		result *= 10;
	}
	result /= 10;
	return result;
}
int main()
{
    int i = 0;
    int n=0;
    char str[80], ch;
    printf("Enter string of simbols: \n");
    while ((ch = getchar()) != '\n') { 
    str[i++] = ch;
    n++;
    }
    str[i] = '\0';
    printf("%d",StoI(n,str));
    getchar();
    return 0; 
}


