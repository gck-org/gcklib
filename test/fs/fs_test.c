#include "../../lib/fs.h"

int main(int argc, char **argv)
{
	if (argc < 2) {
		return 1;
	}

	fs_new(argv[1]);
	fs_write(argv[1], "Hi!\n");

	return 0;
}
