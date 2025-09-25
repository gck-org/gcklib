#include <stdio.h>

#include "../../lib/err.h"

#include "../../lib/conf.h"

int main(int argc, char **argv)
{
	if (argc < 2 || !argv[1]) {
		fatalf("not enough arguments");
	}

	struct config cfg;
	conf_parse(argv[1], &cfg);

	puts(conf_get(&cfg, "foo"));
	puts(conf_get(&cfg, "answer"));

	puts("all conf passed");
	return 0;
}
