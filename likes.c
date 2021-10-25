#include <stdio.h>
#include <stdlib.h>

#define WORD_SIZE 10
#define SENTENCE_SIZE 100
 
char *likes(size_t n, const char *const names[n]);

int main(void)
{
    size_t n;
    printf("No of people: ");
    scanf("%ld", &n);
    char *names[n];
    for (int i = 0; i < n; i++)
    {
        names[i] =  malloc(WORD_SIZE * sizeof(char));
        if (names[i] == NULL)
        {
            printf("Space cannot be allocated\n");
            return 1;
        }

        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);
    }
    char *l = likes(n, names);
    printf("%s\n", l);
    for (int i = 0; i < n; i++)
    {
        free(names[i]);
    }
    free(l);
    return 0;
}

char *likes(size_t n, const char *const names[n])
{
    char *people = malloc(SENTENCE_SIZE * sizeof(char));
    if (n <= 3)
    {
        if (n <= 0)
        {
            sprintf(people, "no one likes this");
        }
        else if (n == 1)
        {
            sprintf(people, "%s likes this", names[0]);
        }
        else if (n == 2)
        {
            sprintf(people, "%s and %s like this", names[0], names[1]);
        }
        else
        {
            sprintf(people, "%s, %s and %s like this", names[0], names[1], names[2]);
        }
    }
    else
    {
        sprintf(people, "%s, %s and %ld others like this", names[0], names[1], (n - 2));
    }
    return people;
}