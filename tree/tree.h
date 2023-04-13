#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TREE_H
#define TREE_H


typedef struct node {
	char data;
	struct node *left;
	struct node *right;
} node_t;

typedef struct tree {
	node_t *root;
} tree_t;

tree_t *create_tree(void);
node_t *create_node(char data);
void delete_node(node_t *node_ptr);
void delete_tree(tree_t *tree_ptr);
void print_node(node_t *node_ptr);
void print_tree(tree_t *tree_ptr);
void delete_node_value(tree_t *tree_ptr, char data);
void show_node(node_t *node_ptr);
node_t *find_node(tree_t *tree_ptr, char data);
void delete_node_value(tree_t *tree_ptr, char data);
void add_data2tree(tree_t *tree_ptr, char data);

#endif

