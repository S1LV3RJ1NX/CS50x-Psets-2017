#include<cs50.h>
#include<stdio.h>
#include<math.h>
float GetPositiveFloat();

int main(void)
{
    int quaters = 25, dimes = 10, nickels = 5, pennies = 1,counter = 0;
    printf("O hai! "); 
    
    //roundup
    int in_cents = roundf((GetPositiveFloat()*100)) ;
    
    while(in_cents>= quaters)
    {
        in_cents -= quaters;
        counter++;
        
    }
   
   while(in_cents>= dimes)
   {
        in_cents -= dimes;
        counter++;
    }
    
    while(in_cents>= nickels)
    {
        in_cents -= nickels;
        counter++;
    }
    
    while(in_cents>=pennies)
    {
        in_cents -= pennies;
        counter++;
    }
    
    printf("%d\n",counter);
    
}

float GetPositiveFloat(void)
{
    float n;
    do
    {
        printf("How much change is owed?\n");
        n = GetFloat();
    }while(n<0);
    
   return n;
}