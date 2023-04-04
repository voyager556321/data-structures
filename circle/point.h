#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef POINT_H
#define POINT_H

typedef struct point {
	int x;
	int y;
} point_t;

point_t *create_point(int x, int y);
void print_point(point_t *point_ptr);
void delete_point(point_t *point_ptr);

#endif
