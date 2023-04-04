#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

typedef struct circle {
	point_t *o;
	int radius;
} circle_t;

circle_t *create_circle(int x, int y, int radius);
circle_t *new_point_circle(point_t *center, int radius);
void delete_circle(circle_t *circle_ptr);
void print_circle(circle_t *circle_ptr);

#endif
