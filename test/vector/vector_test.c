#include <stdio.h>

#include "../../lib/vector.h"

int main(int argc, char **argv)
{
	vec_t v = vec_init(sizeof(int));

	vec_append(&v, 12);

	vec_free(&v);
	puts("all vector passed");
	return 0;
}
