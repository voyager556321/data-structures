#include "point.h"
point_t *create_point(int x, int y)
{
	point_t *new_point = malloc(sizeof(*new_point));
	if (new_point != NULL) {
		new_point->x = x;
		new_point->y = y;
	}
	return new_point;
}

void print_point(point_t *point_ptr)
{
	if (point_ptr == NULL) {
		fprintf(stderr, "Error: incorrect object\n");
		exit(EXIT_FAILURE);
	}
	printf("O(%d, %d), ", point_ptr->x, point_ptr->y);
}

void delete_point(point_t *point_ptr)
{
	if (point_ptr != NULL) {
		free(point_ptr);
	}
}
