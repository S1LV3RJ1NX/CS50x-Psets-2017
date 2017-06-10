/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize scale infile outfile\n");
        return 1;
    }
    
    //remember scale
    int scale = atoi(argv[1]);
    
    // ensure n is is a positive int less than or equal to 100
    if(scale > 100 || scale < 1)
    {
        printf("Scale must be a positive int less than or equal to 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // create variables for new width and height
    int newWidth = bi.biWidth;
    int newHeight = bi.biHeight;
   
    // update width and height
    bi.biWidth *= scale;
    bi.biHeight *= scale;
    
    // determine padding for scanlines
    int newPadding = (4 - (newWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // update image size
    bi.biSizeImage = abs(bi.biHeight) * ((bi.biWidth * sizeof (RGBTRIPLE)) + padding);
    
    // update file size
    bf.bfSize = bi.biSizeImage + sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER); 
    
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // allocate storage for buffer to hold scanline
    RGBTRIPLE *buffer = malloc(sizeof(RGBTRIPLE) * (bi.biWidth));

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(newHeight); i < biHeight; i++)
    {
        int rowtrac = 0;
        // iterate over pixels in scanline
        for (int j = 0; j < newWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write pixel to buffer n times
            for(int count = 0; count < scale; count++)
            {
                *(buffer+(rowtrac)) = triple;
                rowtrac++;
            }
            
        }

        // skip over padding, if any
        fseek(inptr, newPadding, SEEK_CUR);
        
        // write RGB triple to outfile
        for (int k = 0; k < scale; k++)
        {
            fwrite((buffer), sizeof(RGBTRIPLE), bi.biWidth, outptr);
            
            // write padding to outfile
                for (int l = 0; l < padding; l++)
                    fputc(0x00, outptr);
        }
      
    }

    // free memory from buffer
    free(buffer);
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
