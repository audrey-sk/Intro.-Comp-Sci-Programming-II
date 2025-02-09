/* Filename : reverse.c
* Description : Write a C program that reverses the contents of an array in-place, such that, once 
* reversed, the array contains the same values as before, but in the reverse order.
*
* Author : Parastoo Safikhani
*
* Date : May 28 2024
*/
#include <stdio.h>
int main (void){
// define array
const int size=10;
int numbers[size];
int i =0;

// prompt user
    printf("Please, enter 10 integers then press Enter: "); 

// go through each number and read it 
for ( int i=0 ; i<10 ; i++ ) { 
// store user input in array 
    scanf("%d", &numbers[i]); 
}
// echo user input 
printf("Content of array before reversing: ");
for ( int i=0 ; i<10 ; i++ ) { 
    printf("%d ", numbers[i]);
}

// reverse array
int start=0;
int end=size-1;
    while(start < end ) {
        // Swap the elements at start and end
        int temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
        start++;
        end--;
    }

// print reverse array 
printf("\nContent of array after reversing: ");
for ( int i=0 ; i<10 ; i++ ) { 
    printf("%d ", numbers[i]); 
}


 return 0; 
}