/* 
 * dataStructure.c
 *
 * Provides a bound-checked data structure made of an array of integers
 * in which duplicated elements are allowed.
 *
 * The interface of this data structure includes several utility 
 * functions that operate on this array of integers as well as 
 * file i/o functions: saving into and loading from json files. 
 * 
 * Do not change the dataStructure.h file.
 *
 * Author: RV + AL 
 * Modified Date: July 2024 
*/

#include <stdlib.h> // for malloc() and for rand()
#include <stdio.h>  // for file i/o calls
#include <time.h>   // for time()
#include <string.h> // for strlen()
 
#include "dataStructure.h"


/* 
 * Description: Creates a new intArray_t data structure 
 *              with initial array size "size".
 *              If successful (i.e. memory allocation succeeds), 
 *              returns a pointer to a newly-allocated intArray_t. 
 *              If unsuccessful, returns a NULL pointer.
 * Time Efficiency: O(1)
 */
intArray_t * intArray_create( unsigned int size ) {

  // Allocate memory on the heap for intArray_t struct 
  intArray_t * ia = malloc( sizeof( intArray_t ) );
  // proceed if successfully allocated 
  if (ia != NULL) {
    ia->size = size;
    ia->data = malloc(size * sizeof(int));
    if (ia->data == NULL) {
      free(ia);
      ia = NULL;
    } else {
      ia->elementCount = 0;
    }
  }
  return ia;
} 

/* 
 * Description: Frees all memory allocated for "ia".
 *              If the pointer "ia" is NULL, it does nothing. 
 *              If the pointer "ia->data" is NULL, it does not 
 *              attempt to free it. Returns INTARR_OK.
 * Time Efficiency: O(1)
 */ 
intArrayResult_t intArray_destroy( intArray_t * ia ) {

  // If heap memory has been allocated for intArray_t struct ...
  if ( ia != NULL ) {
  
    // If heap memory has been allocated for array ...
    if ( ia->data != NULL ) {
      // ... then free it
      free( ia->data );
      ia->data = NULL;
    }
  
    // ... then free it.
    free( ia );
    ia = NULL;
  }

  return INTARR_OK;
}

/* Description: Appends "newElement" and returns INTARR_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns INTARR_ERROR.
 *              If "ia" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_append( intArray_t * ia, int newElement ) {
	
  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_append(...) with the parameter newElement -> %d.\n", newElement );
  if (ia == NULL) {
        return INTARR_BADPARAM;
    }
    if (ia->elementCount >= ia->size) { //number of elements is more than the size 
        return INTARR_ERROR;
    }
    ia->data[ia->elementCount] = newElement; //put new element at the end
    ia->elementCount++; //new element added so increment element count 
	
  return INTARR_OK; // You are free to modify this return statement.
}
				
/* Description: Removes the element at "indexToBeRemoved" in the data structure
 *              and returns INTARR_OK. If the data structure was initially sorted,
 *              it does not remain sorted after removing the element at "indexToBeRemoved".
 *              If "ia" is NULL or "indexToBeRemoved" is out of bounds, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_remove( intArray_t * ia, unsigned int indexToBeRemoved ) {
	
  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_remove(...) with the parameter indexToBeRemoved -> %u.\n" , indexToBeRemoved );
  if (ia == NULL || indexToBeRemoved >= ia->elementCount) { //null or out of bound
        return INTARR_BADPARAM;
    }
    ia->data[indexToBeRemoved] = ia->data[ia->elementCount - 1]; //replace with the last element 
    ia->elementCount--; //one element removed 
	
  return INTARR_OK; // You are free to modify this return statement.
}

/* Description: Modifies (overwrites) the element at "index" with "newElement"
 *              and returns INTARR_OK. If "ia" is NULL or "index" is out of bounds,
 *              returns INTARR_BADPARAM.
 * Time Efficiency: O(1)
 */
intArrayResult_t intArray_modify( intArray_t * ia, int newElement, unsigned int index ) {
	
  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_modify(...) with the parameters newElement -> %d and index -> %u.\n" , newElement, index );
  if (ia == NULL || index >= ia->elementCount) { //null or index out of bounds 
        return INTARR_BADPARAM;
    }
    ia->data[index] = newElement; //replace whatever is at the wanted index with the target value 
	
  return INTARR_OK; // You are free to modify this return statement.
}
							
/* Description: Finds the first occurrence of "targetElement" in the data structure,
 *              sets "*index" to its index and returns INTARR_OK. If "targetElement" 
 *              does not occur in the data structure, leaves "*index" unmodified 
 *              and returns INTARR_NOTFOUND. If "ia" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(n)
 */
intArrayResult_t intArray_find( intArray_t * ia, int targetElement, unsigned int * index ) {
    
  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_find(...) with the parameter targetElement -> %d.\n" , targetElement );
  if (ia == NULL) { //ia is null, so theres nothing to find 
        return INTARR_BADPARAM;
    }
    for (unsigned int i = 0; i < ia->elementCount; i++) { //go through all indexed in the array 
        if (ia->data[i] == targetElement) { //if target was found in the array 
            *index = i; //store the index 
            return INTARR_OK;
        }
    } 
	
  return INTARR_NOTFOUND; // You are free to modify this return statement.
}

/* Description: Sorts the data structure by value in ascending sort order 
 *              (by smallest-to-largest), such that data[i] < data[i+1] for all valid i, 
 *              then returns INTARR_OK. If "ia" is NULL, returns INTARR_BADPARAM.
 *              Works in-place: content of "ia" is sorted on return. 
 *              Sorts the array using the Bubble Sort algorithm.
 * Time efficiency: O(n^2)
 * Space efficiency: O(1) - Bubble Sort is an "in-place" algorithm.
 */
