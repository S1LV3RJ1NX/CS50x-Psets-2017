/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

//using a trie DS
typedef struct trie
{
    bool isword;
    struct trie* children[27];
}
trie;

trie *firstnode;

// total number of words counter
int numberOfWords = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // mapping int values
    int a_int = (int)'a';
    int z_int = (int)'z';
    
    //point current node towards root node
    trie* currentnode = firstnode;
    
    //loop th' each letter in word
    int i = 0;
    while(word[i] != '\0')
    {
        char c = word[i];
        
        //if c is apostrophe
        if ( c == '\'')
            c = z_int + 1;
            
        //converting all alphabets to lowercase
        int childindex = tolower(c) - a_int;
        
        if (currentnode -> children[childindex] != NULL)
        {
            currentnode = currentnode -> children[childindex];
            i++;
        }
        else
            return false;
    }
            
    if (currentnode -> isword == true)
        return true;
    else
        return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // mapping int values
    int a_int = (int)'a';
    int z_int = (int)'z';
    
    // opening the dictionary file
    FILE* fp = fopen(dictionary,"r");
    
    //check if unable to open
    if (fp == NULL)
        return false;
        
    // mallocking memory for first node
    firstnode = (trie*) malloc(sizeof(trie));
    
    // integer for current position in children array
    int current_pos = 0;
   
    // current node
    trie* currentnode = NULL;
    
    //looping th' dict until EOF
    while ( (current_pos = fgetc(fp)) != EOF )
    {
        //set firstnode equal to current node
        currentnode = firstnode;
        
        // iterating through word and adding each letter to children until "\n"
        for(; current_pos != '\n'; current_pos = fgetc(fp))
   		{
            if (current_pos == '\'')
                current_pos = z_int + 1;
                
            //create a node if charecter is not in trie
            if( currentnode -> children[current_pos - a_int] == NULL)
            {
                //malloc a new node
                currentnode -> children[current_pos - a_int] = (trie*)malloc(sizeof(trie));
                currentnode = currentnode -> children[current_pos - a_int];
            }
            //if present
            else
                currentnode = currentnode -> children[current_pos - a_int];
            
   		}
   		currentnode -> isword = true;
        numberOfWords++;
                        
    }
    // close the dictionary file
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{

    return numberOfWords;
}

// function to freenode
void freenode(trie* firstnode)
{
    for(int i = 0; i < 27; i++)
    {
        if (firstnode -> children[i] != NULL)
        {
            freenode(firstnode -> children[i]);
        }
    }
    free(firstnode);
    return;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    trie* currentnode = firstnode;
    freenode(currentnode);
    return true;
}
