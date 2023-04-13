#include "tree.h"

int main(void)
{
	tree_t *tree_ptr = create_tree();

        add_data2tree(tree_ptr, 'a'); //97
        add_data2tree(tree_ptr, 'q'); //113
        add_data2tree(tree_ptr, 'b'); //98
        add_data2tree(tree_ptr, 'o'); //111
        add_data2tree(tree_ptr, 'p'); //112
        add_data2tree(tree_ptr, 'c'); //99
        add_data2tree(tree_ptr, 'n'); //110
        add_data2tree(tree_ptr, 'x'); //120
        add_data2tree(tree_ptr, 'z'); //122
        add_data2tree(tree_ptr, 'm'); //109
        print_tree(tree_ptr);
	printf("\n");

	delete_node_value(tree_ptr, 'a'); //97

	node_t *find_val = find_node(tree_ptr, 'k');//99
	if (find_val != NULL) { 
		show_node(find_val);
	} else {
		printf("node was't found\n");
	}
        print_tree(tree_ptr);
        delete_tree(tree_ptr);

	return 0;
}