intArrayResult_t intArray_sort( intArray_t * ia ) {
	
  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_sort(...).\n" );
  if (ia == NULL) {
        return INTARR_BADPARAM;
    }
    for (unsigned int i = 0; i < ia->elementCount - 1; i++) { //outer loop for bubble sort 
        for (unsigned int j = 0; j < ia->elementCount - i - 1; j++) {
            if (ia->data[j] > ia->data[j + 1]) { //chech if current element is greater than next element 
                int temp = ia->data[j]; //temporary value to hold current element 
                ia->data[j] = ia->data[j + 1]; //swap current element with next 
                ia->data[j + 1] = temp;
            }
        }
    } 
	
  return INTARR_OK;  // You are free to modify this return statement.
}
							
/* Description: Returns a duplicate copy of "ia", allocating new storage 
 *              for this duplicate data (we call this a "deep copy"). 
 *              If unsuccessful (i.e. memory allocation for the copy fails, 
 *              or "ia" is NULL), returns a NULL pointer. 
 */
intArray_t * intArray_copy( const intArray_t * ia ) {

  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_copy(...).\n" );
  if (ia == NULL) { //if its null then theres nothing to copy 
        return NULL;
    }
    intArray_t * copy = intArray_create(ia->size); //set pointer to have same size as ia
    if (copy == NULL) {
        return NULL;
    }
    copy->elementCount = ia->elementCount; //set them to have same number of elements 
    for (unsigned int i = 0; i < ia->elementCount; i++) { //iterate through ia 
        copy->data[i] = ia->data[i]; //put the value of each index in copy to corresponding index in ia
    }
  
  return copy; // You are free to modify this return statement.
}

/* Description: Prints each field (member) of the data structure "ia" and
 *              prints each element of its array field then returns INTARR_OK.
 * Time Efficiency: O(n)
 */
intArrayResult_t intArray_print( intArray_t * ia ) {
	
  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  if (ia == NULL) {
        return INTARR_BADPARAM; // nothing to print if ia is NULL
    }
  //print each field of ia (size,elementcount,data)
  printf("Size: %u\n", ia->size);
  printf("Element Count: %u\n", ia->elementCount);
  printf("Data: [");
  for (unsigned int i = 0; i < ia->elementCount; i++) { //iterate through array to print data 
    printf("%d", ia->data[i]); //to print a comma between elements but not after the last element 
    if (i < ia->elementCount - 1) {
      printf(", ");
    }
  }
  printf("]\n");

    return INTARR_OK; // Return INTARR_OK to indicate success
}

/* Description: Writes (saves) the entire array "ia" into a file 
 *              called "filename" in a JSON text file format (explained below)
 *              that can be loaded by the function intArray_load_from_json(...).
 *              Returns INTARR_OK on success, or INTARR_ERROR on failure. 
 *              Empty arrays (elementCount == 0) should produce an 
 *              output file containing an empty array.
 *              If "ia" is NULL or "filename" is NULL, returns INTARR_BADPARAM.
 *
 *              The JSON output should be human-readable.
 *
 * Example: The following lines are a valid JSON file content 
 *          produced by first saving "elemenCount" (3), then
 *          each of the 3 elements contained in the array
 *          (100, 200, 300) into a file:
 * [ 
 *  3,
 *  100, 
 *  200, 
 *  300 
 * ]
 */
intArrayResult_t intArray_write_to_json( intArray_t * ia, const char * filename ) {

  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_write_to_json(...) with the filename -> %s.\n", filename );
  if (ia == NULL || filename == NULL) {
        return INTARR_BADPARAM;
    }
    FILE * file = fopen(filename, "w"); //open file for writing 
    if (file == NULL) { //check if opened successfully 
        return INTARR_ERROR;
    }
    fprintf(file, "[\n  %u,\n", ia->elementCount); // write the opening bracket and element count in the file.
    for (unsigned int i = 0; i < ia->elementCount; i++) { //iterate through array 
        fprintf(file, "  %d", ia->data[i]); //write each element in the file 
        if (i < ia->elementCount - 1) {
            fprintf(file, ",\n");
        } else {
            fprintf(file, "\n");
        }
    }
    fprintf(file, "]\n"); //closing bracket 
    fclose(file); //close the file

  return INTARR_OK; // You are free to modify this return statement.
}


/* Description: Loads a new array from the file called "filename", that was
 *              previously saved using intArray_write_to_json(...). The file may 
 *              contain an empty array. Returns a pointer to a newly-allocated 
 *              data structure on success (even if the array is empty), 
 *              or NULL on failure.
 *              If "filename" is NULL, returns NULL.
 */
intArray_t * intArray_load_from_json( const char * filename ) {

  // Function Stub
  // This stub is to be removed when you have successfully implemented this function.
  printf( "Calling intArray_load_from_json(...) with the filename -> %s.\n", filename );
  if (filename == NULL) {
        return NULL;
    }
    FILE * file = fopen(filename, "r"); //open file for reading 
    if (file == NULL) { //check if file is null 
        return NULL;
    }
    unsigned int elementCount; //variable for element count 
    fscanf(file, "[ %u ,", &elementCount); //read elementcount from file 
    intArray_t * ia = intArray_create(elementCount);
    if (ia == NULL) {
        fclose(file); //close file
        return NULL;
    }
    ia->elementCount = elementCount;
    for (unsigned int i = 0; i < elementCount; i++) {
        fscanf(file, " %d ,", &ia->data[i]); //read element count from file 
    }
    fclose(file); //close file 

  return ia; // You are free to modify this return statement.
}
