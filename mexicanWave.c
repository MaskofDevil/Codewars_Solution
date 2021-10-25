#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wave(const char *y, char **target);

int main(void)
{
    char *str = get_string("String: ");

    int size = strlen(str);
    char *modStr[size];
    for (int i = 0; i < size; i++)
    {
        modStr[i] = malloc(size * sizeof(char));
    }

    wave(str, modStr);

    for (int i = 0; i < size; i++)
    {
        if (modStr[i][0] != '\0')
        {
            printf("%s\t", modStr[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        free(modStr[i]);
    }
    return 0;
}

void wave(const char *y, char **target)
{
    int size = strlen(y);
    for (int i = 0; i < size; i++)
    {
        if (y[i] != ' ')
        {
            for (int j = 0; j < size; j++)
            {
                if (j == i)
                {
                    target[i][j] = toupper(y[j]);
                }
                else
                {
                    target[i][j] = y[j];
                }
            }
        }
    }

    return;
}