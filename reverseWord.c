// Reverse each word in a gievn sentence
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(const char* text);

int main(void)
{
    char *s = get_string("String: ");
    char *r = reverseWords(s);
    printf("Reversed String: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", r[i]);
    }
    printf("\n");
    free(r);
    return 0;
}

char* reverseWords(const char* text)
{
    // Dynamically allocate reverse string
    int n = strlen(text), start = 0;
    char *reverse = malloc(n + 1);

    // Loops through string char by char
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        // If char == space or null char
        if (text[i] == ' ' || text[i] == '\0')
        {
            int j = 0;
            // Reverses the word and stores it in reverse
            while (start < i)
            {
                reverse[start] = text[i - 1 - j];
                j++;
                start++;
            }
            // Reserve space
            reverse[i] = ' ';
            start++;
        }
    }
    reverse[n] = '\0';
    return reverse;
}