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
    // end

    // checking if all characters in the key is alphabetical
    string key = argv[1];
    int keyLength = strlen(key);
    int count = 0;
    for (int i = 0; i < keyLength; i++)
    {
        if (isalpha(key[i]))
        {
            count++;
        }
    }
    if (count != keyLength)
    {
        printf("Second command line argument must be alphabetic only");
        return 1;
    }
    // end

    // getting user input, checking length of input and preparing output text
    string plain = get_string("plaintext: ");
    int l = strlen(plain);

    printf("ciphertext: ");
    // end

    // counter for for index position of key
    int counter = 0;

    // looping over each char in string and transforming char to new char based on key value, but only if char is alphabetical
    for (int i = 0; i < l; i++)
    {
        char c = plain[i];
        if (isalpha(c))
        {
            // identifying the current key value
            int index = counter % keyLength;

            int k;
            if (isupper(key[index]))
            {
                k = (key[index] - 65);
            }
            else
            {
                k = (key[index] - 97);
            }
            // end

            // outputting the cipher character
            if (isupper(c))
            {
                int ciph = (c - 65 + k) % 26;
                int out = ciph + 65;

                printf("%c", out);
            }
            else
            {
                int ciph = (c - 97 + k) % 26;
                int out = ciph + 97;

                printf("%c", out);
            }
            //end
            counter++;
        }
        else
        {
            printf("%c", c);
        }

    }
    printf("\n");
}
