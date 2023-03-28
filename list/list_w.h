#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef  STRUCT_H
#define  STRUCT_H
typedef struct node {
	int length;
	char *word;
	struct node *next;

} node_t;

typedef struct single_list {
	node_t *head;
} list_t;

node_t *create_node(char *word, int length);
void delete_node(node_t *node_ptr); 
//void print_node(node_t *node_ptr);

list_t *create_list(char *word, int length);
void print_list(list_t *list_ptr);
void delete_list(list_t *list_ptr);
char add_word2list(list_t *list_ptr, char *word, int length);
void sort_word_list(list_t *list_ptr);
void max_word_list(list_t *list_ptr);
#endif
