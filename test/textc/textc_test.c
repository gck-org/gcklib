#include <stdio.h>
#include <string.h>

#include "../../lib/textc.h"
#include "../../lib/err.h"

char *s_target = "Hello, World!";
char *upper_target = "HELLO, WORLD!";
char *lower_target = "hello, world!";

int main(int argc, char **argv)
{
	int lose;

	char *s = str_dup(s_target);
	char *upper = tostrupr(s);
	char *lower = tostrlwr(s);

	if (strcmp(s_target, s)) {
		errorf("failed to duplicate string: %s", s);
		lose = 1;
	}
	if (strcmp(upper_target, upper)) {
		errorf("failed to uppercase string: %s", upper);
		lose = 1;
	}
	if (strcmp(lower_target, lower)) {
		errorf("failed to lowercase string: %s", lower);
		lose = 1;
	}

	if (!lose) {
		puts("all textc passed");
	}
	return 0;
}
