/*
 * File name: values.c
 *
 * Description: Write a C program that reads a floating point value from stdin, then outputs:
 * 1. The smallest integer larger than or equal to its value.
 * 2. The nearest integer to this value, with halfway values rounded away from zero.
 * 3. The largest integer smaller than or equal to this value
 *
 * Author: Parastoo Safikhani 
 * Date: May 21 2024
 */

#include <stdio.h>
#include <math.h>

int main(void){

//initialize user input to zero  
    float userinput = 0.0;

//get float number from user
     printf("Please, enter a floating point value: ");

//read the floating point value
     scanf("%f", &userinput);

//calculate the smallest integer larger than or equal to userinput
     int larger = ceil(userinput);

//calculate the nearest integer to userinput 
     int near = round(userinput);

//calculate the largest integer smaller than or equal to userinput
     int smaller = floor(userinput);

//print results in respective lines
     printf("The smallest integer larger than or equal to %f is %d.\n",userinput,larger);
     printf("The nearest integer to %f is %d.\n", userinput, near);
     printf("The largest integer smaller than or equal to %f is %d.\n",userinput,smaller); 

//return
     return 0;
}
