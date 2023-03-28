#include "list_w.h"

int main(int argc, char **argv)
{
	if (argc < 2 ) {
		fprintf(stderr, "Error: Usage ./program word1 word2..\n");
		exit(EXIT_FAILURE);
	}

	/*
	char *tmp_word = NULL;
	for (int i = 2; i < argc; ++i) {
		//strncpy(tmp_word, argv[i], strlen(argv[i]));
		if ((tmp_word[i] >= '!' && tmp_word[i] <= '/') 
				|| (tmp_word[i] >= ':' && tmp_word[i] <= '@')) {
			fprintf(stderr, "Error: enter only words\n");
			exit(EXIT_FAILURE);
		}
	}
	*/
	list_t *list_ptr = create_list(argv[1], strlen(argv[1]));
	for (int i = 2; i < argc; ++i) {
		add_word2list(list_ptr, argv[i], strlen(argv[i]));
	}
	sort_word_list(list_ptr);
	print_list(list_ptr);
	max_word_list(list_ptr);
	delete_list(list_ptr);
	return 0;
}
