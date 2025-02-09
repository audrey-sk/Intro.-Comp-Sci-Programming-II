/* File name : counting.c
*
* Description: Write a C program that counts the number of characters, words and lines read from
* standard input until EOF is reached
*
* Author : Parastoo Safikhani 
*
* June 18 2024
*/
#include <stdio.h>
#include <stdbool.h>

// main part of program
int main(void){
// initialize variables
    unsigned long charCount=0;   
    unsigned long wordCount=0;
    unsigned long lineCount=0;
    bool isword = false; //bool variavble to check for words
    int current; //current position in the file
    int apostrophe = 39; //value of apostrophe
    char lastchar=(char)current; // the last character
    //go through the file until user enters EOF
    while( (current=getchar()) !=EOF){
        charCount++;  //increment characters for every value except EOF
        if (current == '\n'){ //increment lines when we reach a new line
            lineCount++;
        }
    
    // check ASCII values and apostrophe to determine the number of words
        if( !((current >= 'a' && current <= 'z')|| (current >= 'A' && current <= 'Z') || (current == apostrophe)) ){
            //We have that our current is not a word character
            if (!isword) {
                wordCount++;
                isword = true;
            }
        }else{ 
            isword= false;
            }      
    }
   // print the results
    printf("%lu %lu %lu \n", charCount, wordCount, lineCount);
    
    return 0;
} 


