// !Have to take user input
#include <stdio.h>
#include <string.h>

#define MAX 5

int shortestWord(char **string);
int longestWord(char **string);

int main(void)
{
    char *str[MAX] = {"Hello,", "my", "name", "is", "Tuhin Dhar"};
    printf("The length of the shortest word is %d\n", shortestWord(str));
    printf("The length of the longest word is %d\n", longestWord(str));
    return 0;
}

int shortestWord(char **string)
{
    int count, shortest = strlen(string[0]);
    for (int i = 0, n = MAX; i < n; i++)
    {
        count = strlen(string[i]);
        shortest = count < shortest ? count : shortest;
    }
    return shortest;
}

int longestWord(char **string)
{
    int count, longest = strlen(string[0]);
    for (int i = 0, n = MAX; i < n; i++)
    {
        count = strlen(string[i]);
        longest = count > longest ? count : longest;
    }
    return longest;
}