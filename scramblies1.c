// Not optimized
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
// linked list structure
typedef struct node
{
    char c;
    struct node *next;
}
node;

// Function definitions
bool scramble(const char *str1, const char *str2);
void free_list(node *n);

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
    // Getting the string lengths
    int n1 = strlen(str1), n2 = strlen(str2);
    
    // If length of str2 > length of str1 return false
    if (n2 > n1)
    {
        return false;
    }
    
    // Creating new linked lists named list, p and n and make "list" a null pointer
    node *list = NULL, *p, *n;
    
    // Store the str1 into linked list "list" char by char
    for (int i = 0; i < n1; i++)
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Space allocation failed\n");
            free_list(list);
            return 1;
        }

        n->c = str1[i];
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else
        {
            p->next = n;
        }
        p = n;
    }

    // Initialize count to 0
    int count = 0;

    // If str2 characters are equal to "list" characters then remove those characters from the list
    for (int i = 0; i < n2; i++)
    {
        p = list;
        n = list;
        while (p != NULL)
        {
            if (str2[i] == p->c)
            {
                if (p == list)
                {
                    list = list->next;
                }
                else
                {
                    n->next = p->next;
                }
                free(p);
                count++;
                goto here;
            }
            if (p != n)
            {
                n = n->next;
            }
            p = p->next;
        }
        here:;

        // for (node *tmp = list; tmp != NULL; tmp = tmp->next)
        // {
        //     printf("%c ", tmp->c);
        // }
        // printf("\n");
    }

    // Free the "list"
    free_list(list);

    // Check if count = length of str2
    if (count == n2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to free the list
void free_list(node *n)
{
    while (n != NULL)
    {
        node *tmp = n->next;
        free(n);
        n = tmp;
    }
    return;
}