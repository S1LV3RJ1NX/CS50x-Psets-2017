#include<cs50.h>
#include<stdio.h>

int GetPositiveInt();
int main(void)
{
  int row, space, hash; 
  
  int height =GetPositiveInt();
  
  // Loop to print marios pyramid
  for(row = 1 ;row <= height; row++ )
  {
      
    //Loop to print the spaces
    for(space=(height - row); space > 0; space--)
    {
      printf(" ");
    }
      
    //Loop to print the hashes
    for(hash = 1; hash <= (row+1); hash++)
    {
      printf("#");
    }
      
    printf("\n");
  }
  

 
}

//To get positive input from the user
int GetPositiveInt(void){
    int n;
    do
    {
        printf("Height: ");
        n = GetInt();
    }while(n<0 || n>23);
    
   return n;
}
