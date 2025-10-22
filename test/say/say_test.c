#include <stdio.h>

#include "../../lib/say.h"

int main(int argc, char **argv)
{
	say("this is an example message\n");

	char *test;
	asprintf(&test, "hello - %s", "what is up");
	printf("%s\n", test);

	alert();

	puts("all say passed");
	return 0;
}
