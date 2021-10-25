#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

void uint32_to_ip(uint32_t ip, char *output);

int main(void)
{
    uint32_t ip32;
    printf("IP in unsigned 32-bit format: ");
    scanf("%u", &ip32);

    char *IPv4 = malloc(16 * sizeof(char));
    
    uint32_to_ip(ip32, IPv4);
    
    printf("%u is %s in IPv4\n", ip32, IPv4);
    
    free(IPv4);
    
    return 0;
}

void uint32_to_ip(uint32_t ip, char *output)
{
    uint32_t temp = ip;
    BYTE out[4] = {0};

    // Convert unsigned ip into an array of octets
    for (int i = 3, m = 1; (i >= 0) && (temp != 0); temp /= 2, m *= 2)
    {
        if (m > 128)
        {
            m = 1;
            i--;
        }
        out[i] += (temp % 2) * m;
    }
    
    // Insert dots in between octets and make it a string
    int dot = 0;
    for (int i = 0, j = 0; i < 4; i++)
    {
        j += sprintf(&output[j], "%d", out[i]);
        if (dot < 3)
        {
            output[j] = '.';
        }
        j++;
        dot++;
    }

    // Just in one Line
    // sprintf(output, "%u.%u.%u.%u", out[0], out[1], out[2], out[3]);
    return;
}