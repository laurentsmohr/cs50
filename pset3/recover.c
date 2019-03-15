#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

// helper function - checks if chunk is a jpeg
bool isBeginning(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    int imageNumber = 0;

    // end-of-file
    bool eof = false;
    // is only false until first image
    bool writingToImg = false;

    FILE *img = NULL;

    // until eof
    while (!eof)
    {
        // read 512 bytes into buffer
        BYTE buffer[512];
        // read 512 bytes into buffer
        const size_t l = fread(&buffer, 512, 1, infile);
        if (l != 1)
        {
            eof = true;
            fclose(img);
            fclose(infile);
            break;
        }

        if (isBeginning(buffer))
        {
            if (writingToImg)
            {
                fclose(img);
                imageNumber++;
            }
            char filename[8];
            // generates filename
            sprintf(filename, "%03i.jpg", imageNumber);
            img = fopen(filename, "w");
            fwrite(&buffer, 512, 1, img);
            writingToImg = true;
        }
        else
        {
            if (writingToImg)
            {
                fwrite(&buffer, 512, 1, img);
            }
        };
    }
    return 0;
}
