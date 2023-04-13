#include "tree.h"

static node_t *get_successor(node_t *delete);

tree_t *create_tree()
{
	tree_t *tree_ptr = malloc(sizeof(*tree_ptr));
	if (tree_ptr != NULL) {
		tree_ptr->root = NULL;
	}
	return tree_ptr;
}

void print_node(node_t *node_ptr) 
{
	if (NULL == node_ptr) {
		return;
	}
	print_node(node_ptr->left);
	print_node(node_ptr->right);
	printf("%c\n", node_ptr->data);
}

void print_tree(tree_t *tree_ptr)
{
	node_t *item = tree_ptr->root;
	print_node(item);
}

void show_node(node_t *node_ptr)
{
	if (node_ptr == NULL) {
		return;
	}
	printf("data: %c;\n", node_ptr->data);
}

node_t *create_node(char data)
{
	node_t *node_ptr = malloc(sizeof(*node_ptr));
	if (node_ptr != NULL) {
		node_ptr->left = NULL;
		node_ptr->right = NULL;
		node_ptr->data = data;
	}
	return node_ptr;
}

void delete_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		delete_node(node_ptr->left);
		delete_node(node_ptr->right);
		free(node_ptr);
	}
}

void delete_tree(tree_t *tree_ptr)
{
	if (tree_ptr != NULL) {
		delete_node(tree_ptr->root);
		free(tree_ptr);
	}
}

void add_data2tree(tree_t *tree_ptr, char data)
{
	if (NULL == tree_ptr) {
		return;
	}
	node_t *node_ptr = create_node(data);
	if (NULL == node_ptr) {
		return;
	}

	if (NULL == tree_ptr->root) {
		tree_ptr->root = node_ptr;
	} else {
		node_t *current = tree_ptr->root;
		node_t *parent = NULL;
		while (1) {
			parent = current;
			if (data < current->data) {
				current = current->left;
				if (NULL == current) {
					parent->left = node_ptr;
					break;
				}
			} else {
				current = current->right;
				if (NULL == current) {
					parent->right = node_ptr;
					break;
				}
			}
		}
	}
}

node_t *find_node(tree_t *tree_ptr, char data)
{
	node_t *current_node = NULL;
	if (NULL != tree_ptr && NULL != tree_ptr->root) {
		current_node = tree_ptr->root;
		while (data != current_node->data) {
			current_node = (data < current_node->data)
				? current_node->left
				: current_node->right;
			if (NULL == current_node) {
				break;
			}
		}
	}
	return current_node;
}

void delete_node_value(tree_t *tree_ptr, char data) {
	if (NULL == tree_ptr || NULL == tree_ptr->root) {
		return;
	}

       	node_t *current = tree_ptr->root;
	node_t *parent = tree_ptr->root;

	while (data != current->data) {
		parent = current;
		if (data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}

		if (NULL == current) {
			return;
		}
	}

	if (NULL == current->left && NULL == current->right) {
		if (tree_ptr->root == current) {
			tree_ptr->root = NULL;
		} else if (parent->left == current) {
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}

	} else if (NULL == current->right) {
		if (tree_ptr->root == current) {
			tree_ptr->root = current->left;
		} else if (parent->left == current) {
			parent->left = current->left;
		} else {
			parent->right = current->left;
		}
	} else if (NULL == current->left) {
		if (tree_ptr->root == current) {
			tree_ptr->root = current->right;
		} else if (parent->right == current) {
			parent->right = current->right;
		} else {
			parent->left = current->right;
		}
	} else {
		node_t *successor = get_successor(current);
		if (tree_ptr->root == current) {
			tree_ptr->root = successor;
		} else if (parent->left == current) {
			parent->left = successor;
		} else {
			parent->right = successor;
		}
		current->left = NULL;
		current->right = NULL;
	}
	if (current != NULL) {
		free(current);
	}
}

node_t *get_successor(node_t *delete) {
	node_t *success_parent = delete;
	node_t *successor = delete;
	node_t *current = delete->right;

	while(NULL != current) {
		success_parent = successor;
		successor = current;
		current = current->left;
	}
	if (successor != delete->right) {
		success_parent->right = successor->right;
		successor->right = delete->right;
	}

	successor->left = delete->left;
	return successor;
}
