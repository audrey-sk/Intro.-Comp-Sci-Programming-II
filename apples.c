/*
 * File name: apples.c
 *
 * Description: Write a program that predicts how many whole bags of apples can be produced given the 
 * number of apples available
 *
 * Author: Parastoo Safikhani 
 * Date: May 21 2024
 */

#include <stdio.h>

int main( void ) {
// Initialize ariavbles for apples, apples that fit in a bag, number of produced bags and leftover
  int apples = 0;
  int bags = 0;
  int bagsproduced = 0;
  int leftovers = 0;

// Prompt user for input
  printf("Please, enter the number of apples available and the number of apples each bag holds: ");

// create a loop to continue until user enters CTRL+D 
  while(scanf("%d %d", &apples , &bags)!=EOF){  

// Echo what the user has just entered
    printf("Number of apples available => %d, number of apples each bag holds => %d\n", apples, bags);

// Calculate number of produced bags
    bagsproduced = apples / bags;

// Use modulo to calculate leftovers
    leftovers= apples % bags;

// Print results and ask again 
    printf("Number of bags produced => %d, number of apples left over => %d\n", bagsproduced , leftovers);
    printf("Please, enter the number of apples available and the number of apples each bag holds: ");
    }
// Print done when user enters CTRL+D
  printf("\n Done.\n");
return 0;
}

