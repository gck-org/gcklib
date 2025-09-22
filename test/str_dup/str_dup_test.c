#include <stdio.h>
#include <string.h>

#include "../../lib/str_dup.h"

char *test_src = "Hello, World!";

int main(int argc, char **argv)
{
	char *test_dest;

	test_dest = str_dup(test_src);

	if (!strcmp(test_src, test_dest)) {
		puts("all str_dup tests passed");
	} else {
		printf("got %s\n", test_dest);
	}
	return 0;
}
