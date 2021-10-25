// Trailing zeros in factorial of a number
#include <stdio.h>

long zeros(long n);
 
int main(void)
{
    long num;
    printf("Number: ");
    scanf("%ld", &num);
    printf("Factorial of %ld contains %ld zero(s)\n", num, zeros(num));
    return 0;
}

// long zeros(long n)
// {
//     long two = 0, five = 0, zero = 0;
//     if (n == 0)
//     {
//         return 0;
//     }
//     for (long i = 1; i <= n; i++)
//     {
//         long val = i;
//         while (val % 2 == 0)
//         {
//             val /= 2;
//             two++;
//         }
//         while (val % 5 == 0)
//         {
//             val /= 5;
//             five++;
//         }
//     }
//     zero += (two < five ? two : five);
//     return zero;
// }

long zeros(long n)
{
    long zero = 0;
    if (n <= 0)
    {
        return 0;
    }
    for (int i = 5; n / i > 0; i *= 5)
    {
        zero += n / i;
    }
    return zero;
}