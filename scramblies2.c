// Optimized
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

// Function definitions
bool scramble(const char *str1, const char *str2);

int main(void)
{
    // dynamically allocating string 1 and taking user input to store in the string
    char *str1 = malloc(SIZE * sizeof(char));
    if (str1 == NULL)
    {
        printf("Space allocation failed\n");
        return 1;
    }
    printf("String 1: ");
    scanf("%s", str1);
    
    // dynamically allocating string 2 and taking user input to store in the string
    char *str2 = malloc(SIZE * sizeof(char));
    if (str2 == NULL)
    {
        printf("Space allocation failed\n");
        free(str1);
        return 1;
    }
    printf("String 2: ");
    scanf("%s", str2);
    
    // stroring the return value(true / false) inside a variable
    bool isPossible = scramble(str1, str2);
    
    // freeing the strings
    free(str1);
    free(str2);
    
    // checking the value of isPossible
    if (!isPossible)
    {
        printf("Not possible\n");
        return 1;
    }
    printf("Possible\n");
    return 0;
}

bool scramble(const char *str1, const char *str2)
{
    int countAlpha[26] = {0};

    for (char *c = str1; *c; c++)
    {
        countAlpha[*c - 97]++;
    }

    for (char *c = str2; *c; c++)
    {
        countAlpha[*c - 97]--;
        if (countAlpha[*c - 97] < 0)
        {
            return false;
        }
    }

    return true;
}