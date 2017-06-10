#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    string message; 
    
    //Validate commandline argument
    if (argc != 2)
    {
        printf("Only two command line argument are allowed\n ");
        printf("Re-run the program with Interger as agrument\n");
        return 1;
    } 
        
    string keyword = argv[1];
    
    //To check if the input keyword consists of only alphabets
    for (int i = 0, j = strlen(keyword); i<j; i++)
        if(!isalpha(keyword[i]))
        {
            printf("Cannot implement vigenare only alphabets required\n");
             return 1;
        }
     
        
    //to force the user to enter atleast a single character;
    do
    {
        printf("plaintext: ");
        message = GetString();
    }while(strlen(message) == 0);
    
    int keylength = strlen(keyword);
    int keycode[keylength]; //Creating an array of length of keyword
    
    //convet Aa--Zz to 0--26 without considering the case
    for(int j = 0; j < keylength; j++)
    {
        keycode[j] = toupper(keyword[j]) - 65;
    }
    
    printf("ciphertext: ");
    
    //To loop through the entire inputed message at the same time assign it the keycode and wrap it around the message
    for (int i = 0, j = 0, n = strlen(message); i < n; i++)
    {  
         
        if(isalpha(message[i]))
        {
       
            // Work with lower case characters
            if(islower(message[i]))
            {
                //keycode[(j % keylength) to get required index of key
                printf("%c",  (((message[i] - 97 ) + keycode[(j % keylength)]) % 26 ) + 97  ); 
                // increment j only if it is a character
                j++;
            }
             
            // Work with upper case characters
            else if(isupper(message[i]))
            {
                printf("%c",  (((message[i] - 65) + keycode[j % keylength]) % 26 ) + 65 );
                j++;
            }  
                 
        }
        else
            //display remaining type of characters
            printf("%c", message[i]);

    }
            
            printf("\n");
}