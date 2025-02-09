/*Filename: verticalHistogram.c
* Description: Write a C program that reads integer values from stdin, separated by one or more spaces or 
* newlines, until reaching EOF. On standard output (stdout), it renders a simple vertical column graph representation of the 
* input values (i.e., a vertical histogram), in order left to right, using hash '#' characters.
*
* Author : Parastoo Safikhani
* June 4 2024 */

#include <stdio.h>
#define MAXVALUES 80

int main(void) {
    int values[MAXVALUES];
    int i = 0;
    int maxvalue = 0;

    // Find max value (rows)
    while (i < MAXVALUES && scanf("%d", &values[i]) == 1) {
        if (values[i] > maxvalue) {
            maxvalue = values[i];
        }
        i++;
    }

    // Iterate through the rows
    for (int j = maxvalue; j > 0; j--) {
    // iterate throuh columns 
        for (int k = 0; k < i; k++) {
            if (values[k] >= j) { //print # if the number fills that cell
                printf("# ");
            } else {
                printf("  ");  // print space if that cell is empty
            }
        }
        printf("\n");
    }

    return 0;
    
}

    