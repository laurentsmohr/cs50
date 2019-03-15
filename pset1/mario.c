#include <stdio.h>
#include <cs50.h>

int height;
int main() {

    do
    {
        height = get_int("Please specify height: ");
    } while (height > 23 || height < 0);

    for (int rows = 1; rows <= height; rows++)
    {
        for(int spaces = height - rows; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for(int hash = 0; hash < rows; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int hash = 0; hash < rows; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
