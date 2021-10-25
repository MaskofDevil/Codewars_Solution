// Incomplete
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

ssize_t find_short(const char *s);

int main(void)
{
    char *s = get_string("String: ");
    if (find_short(s) == -1)
    {
        printf("Program Failed\n");
        return 1;
    }
    else
    {
        printf("Shortest Word in %s: %d\n", s, (int)find_short(s));
    }
    return 0;
}

ssize_t find_short(const char *s)
{
    int count = 0, small;
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            small = count < (i - count - 1) ? count : (i - count - 1);
            count += i;
        }
    }
    if (small > 0)
    {
        return small;
    }
    return -1;
}