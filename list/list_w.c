#include "list_w.h"

node_t *create_node(char *word, int length) {
	node_t *node_ptr = malloc(sizeof(*node_ptr));
	if (node_ptr == NULL) {
		fprintf(stderr, "Error: memory not allocated\n");
		return NULL;
	}
	node_ptr->word = malloc((length + 1) * sizeof(char));
	if (node_ptr->word == NULL) {
		fprintf(stderr, "Error: memory not allocated by word\n");
		free(node_ptr);
		return NULL;
	}
	memcpy(node_ptr->word, word, length);
	node_ptr->word[length] = '\0';
	node_ptr->length = length;
	node_ptr->next = NULL;

	return node_ptr;
};

void delete_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		free(node_ptr);
	}
}

/*
void print_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		printf("%s", node_ptr->word);
	}
}
*/

list_t *create_list(char *word, int length)
{
	list_t *list_ptr = malloc(sizeof(*list_ptr));

	if (list_ptr == NULL) {
		return NULL;
	}
	list_ptr->head = create_node(word, length);
	if (list_ptr->head == NULL) {
		free(list_ptr);
		return NULL;
	}

	return list_ptr;
}

void delete_list(list_t *list_ptr)
{
	if (list_ptr == NULL) {
		return;
	}
	node_t *node_ptr = list_ptr->head;
	while (node_ptr != NULL) {
		node_t *tmp = node_ptr->next;
		delete_node(node_ptr);
		node_ptr = tmp;
	}
	free(list_ptr);
}

void print_list(list_t *list_ptr)
{
	if (list_ptr == NULL) {
		fprintf(stderr, "Error: invalid a pointer to list\n");
		exit(EXIT_FAILURE);
	}
	node_t *node_ptr = list_ptr->head;
	while (node_ptr != NULL) {
		printf("%s ", node_ptr->word);
		node_ptr = node_ptr->next;
	} 
	printf("\n");
}
char add_word2list(list_t *list_ptr, char *word, int length)
{
	if (list_ptr == NULL) {
		fprintf(stderr, "Error: list pointer is null\n");
		return 0;
	}
	node_t *node_ptr = create_node(word, length);
	if (node_ptr == NULL) {
		fprintf(stderr, "Error: unable ot create new node\n");
		return 0;
	}
	if (list_ptr->head == NULL) {
		list_ptr->head = node_ptr;
	}
	node_t *tail = list_ptr->head; 

	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = node_ptr;
	return 1;
}

void sort_word_list(list_t *list_ptr) 
{
	if (list_ptr == NULL || list_ptr->head == NULL) {
		return;
	}

	int sorted = 0;
	node_t *current_node, *next_node, *temp_node;

	while (!sorted) {
		sorted = 1;
		current_node = list_ptr->head;
		next_node = current_node->next;
		temp_node = NULL;
		while (next_node != NULL) {
			if (strlen(current_node->word) > strlen(next_node->word)) {
				current_node->next = next_node->next;
				next_node->next = current_node;
				
				if (temp_node == NULL) {
                                	list_ptr->head = next_node;
				} else {
					temp_node->next = next_node;

				}
				temp_node = next_node;
				next_node = current_node->next;
				sorted = 0;
			} else {
				temp_node = current_node;
				current_node = next_node;
				next_node = next_node->next;
			}
		}
	}
}

void max_word_list(list_t *list_ptr)
{                                                                               
	node_t *current = list_ptr->head;
	node_t *max_node = current;
	if (current == NULL) {
		return;
	}

	while (current != NULL) {
		if (current->length > max_node->length) {
			max_node = current;
		}
		current = current->next;
	}
	printf("max node = %s;\n", max_node->word);
}
