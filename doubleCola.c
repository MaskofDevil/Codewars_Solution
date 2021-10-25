#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

const char *who_is_next(long long n, size_t length, const char *const a[length]);
 
int main(void)
{
    size_t n;
    printf("Number: ");
    scanf("%ld", &n);
    char *names[n];
    for (int i = 0; i < n; i++)
    {
        names[i] =  malloc(10 * sizeof(char));
        if (names[i] == NULL)
        {
            printf("Space cannot be allocated\n");
            return 1;
        }

        printf("String %d: ", i + 1);
        scanf("%s", names[i]);
    }

    long long pos;

    printf("Position: ");
    scanf("%lld", &pos);

    printf("%s is at the position %lld\n", who_is_next(pos, n, names), pos);

    for (size_t i = 0; i < n; i++)
    {
        free(names[i]);
    }

    return 0;
}

const char *who_is_next(long long n, size_t length, const char *const a[length])
{
    int m = 1;

    while (m * length < n)
    {
        n -= m * length;
        m *= 2;
    }

    return a[(n - 1) / m];
}