#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
     // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover name_of_img\n");
        return 1;
    }
    
    char *img = argv[1];
    
    // open the file 
    FILE* file = fopen(img, "r");
    if (file == NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not open %s.\n", img);
        return 2;
    }

    // counter to keep track of images
    int counter = 0; 
   
    //a buffer of 512 bytes
    BYTE buffer[512];
   
    //to give 3digit decimal no to jpgs from 000 to ...
    char fname[10]; 
   
    // temp file output
    FILE* temp = NULL; 
    
    //until EOF
     while (!feof(file))
    {
       
        // check first couple of sequence of the jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // close previously opened file
            if (temp != NULL)
            {
                fclose(temp);
                
            }
            
            // label the files with three digits
            sprintf(fname, "%03d.jpg", counter);
            
            // open the output file pointer and make sure it's not NULL
            if ((temp = fopen(fname, "w")) == NULL)
            {
                printf("Could not write image.\n");
                return 1;
            }
            
            // increment the counter
            counter++;
            
            // new file with buffer
            fwrite(buffer, sizeof(buffer), 1, temp);
                
        }
        //if outfile is open write the blocks to file
        else if (temp != NULL)
        {
            //put jpg in to temp
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        
        //read one byte at a time
        fread(buffer, sizeof(buffer), 1, file);
    }        
        
    // close the file
    fclose(file);

    // success
    return 0;
}   
    