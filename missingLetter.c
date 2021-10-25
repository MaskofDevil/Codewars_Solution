// Finds missing letter in a given sequence of characters
#include <stdio.h>

char findMissingLetter(char array[], int arrayLength);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s char1 char2 ...\n", argv[0]);
        return 1;
    }
    int n = argc - 1;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = *argv[i + 1];
    }
    printf("The missing letter is %c\n", findMissingLetter(arr, n));
}

char findMissingLetter(char array[], int arrayLength)
{
    char tmpChar = array[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] != tmpChar)
        {
            return tmpChar;
        }
        tmpChar++;
    }
}