#include <cs50.h>
#include <stddef.h>
#include <stdio.h>
 
int find_missing(const int *nums, size_t n);

int main(void)
{
    size_t n = get_int("Size: ");
    int array[n];
    printf("Arithmetic Progression: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Missing term in AP: %d\n", find_missing(array, n));
    return 0;
}

int find_missing(const int *nums, size_t n)
{
    if (nums[0] == nums[1])
    {
        return nums[0];
    }
    int d = nums[1] - nums[0], check = nums[0];
    if (d > 0)
    {
        d = d < (nums[2] - nums[1]) ? d : (nums[2] - nums[1]);
    }
    else
    {
        d = d > (nums[2] - nums[1]) ? d : (nums[2] - nums[1]);
    }
    for (size_t i = 0; i < n; i++)
    {
        if (nums[i] != check)
        {
            return check;
        }
        else
        {
            check += d;
        }
    }
    return 0;
}