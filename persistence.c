// Persistence Value: Number of times multiply a value until a single digit value
#include <stdio.h>

int persistence(int n);

int main(void)
{
    int num;
    printf("Value: ");
    scanf("%d", &num);
    printf("Persistence value: %d\n", persistence(num));
    return 0;
}

int persistence(int n) {
    int mul, count = 0;

    while (n > 9)
    {
        mul = 1;
        while (n)
        {
            mul *= n % 10;
            n /= 10;
        }
        count++;
        n = mul;
    }

    return count;
}