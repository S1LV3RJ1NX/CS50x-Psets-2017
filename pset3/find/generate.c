/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if argument count isn't 2 or 3 display the usage of the program
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // convert the first argument to int which is a string.
    int n = atoi(argv[1]);

    // If there are 3 arguments convert the 3rd argrument(srand)to int else let srand be current time
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    
    {
        srand48((long) time(NULL));
    }

    // print n no of random numbers
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
