#include<cs50.h>
#include<stdio.h>

int GetPositiveInt();
int main(void)
{
    int m = GetPositiveInt();
    printf("bottles: %d\n", m*12);
}

//Self explanatory though :)
int GetPositiveInt(void)
{
    int n;
    do
    {
        printf("Miniutes: ");
        n = GetInt();
    }while(n<0);
    
   return n;
}