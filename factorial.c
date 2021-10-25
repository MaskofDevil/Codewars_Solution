#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *factorial(int n);

int main(void)
{
    int num;
    printf("Number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %s\n", num, factorial(num));
    return 0;
}

char *factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return "1";
    }
    else
    {

    }
    return "";
}