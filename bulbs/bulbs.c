#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string msg = get_string("Message: ");

    for (int i = 0, n = strlen(msg); i < n; i += 1)
    {
        int dec = (int) msg[i];

        for (int j = BITS_IN_BYTE - 1; j >= 0; j -= 1)
        {
            int bit = (dec >> j) & 1;
            print_bulb(bit);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
