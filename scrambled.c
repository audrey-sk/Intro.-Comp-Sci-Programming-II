/*Filename: scrambled.c
*
* Description: Create a new file called scrambled.c, containing a single function that matches this declaration: 
* unsigned int scrambled( int arr1[], int arr2[], unsigned int size ); 
* Arrays arr1 and arr2 are both of length size, and contain only values in the range [0 .. 99] 
*
* Author : Parastoo Safikhani
*
* June 4 2024
*/
#include <stdio.h>


unsigned int scrambled(int arr1[], int arr2[], unsigned int size) {
     
    int count[100];

    // set all values of array to zero 
    for(unsigned int i = 0; i < 100; i++){
        count[i]=0;
    }

    // count the occurrences of each value in arr1
    for (unsigned int i = 0; i < size; i++) {
        count[arr1[i]]++;
    }

    // check if arr2 has the same values as arr1
    for (unsigned int i = 0; i < size; i++) {
     
        count[arr2[i]]--; // reset the count for this value
    }
    for (unsigned int i=0; i<100 ; i++){ 
       if (count[i]!=0) {
            return 0; // arr2 has a value that is not in arr1
        }   
    }

    return 1; // arr2 has the same values as arr1
}