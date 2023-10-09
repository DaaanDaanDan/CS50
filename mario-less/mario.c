#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");

    while (height > 8)
    {
        height = get_int("Height: ");
    }

    while (height < 1)
    {
        height = get_int("Height: ");
    }

    for (int i = 0; i < height; i += 1)
    {
        for (int dot = height - i - 1; dot > 0; dot -= 1)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j += 1)
        {
            printf("#");
        }
        printf("\n");
    }
}