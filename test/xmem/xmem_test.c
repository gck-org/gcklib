#include <stdio.h>

#include "../../lib/xmem.h"

int main(int argc, char **argv)
{
	void *test1 = xmalloc(1024);
	void *test2 = xrealloc(test1, 2048);

	int n = 5;
	int *arr = xcalloc(n, sizeof(int));

	free(arr);

	puts("all xmem passed");
	return 0;
}
