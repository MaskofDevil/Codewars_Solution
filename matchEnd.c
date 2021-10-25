// Checks if 1st string ends with 2nd string
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool matchEndString(char *str, char *ending);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s str1 str2\n", argv[0]);
        return 1;
    }
    if (matchEndString(argv[1], argv[2]))
    {
        printf("%s ends with %s\n", argv[1], argv[2]);
    }
    else
    {
        printf("%s does not end with %s\n", argv[1], argv[2]);
    }
    return 0;
}

bool matchEndString(char *str, char *ending)
{
    int n1 = strlen(str), n2 = strlen(ending);
    if (n1 < n2)
    {
        return false;
    }
    for (int i = n1 - 1, j = n2 - 1; j >= 0; i--, j--)
    {
        if (str[i] != ending[j])
        {
            return false;
        }
    }
    return true;
}