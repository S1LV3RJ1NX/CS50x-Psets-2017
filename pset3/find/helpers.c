/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

//declaring of searching and sorting algorithms

bool binary_search(int value, int values[], int n);

void selection_sort(int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm having O(logn)
    if (value<0)
        return false; // if value is negative stop.
    else 
        return binary_search(value, values, n);
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm having O(n^2)
    selection_sort(values, n);
    return;
}

bool binary_search(int value, int values[], int n)
{
    int start = 0; 
    int end = n-1;
    
    while(end>=start)
    {
        int middle = (start + end) /2;
        
        if (values[middle] == value)  //if middle value is the value desired return true
            return true;
        else if (values[middle] > value)
            end = middle - 1;
        else
            start = middle + 1;
    }
    
    return false;
}

void selection_sort(int values[], int n)
{
    int temp;
    
    for(int i = 0; i<n; i++)
    {
        int lowest_value = i;
        for(int j = i+1; j<n; j++)
        {
            if(values[lowest_value]>values[j])
                lowest_value = j;
        }
        
        //Swapping with the lowest value
        
        temp = values[lowest_value];
        values[lowest_value] = values[i];
        values[i] = temp;
    }
}
