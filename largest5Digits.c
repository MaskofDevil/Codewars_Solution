// Finds the largest 5 digit number from a given number
#include <stdio.h>
#include <string.h>

#define MAX 11

int largest_five_digits(const char *digits);

int main()
{
    char num[MAX];
    printf("Number: ");
    scanf("%s", num);
    if (!largest_five_digits(num))
    {
        printf("Enter a number of min 5 digits\n");
        return 1;
    }
    printf("Largest five digits %d\n", largest_five_digits(num));
    return 0;
}

int largest_five_digits(const char *digits)
{
    int n = strlen(digits);
    if (n < 5)
    {
        return 0;
    }
    int num1 = 0, num2 = 0;
    for (int i = (n - 5), j = 0; i >= 0; i--, j++)
    {
        for (int k = j; k < (n - i); k++)
        {
            num2 *= 10;
            num2 += ((int) digits[k] - 48);
        }
        num1 = num1 > num2 ? num1 : num2;
        num2 = 0;
    }
    return num1;
}