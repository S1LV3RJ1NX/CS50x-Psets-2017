#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
   
    //validate the argument
    if (argc != 2)
    {
            
        printf("Only two command line argument are allowed\n ");
        printf("Re-run the program with Interger as agrument\n");
        return 1;
    } 
       
   //to convert string in to an int type
    int key = atoi(argv[1]);
         
        
    printf("plaintext: ");
    string message = GetString();
             
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(message); i < n; i++)
    {  
        if(isalpha(message[i]))
        {
            // Work with lower case characters
            if(islower(message[i]))
                printf("%c",  (((message[i] + key) - 97) % 26 ) + 97  );
             
            // Work with upper case characters
            else if(isupper(message[i]))
                printf("%c",  (((message[i] + key) - 65) %26 ) + 65 );
        }
        else
        //display remaining type of characters
            printf("%c", message[i]);
    }
        printf("\n");
    
}    
