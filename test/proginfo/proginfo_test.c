#include <stdio.h>

#include "../../lib/proginfo.h"

void usage(int status);
void version();

int main(int argc, char **argv)
{
	set_prog_name(argv[0]);

	parse_standard_options(argc, argv, usage, version);

	puts("all proginfo passed");
	return 0;
}

void usage(int status)
{
	emit_try_help();
}

void version()
{
	emit_version();
}
