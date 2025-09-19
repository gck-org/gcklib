#include "../../lib/fs.h"

const char *file, *expected = "write\nappend";
int exit_status;

int main(int argc, char **argv)
{	
	if (argc < 2) {
		file = "test";
	} else {
		file = argv[1];
	}

	fs_new(file);
	fs_write(file, "write\n");
	fs_append(ffile, "append");

	if (!strcmp(fs_read(file), expected)) {
		puts("K");
		exit_status = 0;
	} else {
		puts("F");
		exit_status = 1;
	}

	if (fs_exists(file)) puts("K");
	
	fs_del(file);

	if (!fs_exists(file)) puts("K");

	return exit_status;
}
