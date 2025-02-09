#include <stdio.h>
#include <stdlib.h> 
#include "Circle.h" 

circle_t * circle_create(){
    circle_t * circleptr = malloc (sizeof(circle_t));
    if (circleptr != NULL){ 
        circleptr -> x = 0;
        circleptr -> y = 0;
        circleptr -> radius = 0.0;
    }else{
        printf("memory allocation failed");
        return NULL; 
    }
    return circleptr; 
}
void circle_initialize( circle_t * circleptr, int x , int y, double radius){
    if (radius <= 0.0)
        printf(" bad parameter");
    circleptr -> x = x;
    circleptr -> y = y;
    circleptr -> radius = radius;  
    return;  
}
void circle_setRadius (circle_t * circleptr, double radius){
    if (radius <= 0.0)
        circleptr -> radius = 10.0; 
    else{
        circleptr -> radius = radius; 
    }
    return;
} 
void circle_move (circle_t * circleptr ,  int horiz, int vert ){
    circleptr -> x += horiz;
    circleptr -> y += vert;
    return; 
}
float circle_computeArea(circle_t * circleptr){
    float pi = 3.14;
    float area = (circleptr-> radius * circleptr-> radius) * pi;
    return area;
}
void circle_destroy ( circle_t * circleptr){
    free(circleptr);
    return;
}
void circle_print(circle_t * circleptr){
    printf(" circle centered at (%d , %d) with radius of %.1f \n", circleptr->x , circleptr->y , circleptr-> radius);
    return; 
}