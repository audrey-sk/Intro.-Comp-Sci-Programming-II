/* File name : InRectangle.c
*
* Description: Wite a function that determines whether a point lies inside a rectangle. The
* point and rectangle are both specified using arrays of floating point values. Use the multi source file model to create your solution
*
* Author : Parastoo Safikhani 
*
* June 18 2024
*/
#define POINTS 2
#define CORNERS 4

#include "InRectangle.h"
#include <math.h>

// Function to check if a point is inside a rectangle
int InRectangle(float pt[POINTS], float rect[CORNERS]) {
    // Initialize point coordinates
    float px = pt[0];
    float py = pt[1];
    
    // Initialize rectangle corners
    float x1 = rect[0];
    float y1 = rect[1];
    float x2 = rect[2];
    float y2 = rect[3];
    
    // Make it so that (x1, y1) is the bottom-left
    // and (x2, y2) is the top-right corner
    float left = fmin(x1, x2);
    float right = fmax(x1, x2);
    float bottom = fmin(y1, y2);
    float top = fmax(y1, y2);
    
    // Check if the point is within the rectangle bounds
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return 1; // Point is inside the rectangle
    } else {
        return 0; // Point is outside the rectangle
    }
}

