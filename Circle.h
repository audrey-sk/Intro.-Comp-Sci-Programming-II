#ifndef CIRCLE_H
#define CIRCLE_H

// Define the circle_t data type
typedef struct {
    int x;         // x coordinate of the circle's centre
    int y;         // y coordinate of the circle's centre
    double radius; // radius of the circle
} circle_t;

// Function declarations
circle_t *circle_create();
void circle_initialize(circle_t *circleptr, int x, int y, double radius);
void circle_move(circle_t *circleptr, int horiz, int vert);
void circle_setRadius(circle_t *circleptr, double radius);
float circle_computeArea(circle_t *circleptr);
void circle_print(circle_t *circle);

#endif // CIRCLE_H
