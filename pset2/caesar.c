#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checks if number of arguments is exactly 2 (0: programm and 1: key)
    if (argc != 2)
    {
        printf("Programm must have one command line argument only");
        return 1;
    }

    // setting up the loop and getting input from user
    int k = atoi(argv[1]);
    string plain = get_string("plaintext: ");
    int l = strlen(plain);

    printf("ciphertext: ");

    // looping over each char in string and transforming char to new char based on key value, but only if char is alphabetical
    for (int i = 0; i < l; i++)
    {
        char c = plain[i];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                int n = c;
                int ciph = (n - 65 + k) % 26;
                int out = ciph + 65;

                printf("%c", out);
            }
            else
            {
                int n = c;
                int ciph = (n - 97 + k) % 26;
                int out = ciph + 97;

                printf("%c", out);
            }
        }
        else
        {
            printf("%c", c);
        }

    }
    printf("\n");
}
