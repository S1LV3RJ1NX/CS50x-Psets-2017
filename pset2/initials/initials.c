#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    
    string s = GetString();
    //to print an upper case char 
    printf("%c", toupper(s[0]));
    
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
        // print next character as an uppercase char after space
            printf("%c", toupper(s[i + 1]));
        }
    }
    
    printf("\n");
}