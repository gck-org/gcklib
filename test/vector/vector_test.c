#include <stdio.h>

#include "../../lib/vector.h"

int test;

int main(int argc, char **argv)
{
	if (argc < 2) {
		test = 42;
	} else {
		test = atoi(argv[1]);
	}

	vec_t v = vec_init(sizeof(int));

	vec_append(&v, &test);
	vec_append(&v, &test);
	vec_append(&v, &test);
	vec_append(&v, &test);

	printf("[");
	for (int i = 0; i < v.len; ++i)
		printf(" %d", *(int *)vec_get(&v, i));
	printf(" ]\n");

	vec_free(&v);
	puts("all vector passed");
	return 0;
}
