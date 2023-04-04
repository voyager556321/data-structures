#include "circle.h"
circle_t *create_circle(int x, int y, int radius)
{
	circle_t *new_circle = malloc(sizeof(*new_circle));
	if (new_circle != NULL) {
		new_circle->o = create_point(x, y);
		new_circle->radius = radius;
	}
	return new_circle;
}

circle_t *new_point_circle(point_t *center, int radius) 
{
	return center == NULL
		? NULL
		: create_circle(center->x, center->y, radius);
}

void delete_circle(circle_t *circle_ptr)
{
	if (circle_ptr != NULL) {
		delete_point(circle_ptr->o);
		free(circle_ptr);
	}
}

void print_circle(circle_t *circle_ptr)
{
	if (circle_ptr == NULL) {
		return;
	}
	print_point(circle_ptr->o);
	printf("R = %d", circle_ptr->radius);
}
